#include "mplearning.hpp"

int main()
{
    static_assert(std::is_same_v<alg::metatools::add_const_ref<int>::type, double>, "Hi");
    static_assert(std::is_same_v<alg::metatools::add_const_ref<int &>::type, double>, "Hi");
    static_assert(std::is_same_v<alg::metatools::add_const_ref<const int>::type, double>, "Hi");
    static_assert(std::is_same_v<alg::metatools::add_const_ref<const int &>::type, double>, "Hi");
    static_assert(std::is_same_v<std::void_t<decltype(++std::declval<int&>())>, void>, "Hi");
}
