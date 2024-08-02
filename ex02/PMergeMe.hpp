#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string.h>
# include <vector>
# include <algorithm>
# include <deque>
# include <ctime>
# include <iomanip>

void	merge_insertion_vector(std::vector<int> &a, int left, int right);
void	fusion_insertion_vector(std::vector<int> &a, int left, int right, int m);
void	pmergeme_vector(std::vector<int> &a);
void	fill_vector(std::vector<int> &v, char **av);
void	print_vector(std::vector<int> const& v);

void	merge_insertion_deque(std::deque<int> &a, int left, int right);
void	fusion_insertion_deque(std::deque<int> &a, int left, int right, int m);
void	pmergeme_deque(std::deque<int> &a);
void	fill_deque(std::deque<int> &v, char **av);
void	print_deque(std::deque<int> const& v);

#endif