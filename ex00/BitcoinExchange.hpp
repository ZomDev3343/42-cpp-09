#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <cstdlib>
# include <sstream>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();
		BitcoinExchange &operator=( BitcoinExchange const & rhs );

		std::map<std::string, float> const& getDB() const;

		/* Database */

		void			fill_db();
		bool			check_date(std::string const& date) const;

		/* Input File */

		bool			check_amount(float const& amount) const;
		std::string		find_prev_date(std::string date);
		float			calculate_amount(std::string &date, float &amount);
		void			exchange(char *file_path);

		/* Exception */

		class DateNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};


	private:
		std::map<std::string, float> _db;
};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */
