/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_print.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/04 21:01:31 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/24 16:28:19 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter_print(t_list *lst)
{
	int	*temp;

	if (lst)
	{
		while (lst)
		{
			temp = lst->content;
			ft_putnbr_fd(*temp, 1);
			ft_putchar_fd('\n', 1);
			lst = lst->next;
		}
	}
	else
		return ;
}
