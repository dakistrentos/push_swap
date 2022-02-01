/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 16:26:34 by Vtrentos      #+#    #+#                 */
/*   Updated: 2022/01/25 16:50:12 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_node
{
	long long		num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_couple
{
	t_node	*a;
	t_node	*b;
}	t_couple;

void		init_head(t_node *head);
t_couple	*init_stacks(
				int *new_argv, t_node *head_a, t_node *head_b, int argc);
void		check_all(char **argv);
void		add_to_head(t_node **head, int num);
void		add_to_tail(t_node **head, int num);
void		remove_from_head(t_node **head);
void		push_b(t_couple **couple);
void		push_a(t_couple **couple);
void		rotate(t_node **head, char stack);
void		rev_rotate(t_node **head, char stack);
void		swap(t_node **head, char stack);
int			find_max_digits(t_node *head);
void		radix_sort(t_couple **couple);
int			find_num_digits(long long num);
int			stack_size(t_node *head);
void		print_stack(t_node *head);
void		check_chars(char **argv);
void		check_dup(char **argv);
void		check_if_sorted(char **argv);
int			is_empty(t_node *head);
void		check_dec_limits(char **argv);
int			find_min(t_node **head);
int			find_max(t_node **head);
void		two_sort(t_node **head);
void		three_sort(t_node **head);
void		four_sort(t_couple **couple);
void		five_sort(t_couple **couple);
void		six_sort(t_couple **couple);
void		seven_sort(t_couple **couple);
void		eight_sort(t_couple **couple);
void		free_all(t_couple **couple);
int			s_util_count_pos(t_node **head, int num);
int			*convert_argv(char **argv, int argc);
void		check_sign_symbols(char **argv);

#endif
