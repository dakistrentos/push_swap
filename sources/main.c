/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 14:57:40 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/30 18:01:18 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	f_print_content(int content)
{
	ft_putnbr_fd(content, 1);
	ft_putchar_fd('\n', 1);
}

static void	two_to_eight(t_couple **couple, int argc)
{
	if (argc == 3)
		two_sort(&(*couple)->a);
	else if (argc == 4)
		three_sort(&(*couple)->a);
	else if (argc == 5)
		four_sort(couple);
	else if (argc == 6)
		five_sort(couple);
	else if (argc == 7)
		six_sort(couple);
	else if (argc == 8)
		seven_sort(couple);
	else if (argc == 9)
		eight_sort(couple);
}

int	main(int argc, char *argv[])
{
	t_node		*head_a;
	t_node		*head_b;
	t_couple	*couple;
	int			*new_argv;

	head_a = NULL;
	head_b = NULL;
	couple = NULL;
	if (argc <= 2)
	{
		check_chars(argv);
		check_dec_limits(argv);
		check_sign_symbols(argv);
		exit (0);
	}
	check_all(argv);
	new_argv = convert_argv(argv, argc);
	couple = init_stacks(new_argv, head_a, head_b, argc);
	if (argc >= 3 && argc <= 9)
		two_to_eight(&couple, argc);
	else
		radix_sort(&couple);
	free_all(&couple);
	exit (0);
	return (0);
}
