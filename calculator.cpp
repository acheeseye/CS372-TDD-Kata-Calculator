#include "calculator.hpp"

#include <string>
using std::string;


int calculator(const std::string & s, char inc_c_delim, const string & inc_s_delim)
{
	char c_delim = '\n';
	string s_delim = "";
	int i = 0;
	int sum = 0;

	if (s == "")
	{
		return 0;
	}

	if (inc_c_delim != NULL)
	{
		c_delim = inc_c_delim;
	}

	if (inc_s_delim != "")
	{
		s_delim = inc_s_delim;
	}

	if (s.size() > 3 && s[0] == '/' && s[1] == '/')
	{
		if ((inc_c_delim == NULL) && s[3] == '\n')
		{
			c_delim = s[2];
			i = 3;
		}
		else if ((inc_s_delim == ""))
		{
			i = 2;
			while (s[i] != '\n')
			{
				s_delim += s[i];
				++i;
			}
		}
	}

	while (isdigit(s[i]))
	{
		sum = 10 * sum + (int)(s[i] - '0');
		++i;
	}

	if (sum > 1000)
	{
		sum = 0;
	}

	if (s[i] == '-')
	{
		throw std::runtime_error("Character '-' detected");
	}

	if (s_delim != "")
	{
		if (s.substr(i, s_delim.size()) == s_delim) {
			return calculator(s.substr(i + s_delim.size(), s.size()), c_delim, s_delim) + sum;
		}
	}

	if (s[i] == ',' || s[i] == '\n' || s[i] == c_delim)
	{
		return calculator(s.substr(i + 1, s.size()), c_delim, s_delim) + sum;
	}

	return sum;
}
