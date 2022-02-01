/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:03:39 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/24 16:22:04 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	radix_loop(t_couple **couple, int size, int max_digits)
{
	int	i;
	int	j;
	int	current_size;

	i = 0;
	j = 0;
	while (i < max_digits)
	{
		while (j < size)
		{
			if ((((*couple)->a->num >> i) & 1) == 1)
				rotate(&(*couple)->a, 'a');
			else
				push_b(couple);
			j++;
		}
		j = 0;
		i++;
		current_size = stack_size((*couple)->b);
		while (current_size > 0)
		{
			push_a(couple);
			current_size--;
		}
	}
}

void	radix_sort(t_couple **couple)
{
	int	max_digits;
	int	size;

	size = stack_size((*couple)->a);
	max_digits = find_max_digits((*couple)->a);
	radix_loop(couple, size, max_digits);
}
