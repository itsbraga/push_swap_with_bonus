/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:33:22 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_idx(t_stack **stack)
{
	t_stack		*tmp;
	int			i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->idx = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_pos(t_stack **stack)
{
	t_stack		*tmp;
	int			i;

	tmp = find_min(*stack);
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp->idx = -1;
		tmp->target_idx = -1;
		tmp->cost_a = -1;
		tmp->cost_b = -1;
		tmp = find_min(*stack);
		i++;
	}
}

int	get_lowest_idx(t_stack **stack)
{
	t_stack		*tmp;
	int			idx;

	tmp = *stack;
	idx = 0;
	while (tmp->pos != 0)
	{
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}

/*	Picks the best target position in stack A for the given index of
*	an element in stack B. First checks if the index of the B element
*	can be placed somewhere in between elements in stack A, by checking
*	whether there is an element in stack A with a bigger index. If not,
*	it finds the element with the smallest index in A and assigns that
*	as the target position.
*/
static int	get_target(t_stack **a, int b_pos, int target_pos, int target_idx)
{
	t_stack		*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if ((tmp_a->pos > b_pos) && (tmp_a->pos < target_pos))
		{
			target_pos = tmp_a->pos;
			target_idx = tmp_a->idx;
		}
		tmp_a = tmp_a->next;
	}
	if (target_pos != INT_MAX)
		return (target_idx);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->pos < target_pos)
		{
			target_pos = tmp_a->pos;
			target_idx = tmp_a->idx;
		}
		tmp_a = tmp_a->next;
	}
	return (target_idx);
}

void	get_target_idx(t_stack **b, t_stack **a)
{
	t_stack		*tmp_b;
	int			target_idx;

	tmp_b = *b;
	set_idx(a);
	set_idx(b);
	target_idx = 0;
	while (tmp_b)
	{
		target_idx = get_target(a, tmp_b->pos, INT_MAX, target_idx);
		tmp_b->target_idx = target_idx;
		tmp_b = tmp_b->next;
	}
}
