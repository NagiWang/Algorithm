#pragma once
#include "../Headers.hpp"

__ALG__MAT__BEGIN__

template <std::size_t D, std::size_t B>
struct same_size_check;

template <std::size_t D>
struct same_size_check<D, D>
{
};

template <auto... T>
struct false_type;

__ALG__MAT__END__
