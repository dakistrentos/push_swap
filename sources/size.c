/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   size.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:02:36 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:01:57 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_node *head)
{
	int	size;

	size = 0;
	while (head->next != NULL)
	{
		size++;
		head = head->next;
	}
	size++;
	return (size);
}
