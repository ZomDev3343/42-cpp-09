#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string.h>
# include <vector>
# include <sstream>
# include <algorithm>

void	merge_insertion(std::vector<int> &a, int left, int right);
void	fusion_insertion(std::vector<int> &a, int left, int right, int m);
void	pmergeme_vector(std::vector<int> &a);
void	fill_vector(std::vector<int> &v, char **av);
void	print_vector(std::vector<int> const& v);

#endif