#pragma once
#include "../Headers.hpp"
#include "Array.hpp"
#include "Check.hpp"

__ALG__META__BEGIN__

template <class T, T... Args>
using qDim = typename std::enable_if_t<(sizeof...(Args) == 7), // !The qDim's dimension will be 7
                                       same_type_array<T, Args...>>;

typedef qDim<int, 1, 0, 0, 0, 0, 0, 0> qmass;
typedef qDim<int, 0, 1, 0, 0, 0, 0, 0> qlength;
typedef qDim<int, 0, 0, 1, 0, 0, 0, 0> qtime;
typedef qDim<int, 0, 0, 0, 1, 0, 0, 0> qcharge;
typedef qDim<int, 0, 0, 0, 0, 1, 0, 0> qtemperature;
typedef qDim<int, 0, 0, 0, 0, 0, 1, 0> qintensity;
typedef qDim<int, 0, 0, 0, 0, 0, 0, 1> qamount_of_substance;

template <typename T1, typename T2, typename Func>
struct qTransform
{
};

template <template <typename Td, Td... Args1> class T1,
          template <typename Td, Td... Args2> class T2,
          typename Td,
          Td... Args1,
          Td... Args2,
          typename Func>
struct qTransform<T1<Td, Args1...>, T2<Td, Args2...>, Func>
{
    using type = typename qDim<Td, Func()(Args1, Args2)...>::type;
};

template <typename T1, typename T2, typename Func>
using qTransform_t = typename qTransform<T1, T2, Func>::type;

struct qDimAdd
{
    template <typename T>
    constexpr decltype(auto) operator()(T &&v1, T &&v2) const { return v1 + v2; }
};

struct qDimSub
{
    template <typename T>
    constexpr decltype(auto) operator()(T &&v1, T &&v2) const { return v1 - v2; }
};

template <class T, class Dimensions>
struct metaQuantity
{
    using value_type = T;
    using dim_value_type = typename Dimensions::value_type;

    explicit constexpr metaQuantity(T x) : m_value(x) {}
    inline constexpr T value() const { return m_value; }

private:
    value_type m_value;
};

template <class T, class D>
constexpr metaQuantity<T, D>
operator+(const metaQuantity<T, D> &x, const metaQuantity<T, D> &y)
{
    return metaQuantity<T, D>(x.value() + y.value());
}

template <class T, class D>
constexpr metaQuantity<T, D>
operator-(const metaQuantity<T, D> &x, const metaQuantity<T, D> &y)
{
    return metaQuantity<T, D>(x.value() - y.value());
}

template <class T, class D1, class D2>
constexpr metaQuantity<T, typename qTransform<D1, D2, qDimAdd>::type>
operator*(const metaQuantity<T, D1> &x, const metaQuantity<T, D2> &y)
{
    using dim = typename qTransform<D1, D2, qDimAdd>::type;
    return metaQuantity<T, dim>(x.value() * y.value());
}

template <class T, class D1, class D2>
constexpr metaQuantity<T, typename qTransform<D1, D2, qDimSub>::type>
operator/(const metaQuantity<T, D1> &x, const metaQuantity<T, D2> &y)
{
    using dim = typename qTransform<D1, D2, qDimSub>::type;
    return metaQuantity<T, dim>(x.value() / y.value());
}

__ALG__META__END__
