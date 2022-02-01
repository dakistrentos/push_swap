/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 12:13:43 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/11/17 16:06:16 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str1;

	str1 = s;
	while (n > 0)
	{
		*str1 = '\0';
		str1++;
		n--;
	}
}
