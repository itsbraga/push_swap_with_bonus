/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:07:11 by panther           #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  Find the elem with the smallest content. */
t_stack	*find_min(t_stack *node)
{
	int		tmp;
	int		min;
	t_stack	*min_node;

	if (!node)
		return (NULL);
	tmp = 0;
	min = INT_MAX;
	min_node = NULL;
	while (node)
	{
		if ((node->pos == -1) && (!tmp || node->content < min))
		{
			min = node->content;
			min_node = node;
			tmp = 1;
		}
		node = node->next;
	}
	return (min_node);
}

int	find_min_content(t_stack *node)
{
	int	min;

	if (!node)
		return (0);
	min = node->content;
	while (node)
	{
		if (min > node->content)
			min = node->content;
		node = node->next;
	}
	return (min);
}

/*	A is scanned until a minimum value (min) is found and calculates
*	the distance of that elem from the top of the stack.
*/
int	get_distance_from_min(t_stack **a, int min)
{
	t_stack	*tmp;
	int		dist;

	if (!a)
		return (0);
	tmp = *a;
	dist = 0;
	while (tmp)
	{
		if (tmp->content == min)
			break ;
		dist++;
		tmp = tmp->next;
	}
	return (dist);
}
