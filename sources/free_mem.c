/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:01:02 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/24 15:10:38 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(t_couple **couple)
{
	t_node	*temp_node_a;
	t_node	*temp_node_b;

	temp_node_a = (*couple)->a;
	temp_node_b = (*couple)->b;
	while (temp_node_a)
	{
		temp_node_a = (*couple)->a->next;
		free((*couple)->a);
		(*couple)->a = temp_node_a;
	}
	while (temp_node_b)
	{
		temp_node_b = (*couple)->b->next;
		free((*couple)->b);
		(*couple)->b = temp_node_b;
	}
	free(temp_node_a);
	free(temp_node_b);
	free((*couple)->b);
	free(*couple);
}
