/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stack.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:01:49 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/24 15:51:51 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_node(int num)
{
	ft_putnbr_fd(num, 1);
	ft_putchar_fd('\n', 1);
}

void	print_stack(t_node *head)
{
	t_node	*temp_head;

	temp_head = head;
	if (!head)
		return ;
	if (head->next == NULL && head != NULL)
	{
		print_node(head->num);
		return ;
	}
	while (temp_head->next != NULL)
	{
		print_node(temp_head->num);
		temp_head = temp_head->next;
	}
	print_node(temp_head->num);
}
