# include "PMergeMe.hpp"

int main(int ac, char **av)
{
	std::vector<int>		vec;
	std::deque<int>			deq;
	clock_t					start, end;

	if (ac >= 2)
	{
		fill_vector(vec, av + 1);
		if (vec.empty())
			return 1;
		std::cout << "Before: ";
		print_vector(vec);
		start = clock();
		pmergeme_vector(vec);
		end = clock();
		std::cout << "After: ";
		print_vector(vec);
		std::cout << std::fixed;
		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << double(end - start) / CLOCKS_PER_SEC << " us" << std::endl;
		fill_deque(deq, av + 1);
		start = clock();
		pmergeme_deque(deq);
		end = clock();
		std::cout << "Time to process a range of " << deq.size() << " elements with std::vector : " << double(end - start) / CLOCKS_PER_SEC << " us" << std::endl;
	}
	else
		std::cout << "Usage: ./pmergeme <number_sequence>" << std::endl;
	return 0;
}
