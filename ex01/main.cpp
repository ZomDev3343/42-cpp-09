# include <iostream>
# include <string.h>
# include <cstdlib>
# include <stack>
# include <sstream>

int main(int ac, char **av)
{
	std::istringstream		expr;
	std::stack<int> 		stack;
	float					res = 0.0f;
	std::string				number;

	if (ac == 2)
	{
		expr.str(av[1]);
		while (!expr.eof())
		{
			expr >> number;
			if (number.length() > 1)
				return std::cout << "Error: Number must be only 1 character long!" << std::endl, EXIT_FAILURE;
			if (number.at(0) == '+')
			{
				if (stack.size() == 1)
				{
					res += stack.top();
					stack.pop();
				}else if (stack.size() >= 2)
				{
					int tmp = stack.top();
					stack.pop();
					tmp += stack.top();
					stack.pop();
					stack.push(tmp);
				}
			}
			else if (number.at(0) == '-')
			{
				if (stack.size() == 1)
				{
					res -= stack.top();
					stack.pop();
				}else if (stack.size() >= 2)
				{
					int tmp = stack.top();
					stack.pop();
					tmp = stack.top() - tmp;
					stack.pop();
					stack.push(tmp);
				}
			}
			else if (number.at(0) == '*')
			{
				if (stack.size() == 1)
				{
					res *= stack.top();
					stack.pop();
				}else if (stack.size() >= 2)
				{
					int tmp = 0;
					tmp = stack.top();
					stack.pop();
					tmp *= stack.top();
					stack.pop();
					stack.push(tmp);
				}
			}
			else if (number.at(0) == '/')
			{
				if (stack.size() == 1)
				{
					res /= (float) stack.top();
					stack.pop();
				}else if (stack.size() >= 2)
				{
					int tmp = stack.top();
					stack.pop();
					tmp = stack.top() / (float) tmp;
					stack.pop();
					stack.push(tmp);
				}
			}
			else if(std::isdigit(number.at(0)))
				stack.push(number.at(0) - '0');
		}
		if (stack.size() == 1)
		{
			res += stack.top();
			stack.pop();
		}
		if (stack.size() > 0)
			std::cout << "Error: Invalid expression" << std::endl;
		else
			std::cout << res << std::endl;
	}
	else
		std::cerr << "Usage: ./polish <expression>" << std::endl;
	return 0;
}
