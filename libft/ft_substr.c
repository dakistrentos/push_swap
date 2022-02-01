/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 08:27:57 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/09/22 13:32:57 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	if (!s)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if (len <= 0 || start >= slen)
		return (ft_strdup(""));
	if (start + len > slen)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (start > 0)
	{
		s++;
		start--;
	}
	ft_memcpy(sub, (char *)s, len);
	sub[len] = '\0';
	return (sub);
}
