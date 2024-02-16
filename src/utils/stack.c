/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:04:08 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int number)
{
	t_stack		*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = number;
	new->pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*get_last(t_stack *node)
{
	t_stack		*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*get_before_last(t_stack *node)
{
	t_stack		*tmp;

	if (!node)
		return (NULL);
	tmp = node;
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

void	add2bottom(t_stack **stack, t_stack *new)
{
	t_stack		*tmp;

	if (*stack)
	{
		tmp = get_last(*stack);
		tmp->next = new;
	}
	else
		*stack = new;
}

int	stack_size(t_stack *node)
{
	int	size;

	if (!node)
		return (0);
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
