#pragma once
#include "../Headers.hpp"

__ALG__BEGIN__

template <typename T>
class linear_squares
{
private:
	std::vector<T> _x, _y;
	std::vector<double> _result;
	bool _flag = false;

	void mse_loss()
	{
		double loss = 0;
		double e = 0;
		for (int i = 0; i < _x.size(); i++)
		{
			e = _y[i] - (_result[0] * _x[i] + _result[1]);
			loss += e * e;
		}
		loss /= _x.size();
		_result[2] = loss;
	}

public:
	linear_squares(const std::vector<T> &x, const std::vector<T> &y)
		: _x(x), _y(y), _result(3, 0)
	{
		if (_x.size() != _y.size())
		{
			std::cout << RED
					  << "\nWarning: x.size() != y.size()\n"
					  << RESET;
		}
	}

	const std::vector<double> &result()
	{
		if (_flag || _x.size() < 1)
			return _result;
		else
			_flag = true;

		int N = _x.size();
		double sum_x = std::accumulate(_x.begin(), _x.end(), 0);
		double mean_x = sum_x / N;
		double sum_y = std::accumulate(_y.begin(), _y.end(), 0);
		double mean_y = sum_y / N;
		double sum_xy = std::inner_product(_x.begin(), _x.end(), _y.begin(), 0);
		double sum_xx = std::inner_product(_x.begin(), _x.end(), _x.begin(), 0);

		_result[0] = (N * sum_xy - sum_x * sum_y) / (N * sum_xx - sum_x * sum_x);
		_result[1] = mean_y - _result[0] * mean_x;

		mse_loss();

		return _result;
	}

	T prediction(const T &x_data) { return _result[0] * x_data + _result[1]; }
	std::vector<T> prediction(const std::vector<T> &x_data)
	{
		std::vector<T> pred{};
		std::for_each(x_data.begin(), x_data.end(),
					  [&](const auto &value) { pred.push_back(value * _result[0] + _result[1]); });
		return pred;
	}
};

__ALG__END__
