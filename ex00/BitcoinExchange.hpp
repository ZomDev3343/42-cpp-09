#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>

class BitcoinExchange
{

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		void			fill_db();
		bool			check_date(std::string const& date) const;
		bool			check_amount(float const& amount) const;

		BitcoinExchange &operator=( BitcoinExchange const & rhs );

	private:
		std::map<std::string, float> _db;
};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */
