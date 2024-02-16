/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:36:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack)->content;
	mid = (*stack)->next->content;
	bot = (*stack)->next->next->content;
	if (is_sorted(*stack) == true)
		return ;
	else if ((top < mid) && (mid > bot) && (top < bot))
	{
		rra(stack);
		sa(stack);
	}
	else if ((top < mid) && (mid > bot) && (top > bot))
		rra(stack);
	else if ((top > mid) && (mid < bot) && (top < bot))
		sa(stack);
	else if ((top > mid) && (mid < bot) && (top > bot))
		ra(stack);
	else
	{
		ra(stack);
		sa(stack);
	}
}

static void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	int	dist;

	min = find_min_content(*a);
	dist = get_distance_from_min(a, min);
	if (dist <= 2 && dist != 0)
		ra(a);
	if (dist == 2)
		ra(a);
	if (dist == 3)
		rra(a);
	if (is_sorted(*a) == true)
		return ;
	pb(a, b);
	sort_three(a);
	pa(b, a);
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	dist;

	min = find_min_content(*a);
	dist = get_distance_from_min(a, min);
	if (is_sorted(*a) == true)
		return ;
	if (dist <= 2 && dist != 0)
		ra(a);
	if (dist == 2)
		ra(a);
	if (dist == 3 || dist == 4)
		rra(a);
	if (dist == 3)
		rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(b, a);
}

void	sort_mini(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
