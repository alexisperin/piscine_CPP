#include "PmergeMe.hpp"

static void	insertion_sort_v(std::vector, int i1, int i2)
{
	
}

static void	merge_insert_sort_v(std::vector, int i1, int i2)
{
	int	mid = i1 + (i2 - i1) / 2;

	if (i2 - i1 <= K)
		insertion_sort_v(vector, i1, i2);
	else
	{
		merge_insert_sort_v(vector, i1, mid);
		merge_insert_sort_v(vector, mid + 1, i2);
	}
	merge_v(vector, i1, mid, i2);
}

void	merge_insert_sort_vector(std::vector &vector)
{
	merge_insert_sort_v(std::vector &vector, 0, vector.length() - 1);
}
