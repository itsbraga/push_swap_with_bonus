/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:09:22 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/15 03:38:17 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		do_swap(a);
	else if (!ft_strcmp(move, "sb\n"))
		do_swap(b);
	else if (!ft_strcmp(move, "ss\n"))
	{
		do_swap(a);
		do_swap(b);
	}
}

static void	rotate(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "ra\n"))
		do_rotate(a);
	else if (!ft_strcmp(move, "rb\n"))
		do_rotate(b);
	else if (!ft_strcmp(move, "rr\n"))
	{
		do_rotate(a);
		do_rotate(b);
	}
}

static void	reverse_rotate(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "rra\n"))
		do_reverse_rotate(a);
	else if (!ft_strcmp(move, "rrb\n"))
		do_reverse_rotate(b);
	else if (!ft_strcmp(move, "rrr\n"))
	{
		do_reverse_rotate(a);
		do_reverse_rotate(b);
	}
}

static void	push(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "pa\n"))
		do_push(b, a);
	else if (!ft_strcmp(move, "pb\n"))
		do_push(a, b);
}

int	do_op(t_stack **a, t_stack **b, char *move)
{
	if (!move)
		return (EXIT_FAILURE);
	if (!ft_strcmp(move, "sa\n") || !ft_strcmp(move, "sb\n")
		|| !ft_strcmp(move, "ss\n"))
		swap(a, b, move);
	else if (!ft_strcmp(move, "ra\n") || !ft_strcmp(move, "rb\n")
		|| !ft_strcmp(move, "rr\n"))
		rotate(a, b, move);
	else if (!ft_strcmp(move, "rra\n") || !ft_strcmp(move, "rrb\n")
		|| !ft_strcmp(move, "rrr\n"))
		reverse_rotate(a, b, move);
	else if (!ft_strcmp(move, "pa\n") || !ft_strcmp(move, "pb\n"))
		push(a, b, move);
	else
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
