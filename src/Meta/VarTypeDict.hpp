#pragma once
#include "../Headers.hpp"
#include "AuxiliaryTypes/vtdtools.hpp"

__ALG__META__BEGIN__

template <typename... TParams>
struct VarTypeDict
{
    using namespace alg::metatools;

    template <typename... Types>
    struct Values
    {
        constexpr Values() = default;
        constexpr Values(const Values &) = default;
        constexpr Values &operator=(const Values &) = default;
        constexpr Values &operator=(Values &&) = default;
        constexpr Values(std::shared_ptr<void>(&&input)[sizeof...(Types)])
        {
            for (std::size_t i = 0; i < sizeof...(Types); ++i)
                m_tuple[i] = std::move(input[i]);
        }

        template <typename TTag, typename TVal>
        constexpr decltype(auto) Set(TVal &&val) &&
        {
            static_constexpr std::size_t TagPos = Tag2ID<TTag, TParams...>;
            using rawVal = std::decay_t<TVal>;
            rawVal *tmp = new rawVal(std::forward<TVal>(val));

            m_tuple[Tag2ID] = std::shared_ptr<void>(tmp,
                                                    [](void *ptr) {
                                                        rawVal *nptr = static_cast<rawVal *>(ptr);
                                                        delete nptr;
                                                    });

            using new_type = NewTupleType<rawVal, TagPos, Values<>, Types...>;
            return new_type(std::move(m_tuple));
        }

    private:
        std::shared_ptr<void> m_tuple[sizeof...(Types)];
    };

    static constexpr decltype(auto) Create()
    {
        using type = typename iCreate<sizeof...(TParams), Values>::type;
        return type{};
    }
};

__ALG__META__END__
