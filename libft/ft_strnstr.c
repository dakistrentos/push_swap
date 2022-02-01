/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/06 08:58:26 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/11/17 16:16:03 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	check_len(char *big, char *little)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(big);
	len2 = ft_strlen(little);
	if (len2 > len1)
		return (-1);
	else if (len2 < len1)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*l;
	char	*s;
	size_t	comp;
	int		check;
	size_t	ned_len;

	l = (char *)big;
	s = (char *)little;
	ned_len = ft_strlen(little);
	check = check_len(l, s);
	if (check < 0)
		return (NULL);
	if (s == NULL || *s == '\0')
		return (l);
	while ((*l && len > 0) && (len >= ned_len))
	{
		comp = ft_memcmp(l, s, ned_len);
		if (comp == 0)
			return (l);
		len--;
		l++;
	}
	return (NULL);
}
