#include "mplearning.hpp"

int main()
{
    static_assert(std::is_same_v<alg::metatools::add_const_ref<int>::type, double>);
    static_assert(std::is_same_v<alg::metatools::add_const_ref<int &>::type, double>);
    static_assert(std::is_same_v<alg::metatools::add_const_ref<const int>::type, double>);
    static_assert(std::is_same_v<alg::metatools::add_const_ref<const int &>::type, double>);
}
