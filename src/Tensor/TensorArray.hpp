#include "../Headers.hpp"

__ALG__BEGIN__

template <typename _T, std::size_t _N>
struct add_np
{
    using type = _T[_N];
};

template <typename _T, std::size_t _N>
using add_np_t = typename add_np<_T, _N>::type;

template <typename _TensorType, std::size_t _arg, std::size_t... _args>
struct makep_tensor
{
    using type = typename makep_tensor<add_np_t<_TensorType, _arg>, _args...>::type;
};

template <typename _TensorType, std::size_t _arg>
struct makep_tensor<_TensorType, _arg>
{
    using type = add_np_t<_TensorType, _arg>;
};

template <typename _TensorType, std::size_t... _args>
using makep_tensor_t = typename makep_tensor<_TensorType, _args...>::type;

template <typename _TensorType, std::size_t _N>
struct _AddPointer
{
    using type = typename std::add_pointer<typename _AddPointer<_TensorType, _N - 1>::type>::type;
};

template <typename _TensorType>
struct _AddPointer<_TensorType, 0>
{
    using type = typename std::remove_reference_t<_TensorType>;
};

template <typename _TensorType, std::size_t... _Dims>
struct ArrayPtr
{
    using type = typename _AddPointer<_TensorType, sizeof...(_Dims)>::type;
};

template <typename _TensorType, std::size_t... _Dims>
using ArrayPtr_t = typename ArrayPtr<_TensorType, _Dims...>::type;

template <typename _TensorType, std::size_t... _Dims>
class Tensor
{
public:
    constexpr Tensor() : _dimension(sizeof...(_Dims)) {}
    using type = makep_tensor_t<_TensorType, _Dims...>;
    decltype(auto) get_raw() { return &_data; }

private:
    std::size_t _dimension;
    type _data;
};

template <class T, T... Args>
struct tyArray
{
    using type = tyArray<T, Args...>;
};

using mass = tyArray<int, 1, 0, 0, 0, 0, 0, 0>;
using length = tyArray<int, 0, 1, 0, 0, 0, 0, 0>;
using time = tyArray<int, 0, 0, 1, 0, 0, 0, 0>;
using charge = tyArray<int, 0, 0, 0, 1, 0, 0, 0>;
using temperature = tyArray<int, 0, 0, 0, 0, 1, 0, 0>;
using intensity = tyArray<int, 0, 0, 0, 0, 0, 1, 0>;
using amount_of_substance = tyArray<int, 0, 0, 0, 0, 0, 0, 1>;

template <typename T1, typename T2, typename Func>
struct tyTransform
{
};

template <template <typename Tv, Tv... Args1> class T1,
          template <typename Tv, Tv... Args2> class T2,
          typename Tv,
          Tv... Args1,
          Tv... Args2,
          typename Func>
struct tyTransform<T1<Tv, Args1...>, T2<Tv, Args2...>, Func>
{
    constexpr tyTransform()
    {
        static_assert(sizeof...(Args1) != 7, "Hi");
        static_assert(sizeof...(Args2) != 7, "Hi");
    }
    using type = typename tyArray<Tv, Func()(Args1, Args2)...>::type;
};

template <typename T1, typename T2, typename Func>
using tyTransform_t = typename tyTransform<T1, T2, Func>::type;

struct tyAdd
{
    template <typename T>
    constexpr decltype(auto) operator()(T &&v1, T &&v2) const { return v1 + v2; }
};

// template <tem>
// using tyAdd_t = typename tyAdd<Tv1, Tv2>::type;

struct tySub
{
    template <typename T>
    constexpr decltype(auto) operator()(T &&v1, T &&v2) const { return v1 - v2; }
};

// template <const auto Tv1, const auto Tv2>
// using tySub_t = typename tySub<Tv1, Tv2>::type;

template <class T, class Dimensions>
struct Quantity
{
    explicit constexpr Quantity(T x) : m_value(x) {}
    constexpr T value() const { return m_value; }

private:
    T m_value;
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

__ALG__END__
