/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 14:58:19 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:33:01 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_dup(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_putstr_fd("Error\n", 1);
				exit (0);
			}
			j++;
		}
		i++;
	}
}

void	check_if_sorted(char **argv)
{
	size_t	i;
	int		is_sorted;

	is_sorted = 1;
	i = 1;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			is_sorted = 0;
		i++;
	}
	if (is_sorted)
		exit (0);
}

void	check_chars(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0') || (argv[i][j] > '9'))
			{
				if (argv[i][j] != '-')
				{
					ft_putstr_fd("Error\n", 1);
					exit (0);
				}
			}
			j++;
		}
		i++;
	}
}

void	check_dec_limits(char **argv)
{
	int	int_min;
	int	int_max;
	int	i;

	i = 1;
	int_min = -2147483648;
	int_max = 2147483647;
	while (argv[i])
	{
		if (ft_atol(argv[i]) < int_min || ft_atol(argv[i]) > int_max)
		{
			ft_putstr_fd("Error\n", 1);
			exit (0);
		}
		i++;
	}
}

void	check_sign_symbols(char **argv)
{	
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if ((argv[i][j + 1] == '-' || argv[i][j + 1] == '+') ||
					!argv[i][j + 1])
				{
					ft_putstr_fd("Error\n", 1);
					exit (0);
				}
			}
			j++;
		}
		i++;
	}
}
