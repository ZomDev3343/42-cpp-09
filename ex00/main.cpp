# include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange be;
		be.exchange(av[1]);
	}
	else
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
	return 0;
}
