#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::fill_db()
{
	std::ifstream	input("data.csv");
	std::string		line, date;
	float			amount;
	if (input.is_open())
	{
		std::getline(input, line);
		std::getline(input, line);
		while (line[10] && line[10] == ',')
		{
			date = line.substr(0, 10);
			amount = std::atof(line.substr(11).c_str());
		}
	}
	else
		std::cerr << "Error: Can't open database file!" << std::endl;
}

bool BitcoinExchange::check_date(std::string const &date) const
{
	int	year, month, day;

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(4, 2).c_str());
	day = std::atoi(date.substr(6, 2).c_str());
	if (year < 2009 || month < 0 || month > 12 || day < 0 || day > 31 || (month == 2 && day > 29))
		return false;
	return true;
}

bool BitcoinExchange::check_amount(float const &amount) const
{
	return false;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
