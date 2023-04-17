/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMedeque.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:54:11 by aperin            #+#    #+#             */
/*   Updated: 2023/04/17 11:57:13 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void	insertion_sort_d(std::deque<int> &deque, int i1, int i2)
{
	for (int i = i1 + 1; i <= i2; i++)
	{
		int tmp = deque[i];
		int j = i - 1;
		while (j >= i1 && deque[j] > tmp)
		{
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = tmp;
	}
}

static void	merge_d(std::deque<int> &deque, int i1, int mid, int i2)
{
	int left_size = mid - i1 + 1;
	int right_size = i2 - mid;

	int left[left_size];
	int right[right_size];

	for (int i = 0; i < left_size; i++)
		left[i] = deque[i1 + i];
	for (int i = 0; i < right_size; i++)
		right[i] = deque[mid + i + 1];

	int i = 0, li = 0, ri = 0;
	while (li < left_size && ri < right_size)
	{
		if (left[li] < right[ri])
		{
			deque[i1 + i] = left[li];
			li++;
		}
		else
		{
			deque[i1 + i] = right[ri];
			ri++;
		}
		i++;
	}
	for (; li < left_size ; li++, i++)
		deque[i1 + i] = left[li];
	for (; ri < right_size ; ri++, i++)
		deque[i1 + i] = right[ri];
}

static void	merge_insert_sort_d(std::deque<int> &deque, int i1, int i2)
{
	int	mid = i1 + (i2 - i1) / 2;

	if (i2 - i1 <= K)
		insertion_sort_d(deque, i1, i2);
	else
	{
		merge_insert_sort_d(deque, i1, mid);
		merge_insert_sort_d(deque, mid + 1, i2);
	}
	merge_d(deque, i1, mid, i2);
}

void	merge_insert_sort_deque(std::deque<int> &deque)
{
	merge_insert_sort_d(deque, 0, deque.size() - 1);
}
