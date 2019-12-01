#include "../../Algorithm.h"

int main()
{
	std::vector<int> x_data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> y_data{};
	std::for_each(x_data.begin(), x_data.end(),
				  [&y_data](const auto &value) { y_data.push_back(value * 5 + 4); });

	alg::linear_squares ls_model(x_data, y_data);
	auto result{ls_model.result()};
	alg::array_print(result);
}
