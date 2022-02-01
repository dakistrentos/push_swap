/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hard_sort_b.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:48:09 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:57:07 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	five_sort_util(t_couple **couple, int count)
{
	int	res;

	if (count == 2)
		res = find_min(&(*couple)->a);
	else
		res = find_max(&(*couple)->a);
	return (res);
}

void	five_sort(t_couple **couple)
{
	int	i;
	int	count;
	int	min_max;

	count = 2;
	while (count > 0)
	{	
		min_max = five_sort_util(couple, count);
		i = s_util_count_pos(&(*couple)->a, min_max);
		while ((*couple)->a->num != min_max)
		{
			if (i <= 2)
				rotate(&(*couple)->a, 'a');
			else
				rev_rotate(&(*couple)->a, 'a');
		}
		push_b(couple);
		count--;
	}
	three_sort(&(*couple)->a);
	push_a(couple);
	rotate(&(*couple)->a, 'a');
	push_a(couple);
}

void	six_sort(t_couple **couple)
{
	int	i;
	int	min;
	int	count;

	count = 3;
	while (count > 0)
	{	
		min = find_min(&(*couple)->a);
		i = s_util_count_pos(&(*couple)->a, min);
		while ((*couple)->a->num != min)
		{
			if (i <= 2)
				rotate(&(*couple)->a, 'a');
			else
				rev_rotate(&(*couple)->a, 'a');
		}
		push_b(couple);
		count--;
	}
	three_sort(&(*couple)->a);
	push_a(couple);
	push_a(couple);
	push_a(couple);
}

void	seven_sort(t_couple **couple)
{
	int	i;
	int	min;

	min = find_min(&(*couple)->a);
	i = s_util_count_pos(&(*couple)->a, min);
	while ((*couple)->a->num != min)
	{
		if (i <= 2)
			rotate(&(*couple)->a, 'a');
		else
			rev_rotate(&(*couple)->a, 'a');
	}
	push_b(couple);
	six_sort(couple);
	push_a(couple);
}

void	eight_sort(t_couple **couple)
{
	int	i;
	int	min;
	int	count;

	count = 4;
	while (count > 0)
	{	
		min = find_min(&(*couple)->a);
		i = s_util_count_pos(&(*couple)->a, min);
		while ((*couple)->a->num != min)
		{
			if (i <= 2)
				rotate(&(*couple)->a, 'a');
			else
				rev_rotate(&(*couple)->a, 'a');
		}
		push_b(couple);
		count--;
	}
	four_sort(couple);
	push_a(couple);
	push_a(couple);
	push_a(couple);
	push_a(couple);
}
