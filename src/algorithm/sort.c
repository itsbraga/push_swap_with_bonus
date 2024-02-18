/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:35:15 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/18 15:33:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Compares the top elem of A with the minimum elem of B. If the top
*	elem of A is smaller than the minimum of B, it performs a reverse
*	rotation on B. Then, it pushes the top elem of A onto B. This process
*	continues until the size of A is reduced to 5.
*/
static void	way2three(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	while (size_a > 3)
	{
		pb(a, b);
		size_a--;
	}
}

/*	Once most of the stack is sorted, A is rotated until the lowest value
*	is at the top. If it is in the bottom half of the stack, we reverse
*	rotate it to get it into position, otherwise we rotate it until it is
*	at the top of A.
*/
static void	final_rotate(t_stack **a)
{
	int	size;
	int	lowest_idx;
	int	median;

	size = stack_size(*a);
	lowest_idx = get_lowest_idx(a);
	median = (size / 2);
	if (lowest_idx > median)
	{
		while (lowest_idx < size)
		{
			rra(a);
			lowest_idx++;
		}
	}
	else
	{
		while (lowest_idx > 0)
		{
			ra(a);
			lowest_idx--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	way2three(a, b);
	sort_mini(a);
	while (*b)
	{
		get_target_idx(b, a);
		get_cost2move(a, b);
		best_cost_move(a, b);
	}
	if (!is_sorted(*a))
		final_rotate(a);
}
