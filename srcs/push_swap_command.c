/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:47:02 by fde-carv          #+#    #+#             */
/*   Updated: 2023/07/13 14:55:18 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Conclude the rotation of the stacks 
void	finish_rotation(t_stack_node **stack,
							t_stack_node *top_node,
							char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

// Move the node from 'b' to 'a' with the metadata available in the node
// 1)Make the target nodes emerge
// 2)push in A

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);
}

static void	get_final_index(t_stack_node *a, int size)
{
	t_stack_node	*temp;
	t_stack_node	*max_address;
	int				max_n;

	while (size--)
	{
		temp = a;
		max_n = INT_MIN;
		max_address = NULL;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->final_index == 0)
				temp->final_index = 1;
			else if (temp->value > max_n && temp->final_index == 0)
			{
				max_n = temp->value;
				max_address = temp;
				temp = a;
			}
			else
				temp = temp->next;
		}
		if (max_address)
			max_address->final_index = size + 1;
	}
}

static void	push_b_save_3(t_stack_node **a, t_stack_node **b, int size)
{
	int		pushed;
	int		i;

	pushed = 0;
	i = 0;
	get_final_index(*a, size);
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->final_index <= size / 2)
		{
			pb(b, a, false);
			pushed++;
		}
		else
			ra(a, false);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(b, a, false);
		pushed++;
	}
}

// ~Push all nodes in B ~For every configuration choose the "cheapest_node"
// ~Push everything back in A in order
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	else
		push_b_save_3(a, b, len_a);
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
