#pragma once
#include "../Headers.hpp"

__ALG__MAT__BEGIN__

template <typename T, T... Args>
struct same_type_array
{
    using value_type = T;
    using type = same_type_array<T, Args...>;
};

__ALG__MAT__END__
