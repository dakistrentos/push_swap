/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 17:47:41 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/19 18:19:44 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 12:13:09 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/11/17 16:05:55 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static long long	conv_loop(const char *str)
{
	long long	num;
	long long	r;
	int			sign;

	num = 0;
	r = 0;
	sign = 1;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = *str - '0';
		r = num + (r * 10);
		str++;
	}
	r = r * sign;
	return (r);
}

long long	ft_atol(const char *str)
{
	long long	res;
	char		*s;

	s = (char *)str;
	if (*s == '+' || *s == '-')
	{
		s++;
		if (*s == '+' || *s == '-')
			return (0);
	}
	while ((*str == ' ' || *str == '\n')
		|| (*str == '\r' || *str == '\f')
		|| (*str == '\v' || *str == '\t'))
		str++;
	res = conv_loop(str);
	return (res);
}
