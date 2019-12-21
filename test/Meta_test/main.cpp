#include "../../Algorithm.hpp"

int main()
{
    // static_assert(std::is_same<alg::Tensor<double, 1, 2, 3>::type, double[3][2][1]>::value, "Hi~");
    // static_assert(std::is_same<alg::makep_tensor_t<int, 3, 4, 5>, int[5][4][3]>::value, "Hi~");

    using a = alg::meta::tyDim<int, 0, 1, 1, 0, 0, 0, 0>;
    using b = alg::meta::tyDim<int, 0, 1, 0, 1, 0, 0, 0>;

    using c = typename alg::meta::tyTransform_t<a, b, alg::meta::tySub>;

    constexpr auto d = alg::meta::Quantity<double, alg::meta::mass>(5);
    constexpr auto e = alg::meta::Quantity<double, alg::meta::time>(9);
    constexpr auto f = d * e;

    // using c = decltype(alg::Mul<a>(a{},b{}));
    static_assert(std::is_same<c, alg::meta::mass>::value, "Hi~");
    static_assert(f.value(), "Hi~");
}
