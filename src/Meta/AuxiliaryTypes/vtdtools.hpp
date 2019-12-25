#pragma once
#include "../Headers.hpp"

__ALG__MAT__BEGIN__

template <typename...>
struct NullParameter;
/****************************************************************/

template <typename TFindTag, std::size_t N, typename TCurTag, typename... TTags>
static_constexpr std::size_t iTag2ID = iTag2ID<TFindTag, N + 1, TTags...>;

template <typename TFindTag, std::size_t N, typename... TTags>
static_constexpr std::size_t iTag2ID<TFindTag, N, TFindTag, TTags...> = N;

template <typename TFindTag, typename... TTags>
constexpr std::size_t Tag2ID = iTag2ID<TFindTag, 0, TTags...>;

/****************************************************************/

template <std::size_t N, template <typename...> class TConstruct, typename... Types>
struct iCreate
{
    using type = typename iCreate<N - 1, TConstruct, NullParameter, T...>::type;
};

template <template <typename...> class TConstruct, typename... Types>
struct iCreate<0, TConstruct, Types...>
{
    using type = TConstruct<Types...>;
};

__ALG__MAT__END__
