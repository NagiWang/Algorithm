#pragma once
#include "../../Headers.hpp"

__ALG__MAT__BEGIN__

template <std::size_t N>
struct iBinary
{
    static_assert((N % 10) <= 1, "iBinary< Number > : Number must be a binary number!");
    static constexpr std::size_t value = 2 * iBinary<N / 10>::value + N % 10;
};

template <>
struct iBinary<0>
{
    static constexpr std::size_t value = 0;
};

template <std::size_t N>
static constexpr std::size_t iBinary_v = iBinary<N>::value;

__ALG__MAT__END__
