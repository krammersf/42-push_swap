/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:42:38 by fde-carv          #+#    #+#             */
/*   Updated: 2023/07/13 14:55:11 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// atol, i need it to check eventual overflows converting every string
// into a long value
static long	ft_atol(const char *str)
{
	long	res;
	int		sinal;
	int		i;

	res = 0;
	sinal = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal = -1 * sinal;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sinal);
}

// Create the stack with the command line values
// Checks are embedded in the creation itslef
// ~Duplicate values ~Over|Underflow ~Syntax errors
// Flag is useful cause if true, i have the av in the HEAP to free
void	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag_ac_2);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag_ac_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag_ac_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag_ac_2)
		free_matrix(av);
}

// Cahnge push_swap_command.c
// Loop decays once ~cheapest_node tops is a
//                  ~relative target_node tops in b
void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
		&& *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}
