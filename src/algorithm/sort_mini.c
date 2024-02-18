/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:36:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/18 15:33:30 by annabrag         ###   ########.fr       */
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

void	sort_mini(t_stack **a)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
}
