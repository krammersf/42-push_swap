/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:57:22 by fde-carv          #+#    #+#             */
/*   Updated: 2023/07/13 14:55:21 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// i starts from -1 
void	free_matrix(char **av)
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

// Matrix starts from -1 because i artificially made Up equal to av
void	error_free(t_stack_node **a, char **av, bool flag_ac_2)
{
	free_stack(a);
	if (flag_ac_2)
		free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);
}

// Check if there are some syntactical mistakes
int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

// Loop into the stack for value repetition
int	error_repetition(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
