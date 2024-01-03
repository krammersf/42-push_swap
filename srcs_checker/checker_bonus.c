/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:47:46 by fde-carv          #+#    #+#             */
/*   Updated: 2023/07/24 14:12:17 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	checker(t_stack_node **a, t_stack_node **b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		parse_command(a, b, command);
		free(command);
		command = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	checker(&a, &b);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&b);
	free_stack(&a);
	return (0);
}
