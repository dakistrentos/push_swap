/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_argv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 17:45:16 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:49:21 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	index_argv(char **argv, int current)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (argv[i])
	{
		if (current > ft_atoi(argv[i]))
			res++;
		i++;
	}
	return (res);
}

int	*convert_argv(char **argv, int argc)
{
	int	*new_argv;
	int	j;
	int	i;

	j = 0;
	i = 1;
	new_argv = malloc(sizeof(int) * argc - 1);
	while (argv[i])
	{
		new_argv[j] = index_argv(argv, ft_atoi(argv[i]));
		j++;
		i++;
	}
	return (&new_argv[0]);
}
