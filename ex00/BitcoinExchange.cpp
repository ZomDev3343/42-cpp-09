#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
	this->fill_db();
	if (this->_db.empty())
		exit(EXIT_FAILURE);
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}

std::map<std::string, float> const &BitcoinExchange::getDB() const
{
	return this->_db;
}

void BitcoinExchange::fill_db()
{
	std::ifstream	input("data.csv");
	std::string		line, date;
	float			amount;
	if (input.is_open())
	{
		std::getline(input, line);
		while (std::getline(input, line))
		{
			if (!line[10] || line[10] != ',')
			{
				input.close();
				this->_db.clear();
				std::cerr << "Error: Database file has incorrect format" << std::endl;
				return ;
			}
			date = line.substr(0, 10);
			amount = std::atof(line.substr(11).c_str());
			if (check_date(date))
				this->_db[date] = amount;
			else
			{
				input.close();
				this->_db.clear();
				std::cerr << "Error: Incorrect values in database : " << date << "," << amount << std::endl;
				return ;
			}
		}
		input.close();
	}
	else
		std::cerr << "Error: Can't open database file!" << std::endl;
}

bool BitcoinExchange::check_date(std::string const &date) const
{
	int	year, month, day;

	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (year < 2009 || month < 0 || month > 12 || day < 0 || day > 31 || (month == 2 && day > 29))
		return false;
	return true;
}

bool BitcoinExchange::check_amount(float const &amount) const
{
	return amount >= 0.0f && amount <= 1000.0f;
}

std::string BitcoinExchange::find_prev_date(std::string date)
{
	if (this->_db.find(date) != this->_db.end())
		return (date);

	int					year = std::atoi(date.substr(0, 4).c_str());
	int					month = std::atoi(date.substr(5, 2).c_str());
	int					day = std::atoi(date.substr(8, 2).c_str());
	std::stringstream	new_date(date);

	while (this->_db.find(new_date.str()) == this->_db.end())
	{
		if (!--day)
		{
			day = 31;
			if (!--month)
			{
				month = 12;
				if (--year < 2009)
					throw BitcoinExchange::DateNotFoundException();
			}
		}
		new_date.clear();
		new_date << year << "-" << (month < 10 ? "0" : "") << month << (day < 10 ? "0" : "") << day;
	}
	return (new_date.str());
}

float BitcoinExchange::calculate_amount(std::string &date, float &amount)
{
	std::string	prev_date;

	try
	{
		prev_date = find_prev_date(date.substr(0, 10));
	}
	catch(const BitcoinExchange::DateNotFoundException& e)
	{
		std::cerr << e.what() << '\n';
		return (-1.0f);
	}
	return this->_db[prev_date] * amount;
}

void BitcoinExchange::exchange(char *file_path)
{
	std::ifstream	input(file_path);
	std::string 	line;
	std::string 	date;
	float			amount;
	float			real_amount;
	
	if (input.is_open())
	{
		std::getline(input, line);
		while (std::getline(input, line))
		{
			date = line.substr(0, 10);
			amount = std::atof(line.substr(13).c_str());
			
			if (check_date(date) && check_amount(amount) && (real_amount = calculate_amount(date, amount)) != 1.0f)
				std::cout << date << " => " << amount << " = " << real_amount << std::endl;
			else
				return input.close(), (void) 0;
		}
	}
	else
		std::cerr << "Error: Can't open the input file!" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	if (this != &rhs)
	{
		this->_db.clear();
		this->_db = std::map<std::string, float>(rhs._db);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i )
{
	typedef std::map<std::string, float>::const_iterator it;
	for (it ite = i.getDB().begin(); ite != i.getDB().end(); ++ite)
		o << "Key: " << ite->first << " Value : " << ite->second << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

const char *BitcoinExchange::DateNotFoundException::what() const throw()
{
	return "Error: Can't find a previous date";
}
