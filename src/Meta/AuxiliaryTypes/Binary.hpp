#pragma once
#include "../../Headers.hpp"

__ALG__MAT__BEGIN__

template <std::size_t N>
constexpr std::size_t iBinary = (iBinary<N / 10> << 1) + N % 10;

template <>
constexpr std::size_t iBinary<0> = 0;

__ALG__MAT__END__
