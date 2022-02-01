/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmds_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 14:58:33 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/24 15:08:04 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_couple **couple)
{
	if ((*couple)->a)
	{
		add_to_head(&(*couple)->b, (*couple)->a->num);
		remove_from_head(&(*couple)->a);
	}
	ft_putstr_fd("pb\n", 1);
}

void	push_a(t_couple **couple)
{
	if ((*couple)->b)
	{
		add_to_head(&(*couple)->a, (*couple)->b->num);
		remove_from_head(&(*couple)->b);
	}
	ft_putstr_fd("pa\n", 1);
}

void	swap(t_node **head, char stack)
{
	t_node	*temp_node;

	if (!*head)
		return ;
	if ((*head)->next == NULL)
		return ;
	temp_node = *head;
	*head = (*head)->next;
	temp_node->next = (*head)->next;
	(*head)->next->prev = temp_node;
	(*head)->next = temp_node;
	(*head)->prev = NULL;
	temp_node->prev = *head;
	if (stack == 'a')
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

/* at first make the list circular, then move every node one step forward */
void	rotate(t_node **head, char stack)
{
	t_node	*new_head;
	t_node	*current_tail;
	t_node	*old_head;
	int		size;

	size = stack_size(*head);
	if (size < 2)
		return ;
	new_head = (*head)->next;
	old_head = *head;
	while ((*head)->next != NULL)
		*head = (*head)->next;
	current_tail = *head;
	old_head->prev = current_tail;
	current_tail->next = old_head;
	new_head->prev = NULL;
	old_head->next = NULL;
	*head = new_head;
	if (stack == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

/* at first make the list circular, then move every node one step backwards */
void	rev_rotate(t_node **head, char stack)
{
	t_node	*new_head;
	t_node	*new_tail;
	t_node	*old_head;
	int		size;

	size = stack_size(*head);
	if (size < 2)
		return ;
	old_head = *head;
	while ((*head)->next != NULL)
		*head = (*head)->next;
	new_head = *head;
	new_tail = new_head->prev;
	new_head->prev = NULL;
	new_head->next = old_head;
	old_head->prev = new_head;
	new_head->prev = NULL;
	new_tail->next = NULL;
	*head = new_head;
	if (stack == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}
