/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 20:21:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Rotates both A and B until one of them is in position.
 *	The given cost is positive since both positions are in the top
 *	half of their respective stacks. The cost is decreased as the
 *	stacks are rotated, when one reaches 0, the stack has been rotated
 *	as far as possible and the top position is correct.
 */
static void	do_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

/*	Reverse rotates both A and B until one of them is in position.
 *	The given cost is negative since both positions are in the bottom
 *	half of their respective stacks. The cost is increased as the stacks
 *	are rotated, when one reaches 0, the stack has been rotated as far as
 *	possible and the top position is correct.
 */
static void	do_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

/*	Rotates A until it is in position. If the cost positive,
 *	it will be rotated. Otherwise, the stack will be reverse
 *	rotated.
 */
static void	do_ra(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/*	Rotates B until it is in position. If the cost positive,
 *	it will be rotated. Otherwise, the stack will be reverse
 *	rotated.
 */
static void	do_rb(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/*	Chooses which move to make to get the B stack elem to the correct
 *	position in A.
 *	If the costs of moving A and B into position match, both will be
 *	rotated or reverse rotated at the same time. They might also be
 *	rotated separately, before finally pushing the top B elem to the
 *	top of A.
 */
void	exec_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr(a, b, &cost_a, &cost_b);
	do_ra(a, &cost_a);
	do_rb(b, &cost_b);
	pa(b, a);
}
