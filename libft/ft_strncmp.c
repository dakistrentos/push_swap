/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 09:58:42 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/19 17:59:29 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long long	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	long long		i;
	unsigned char	u1;
	unsigned char	u2;

	i = 0;
	while (n)
	{
		u1 = (unsigned char)*s1;
		u2 = (unsigned char)*s2;
		if (u1 == '\0' && u2 == '\0')
			return (i);
		if (u1 != u2)
		{
			i = u1 - u2;
			return (i);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
