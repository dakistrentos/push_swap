/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmds_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 14:59:54 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/24 16:24:29 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* pop from stack */
void	remove_from_head(t_node **head)
{
	t_node	*temp_node;

	temp_node = *head;
	if (!*head || !head)
		return ;
	if (temp_node != NULL)
	{
		*head = temp_node->next;
		if (!head)
			free(head);
		free(temp_node);
		return ;
	}
}

void	add_to_tail(t_node **head, int num)
{
	t_node	*new_node;
	t_node	*temp;

	temp = *head;
	new_node = malloc(sizeof(*new_node));
	new_node->num = num;
	if (*head == NULL)
	{
		*head = new_node;
		init_head(*head);
		return ;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
		new_node->next = NULL;
	}
}

/* push to stack */
void	add_to_head(t_node **head, int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	new_node->num = num;
	if (*head == NULL)
	{
		*head = new_node;
		init_head(*head);
	}
	else
	{
		(*head)->prev = new_node;
		new_node->next = *head;
		*head = new_node;
	}
}

int	is_empty(t_node *head)
{
	if (stack_size(head) > 0)
		return (1);
	return (0);
}
