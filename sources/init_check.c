/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_check.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 15:01:23 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:48:12 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_all(char **argv)
{
	check_chars(argv);
	check_sign_symbols(argv);
	check_dup(argv);
	check_dec_limits(argv);
	check_if_sorted(argv);
}

void	init_head(t_node *head)
{
	head->next = NULL;
	head->prev = NULL;
}

t_couple	*init_stacks(
	int *new_argv, t_node *head_a, t_node *head_b, int argc)
{
	t_couple	*couple;
	int			i;

	i = 0;
	couple = (t_couple *)malloc(sizeof(*couple));
	while (i < argc - 1)
	{
		if (i == 0)
			add_to_head(&head_a, new_argv[i]);
		else
			add_to_tail(&head_a, new_argv[i]);
		i++;
	}
	i = 0;
	free(new_argv);
	couple->a = head_a;
	couple->b = head_b;
	return (couple);
}
