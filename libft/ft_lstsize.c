/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/13 17:05:16 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/09/22 13:30:12 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*lst2;

	lst2 = lst;
	i = 0;
	if (!lst)
		return (0);
	while (lst2->next != NULL)
	{
		i++;
		lst2 = lst2->next;
	}
	i++;
	return (i);
}
