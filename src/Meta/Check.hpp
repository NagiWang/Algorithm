#pragma once
#include "../Headers.hpp"

__ALG__META__BEGIN__

template <std::size_t D, std::size_t B>
struct same_size_check;

template <std::size_t D>
struct same_size_check<D, D>
{
};

__ALG__META__END__
