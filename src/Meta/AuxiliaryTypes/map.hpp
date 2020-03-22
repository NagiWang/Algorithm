#pragma once
#include "../../Headers.hpp"

__ALG__MAT__BEGIN__

template <typename... Args>
constexpr auto get_value(Args... args)
{
    constexpr auto a = {args...};
    return a[sizeof...(Types) - 1];
}

template <typename... Args>
struct pair
{
    static_assert(sizeof...(Args) > 2, "Args too much!");
    static_assert(sizeof...(Args) < 2, "Args too less!");
    constexpr pair(Args... args){};
    static Tvalue value = args;
};

template <typename Tkey, typename Tvalue>
constexpr auto make_pair(Tkey Key, Tvalue Value)
{
    return pair<Key>(Value);
}

__ALG__MAT__END__
