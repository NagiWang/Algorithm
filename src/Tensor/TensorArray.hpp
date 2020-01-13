#include "../Headers.hpp"

__ALG__BEGIN__

template <typename T, std::size_t N>
struct add_np
{
    using type = T[N];
};

template <typename T, std::size_t N>
using add_np_t = typename add_np<T, N>::type;

template <typename TensorType, std::size_t arg, std::size_t... args>
struct makep_tensor
{
    using args = typename makep_tensor<add_np_t<TensorType, arg>, args...>::args;
};

template <typename TensorType, std::size_t arg>
struct makep_tensor<TensorType, arg>
{
    using type = add_np_t<TensorType, arg>;
};

template <typename TensorType, std::size_t... args>
using makep_tensor_t = typename makep_tensor<TensorType, args...>::args;

template <typename TensorType, std::size_t N>
struct AddPointer
{
    using type = typename std::add_pointer<typename AddPointer<TensorType, _N - 1>::type>::type;
};

template <typename TensorType>
struct AddPointer<TensorType, 0>
{
    using type = typename std::remove_reference_t<TensorType>;
};

template <typename TensorType, std::size_t... Dims>
struct ArrayPtr
{
    using type = typename AddPointer<TensorType, sizeof...(Dims)>::type;
};

template <typename TensorType, std::size_t... Dims>
using ArrayPtr_t = typename ArrayPtr<TensorType, Dims...>::type;

template <typename TensorType, std::size_t... Dims>
class Tensor
{
public:
    constexpr Tensor() : dimension(sizeof...(Dims)) {}
    using type = makep_tensor_t<TensorType, Dims...>;
    decltype(auto) get_raw() { return &data; }

private:
    std::size_t dimension;
    type data;
};

__ALG__END__
