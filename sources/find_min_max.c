/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_min_max.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:00:30 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:48:58 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max_digits(t_node *head)
{
	int	max;

	max = head->num;
	while (head->next != NULL)
	{
		if (max < head->num)
			max = head->num;
		head = head->next;
	}
	if (max < head->num)
			max = head->num;
	return (find_num_digits(max));
}

int	find_num_digits(long long num)
{
	int	digits_num;

	digits_num = 0;
	while (num >> digits_num != 0)
		digits_num++;
	return (digits_num);
}

int	find_min(t_node **head)
{
	t_node	*temp_head;
	int		min;

	temp_head = *head;
	min = temp_head->num;
	while (temp_head->next != NULL)
	{
		if (min > temp_head->num)
			min = temp_head->num;
		temp_head = temp_head->next;
	}
	if (min > temp_head->num)
		min = temp_head->num;
	return (min);
}

int	find_max(t_node **head)
{
	int	max;

	max = (*head)->num;
	while ((*head)->next != NULL)
	{
		if (max < (*head)->num)
			max = (*head)->num;
		head = &(*head)->next;
	}
	if (max < (*head)->num)
			max = (*head)->num;
	return (max);
}
