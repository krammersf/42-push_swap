/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:29:41 by fde-carv          #+#    #+#             */
/*   Updated: 2023/07/02 11:41:25 by fde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../srcs/push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// GET NEXT LINE
char	*get_next_line(int fd);
size_t	ft_strclen(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strjoin(char *s1, const char *s2);

// CHECKER
void	error(t_stack_node **a, t_stack_node **b);
int		ft_strcmp(char *str_1, char *str_2);
void	parse_command(t_stack_node **a, t_stack_node **b, char *command);
void	execute_valid_command(t_stack_node **a, t_stack_node **b,
			char *command);
void	invalid_command(t_stack_node **a, t_stack_node **b, char *command);
void	checker(t_stack_node **a, t_stack_node **b);
int		ft_strcmp(char *str_1, char *str_2);

#endif
