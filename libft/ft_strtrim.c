/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 08:08:39 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/11/17 16:16:59 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	find_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	char_count_start(char const *str, char const *set)
{
	int	x;
	int	f;

	x = 0;
	f = 0;
	while (str[f] && find_char_in_set(str[f], set))
	{
		f++;
		x++;
	}
	return (x);
}

static int	char_count_end(
	char const *str, char const *set, size_t startlen)
{
	int		y;
	size_t	len;

	len = ft_strlen(str) - 1;
	y = 0;
	while (len > startlen && find_char_in_set(str[len], set))
	{
		len--;
		y++;
	}
	return (y);
}

static char	*res_do(char const *s1, char const *set)
{
	char	*res;
	char	*str;
	size_t	startlen;
	int		endlen;
	int		totlen;

	str = (char *)s1;
	startlen = char_count_start(s1, set);
	endlen = char_count_end(str, set, startlen);
	if (startlen == 0 && endlen == 0)
		return (ft_strdup(s1));
	totlen = ft_strlen(s1) - (startlen + endlen);
	if (totlen <= 0)
		return (ft_strdup(""));
	res = (char *)malloc(totlen + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1 + (startlen), totlen);
	res[totlen] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	res = res_do(s1, set);
	return (res);
}
