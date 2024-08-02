# include "PMergeMe.hpp"

int main(int ac, char **av)
{
	std::vector<int>	vec;
	if (ac >= 2)
	{
		fill_vector(vec, av + 1);
		pmergeme_vector(vec);
		print_vector(vec);
	}
	else
		std::cout << "Usage: ./pmergeme <number_sequence>" << std::endl;
	return 0;
}
