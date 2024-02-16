/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:31:20 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/15 08:09:48 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	n_abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

/*	Calculates the cost of moving each elem of stack B into the correct
*	position in stack A.
*	
*	cost_b represents the cost of getting the elem to the top of the B stack
*	cost_a represents the cost of getting to the right position in stack A.
*
*	If the elem is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive.
*/
void	get_cost2move(t_stack **a, t_stack **b)
{
	t_stack		*tmp_b;
	int			size_a;
	int			size_b;
	int			median_a;
	int			median_b;

	tmp_b = *b;
	size_a = stack_size(*a);
	size_b = stack_size(tmp_b);
	median_a = size_a / 2;
	median_b = size_b / 2;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->idx;
		if (tmp_b->idx > median_b)
			tmp_b->cost_b = (size_b - tmp_b->idx) * -1;
		tmp_b->cost_a = tmp_b->target_idx;
		if (tmp_b->target_idx > median_a)
			tmp_b->cost_a = (size_a - tmp_b->target_idx) * -1;
		tmp_b = tmp_b->next;
	}
}

void	best_cost_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		best_cost;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	best_cost = INT_MAX;
	while (tmp)
	{
		if (n_abs(tmp->cost_a) + n_abs(tmp->cost_b) < n_abs(best_cost))
		{
			best_cost = n_abs(tmp->cost_a) + n_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	exec_move(a, b, cost_a, cost_b);
}
