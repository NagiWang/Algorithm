#include "../../Algorithm.hpp"

int main()
{
    using namespace alg::meta;

    using a = qDim<int, 0, 1, 1, 0, 0, 0, 0>;
    using b = qDim<int, 0, 1, 0, 1, 0, 0, 0>;

    using c =  qTransform_t<a, b, qDimSub>;
    // using d = qDim<int, 1, 2, 3>;
    // d n{};

    constexpr auto e = metaQuantity<double, qmass>(5);
    constexpr auto f = metaQuantity<double, qtime>(9);
    constexpr auto g = e * f;


    static_assert(!std::is_same_v<c, qmass>, "Hi~");
    static_assert(g.value(), "Hi~");
}
