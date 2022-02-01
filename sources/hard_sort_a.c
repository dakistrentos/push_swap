/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hard_sort_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:01:15 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:58:31 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	s_util_count_pos(t_node **head, int num)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	temp_node = *head;
	while (temp_node->num != num)
	{
		temp_node = temp_node->next;
		i++;
	}
	return (i);
}

void	two_sort(t_node **head)
{
	rotate(head, 'a');
}

void	three_sort(t_node **head)
{
	t_node	*temp_node;
	int		min;
	int		max;

	temp_node = *head;
	min = find_min(&temp_node);
	max = find_max(&temp_node);
	if (temp_node->num == min && temp_node->next->num == max)
	{
		swap(head, 'a');
		rotate(head, 'a');
	}
	else if (temp_node->num == max && temp_node->next->num == min)
		rotate(head, 'a');
	else if (temp_node->num == max && temp_node->next->num != min)
	{
		swap(head, 'a');
		rev_rotate(head, 'a');
	}
	else if (temp_node->next->num == min && temp_node->num != max)
		swap(head, 'a');
	else if (temp_node->next->num == max && temp_node->num != min)
		rev_rotate(head, 'a');
}

void	four_sort(t_couple **couple)
{
	t_node	*temp_node;
	int		min;
	int		i;

	temp_node = (*couple)->a;
	min = find_min(&temp_node);
	i = s_util_count_pos(&(*couple)->a, min);
	while ((*couple)->a->num != min)
	{
		if (i <= 1)
			rotate(&(*couple)->a, 'a');
		else
			rev_rotate(&(*couple)->a, 'a');
	}
	push_b(couple);
	three_sort(&(*couple)->a);
	push_a(couple);
}
