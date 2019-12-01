#include "../Headers.h"

__ALG__BEGIN__


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
private:
	std::size_t _dimension;
	using _Type = typename ArrayPtr<_TensorType, _Dims...>::type;
	_Type _data;

public:
	constexpr Tensor() : _dimension(sizeof...(_Dims)) {}
	_Type get_raw() { return _data; }
};

__ALG__END__
