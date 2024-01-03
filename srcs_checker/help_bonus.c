/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 13:15:09 by fde-carv          #+#    #+#             */
/*   Updated: 2023/07/24 13:52:00 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		str_1++;
		str_2++;
	}
	return (*str_1 - *str_2);
}

void	parse_command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (command == NULL)
	{
		free (command);
		return ;
	}
	if (!ft_strcmp(command, "pa\n") || !ft_strcmp(command, "pb\n")
		|| !ft_strcmp(command, "sa\n") || !ft_strcmp(command, "sb\n")
		|| !ft_strcmp(command, "ss\n") || !ft_strcmp(command, "ra\n")
		|| !ft_strcmp(command, "rb\n") || !ft_strcmp(command, "rr\n")
		|| !ft_strcmp(command, "rra\n") || !ft_strcmp(command, "rrb\n")
		|| !ft_strcmp(command, "rrr\n"))
		execute_valid_command(a, b, command);
	else
		invalid_command(a, b, command);
}

void	execute_valid_command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, true);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a, true);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, true);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, true);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, true);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, true);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, true);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, true);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, true);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, true);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, true);
}

void	invalid_command(t_stack_node **a, t_stack_node **b, char *command)
{
	free(command);
	error(a, b);
}
