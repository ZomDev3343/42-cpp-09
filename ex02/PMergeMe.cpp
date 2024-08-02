# include "PMergeMe.hpp"

void	merge_insertion_vector(std::vector<int> &a, int left, int right)
{
	int	m;

	if (right - left + 1 <= 1)
		return ;
	m = (right - left + 1) / 2;
	merge_insertion_vector(a, left, left + m - 1);
	merge_insertion_vector(a, left + m, right);

	fusion_insertion_vector(a, left, right, m);
}

void fusion_insertion_vector(std::vector<int> &a, int left, int right, int m)
{
	std::vector<int>	L, R;
	long int			i, j, k;
	long int			ls, rs;

	for (int x = left; x < left + m; x++)
		L.push_back(a[x]);
	for (int x = left + m; x < right + 1; x++)
		R.push_back(a[x]);
	i = 0;
	j = 0;
	k = left;
	ls = L.size();
	rs = R.size();

	while (i < ls && j < rs)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < ls)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < rs)
	{
		a[k] = R[j];
		j++;
		k++;
	}

	for (int x = 0; x < right-left; x++)
	{
		int key = a[left + x];
		j = x - 1;
		while (j >= 0 && a[left + j] > key)
		{
			a[left + j + 1] = a[left + j];
			j--;
		}
		a[left + j + 1] = key;
	}
}

void pmergeme_vector(std::vector<int> &a)
{
	if (a.size() > 0)
		merge_insertion_vector(a, 0, a.size() - 1);
}

void fill_vector(std::vector<int> &v, char **av)
{
	for (int i = 0; av[i]; i++)
	{
		int n = std::atoi(av[i]);
		if (n == 0 && (av[i][0] != '0' || av[i][1] != '\0'))
			return std::cout << "Error: Invalid number sequence!" << std::endl, v.clear(), (void) 0;
		if (std::count(v.begin(), v.end(), n) == 1)
			return std::cout << "Error: Found duplicates in the sequence!" << std::endl, v.clear(), (void) 0;
		v.push_back(n);
	}
}

void print_vector(std::vector<int> const &v)
{
	long int	vs = v.size();
	if (vs == 0)
		return ;
	for (int i = 0; i < vs; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void merge_insertion_deque(std::deque<int> &a, int left, int right)
{
	int	m;

	if (right - left + 1 <= 1)
		return ;
	m = (right - left + 1) / 2;
	merge_insertion_deque(a, left, left + m - 1);
	merge_insertion_deque(a, left + m, right);

	fusion_insertion_deque(a, left, right, m);
}

void fill_deque(std::deque<int> &v, char **av)
{
	for (int i = 0; av[i]; i++)
	{
		int n = std::atoi(av[i]);
		if (n == 0 && (av[i][0] != '0' || av[i][1] != '\0'))
			return std::cout << "Error: Invalid number sequence!" << std::endl, v.clear(), (void) 0;
		if (std::count(v.begin(), v.end(), n) == 1)
			return std::cout << "Error: Found duplicates in the sequence!" << std::endl, v.clear(), (void) 0;
		v.push_back(n);
	}
}

void print_deque(std::deque<int> const &v)
{
	long int	vs = v.size();
	if (vs == 0)
		return ;
	for (int i = 0; i < vs; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

void pmergeme_deque(std::deque<int> &a)
{
	if (a.size() > 0)
		merge_insertion_deque(a, 0, a.size() - 1);
}

void fusion_insertion_deque(std::deque<int> &a, int left, int right, int m)
{
	std::deque<int>	L, R;
	long int			j, k;

	for (int x = left; x < left + m; x++)
		L.push_back(a[x]);
	for (int x = left + m; x < right + 1; x++)
		R.push_back(a[x]);
	j = 0;
	k = left;

	while (!L.empty() && !R.empty())
	{
		if (L.front() <= R.front())
		{
			a[k] = L.front();
			L.pop_front();
		}
		else
		{
			a[k] = R.front();
			R.pop_front();
		}
		k++;
	}

	while (!L.empty())
	{
		a[k] = L.front();
		L.pop_front();
		k++;
	}

	while (!R.empty())
	{
		a[k] = R.front();
		R.pop_front();
		k++;
	}

	for (int x = 0; x < right-left; x++)
	{
		int key = a[left + x];
		j = x - 1;
		while (j >= 0 && a[left + j] > key)
		{
			a[left + j + 1] = a[left + j];
			j--;
		}
		a[left + j + 1] = key;
	}
}
