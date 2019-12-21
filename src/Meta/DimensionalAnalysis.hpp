#include "../Headers.hpp"

__ALG__META__BEGIN__

template <class T, T... Args>
struct tyDim
{
    using type = tyDim<T, Args...>;
    using value_type = T;
};

typedef tyDim<int, 1, 0, 0, 0, 0, 0, 0> mass;
typedef tyDim<int, 0, 1, 0, 0, 0, 0, 0> length;
typedef tyDim<int, 0, 0, 1, 0, 0, 0, 0> time;
typedef tyDim<int, 0, 0, 0, 1, 0, 0, 0> charge;
typedef tyDim<int, 0, 0, 0, 0, 1, 0, 0> temperature;
typedef tyDim<int, 0, 0, 0, 0, 0, 1, 0> intensity;
typedef tyDim<int, 0, 0, 0, 0, 0, 0, 1> amount_of_substance;

template <typename T1, typename T2, typename Func>
struct tyTransform
{
};

template <template <typename Td, Td... Args1> class T1,
          template <typename Td, Td... Args2> class T2,
          typename Td,
          Td... Args1,
          Td... Args2,
          typename Func>
struct tyTransform<T1<Td, Args1...>, T2<Td, Args2...>, Func>
{
    constexpr tyTransform()
    {
        static_assert(sizeof...(Args1) != 7, "Hi");
        static_assert(sizeof...(Args2) != 7, "Hi");
    }
    using type = typename tyDim<Td, Func()(Args1, Args2)...>::type;
};

template <typename T1, typename T2, typename Func>
using tyTransform_t = typename tyTransform<T1, T2, Func>::type;

struct tyAdd
{
    template <typename T>
    constexpr decltype(auto) operator()(T &&v1, T &&v2) const { return v1 + v2; }
};

struct tySub
{
    template <typename T>
    constexpr decltype(auto) operator()(T &&v1, T &&v2) const { return v1 - v2; }
};

template <class T, class Dimensions>
struct Quantity
{
    using value_type = T;
    using dim_value_type = typename Dimensions::value_type;

    explicit constexpr Quantity(T x) : m_value(x) {}
    inline constexpr T value() const { return m_value; }

private:
    value_type m_value;
};

template <class T, class D>
constexpr Quantity<T, D>
operator+(const Quantity<T, D> &x, const Quantity<T, D> &y)
{
    return Quantity<T, D>(x.value() + y.value());
}

template <class T, class D>
constexpr Quantity<T, D>
operator-(const Quantity<T, D> &x, const Quantity<T, D> &y)
{
    return Quantity<T, D>(x.value() - y.value());
}

template <class T, class D1, class D2>
constexpr Quantity<T, typename tyTransform<D1, D2, tyAdd>::type>
operator*(const Quantity<T, D1> &x, const Quantity<T, D2> &y)
{
    using dim = typename tyTransform<D1, D2, tyAdd>::type;
    return Quantity<T, dim>(x.value() * y.value());
}

template <class T, class D1, class D2>
constexpr Quantity<T, typename tyTransform<D1, D2, tySub>::type>
operator/(const Quantity<T, D1> &x, const Quantity<T, D2> &y)
{
    using dim = typename tyTransform<D1, D2, tySub>::type;
    return Quantity<T, dim>(x.value() / y.value());
}

__ALG__META__END__
