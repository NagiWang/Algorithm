#pragma once
#include "../../Headers.hpp"

__ALG__MAT__BEGIN__

// ****************************************************************

template <typename T>
struct add_const_ref
{
    using type = const T &;
};

template <typename T>
struct add_const_ref<T &>
{
    using type = T;
};

// ****************************************************************

__ALG__MAT__END__
