#include "../Headers.h"

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

__ALG__END__
