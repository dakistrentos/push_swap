/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 11:19:14 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/11/17 16:14:09 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	free_array(char **arr, int words)
{
	if (words <= 0)
		free(arr);
	else
	{
		words--;
		while (words >= 0)
		{
			if (arr[words])
				free(arr[words]);
			words--;
		}
	}
	free(arr);
}

int	count_words(char *str3, char c)
{
	int		i;
	int		j;
	size_t	f;
	size_t	len;

	j = 0;
	f = 0;
	len = ft_strlen(str3);
	while (f < len)
	{
		i = 0;
		while (str3[f] != c && str3[f] != '\0')
		{
			i++;
			f++;
		}
		if (i != 0)
			j++;
		if (f >= len)
			break ;
		f++;
	}
	return (j);
}

static char	*string_ptr(char *str2, char c)
{
	int		i;
	char	*str;
	char	*string;

	i = 0;
	str = str2;
	while (*str != c && *str != '\0')
	{
		i++;
		str++;
	}
	string = (char *)malloc(i + 1);
	if (!string)
		return (NULL);
	ft_strlcpy(string, str - i, i + 1);
	return (string);
}

static char	**malloc_array(int words, char c, char *str2)
{
	char	**ar;
	int		l;
	size_t	len;

	l = 0;
	ar = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ar)
		return (NULL);
	while (l < words)
	{
		while (*str2 == c && *str2)
			str2++;
		ar[l] = string_ptr(str2, c);
		if (!ar[l])
		{
			free_array(ar, l - 1);
			return (NULL);
		}
		len = ft_strlen(ar[l]);
		str2 = str2 + len;
		l++;
	}
	ar[words] = NULL;
	return (ar);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**arr;

	if (!s)
		return (NULL);
	words = count_words((char *)s, c);
	arr = malloc_array(words, c, (char *)s);
	if (!arr)
		return (NULL);
	return (arr);
}
