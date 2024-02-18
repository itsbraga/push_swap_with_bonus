/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:58:14 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/18 15:30:53 by annabrag         ###   ########.fr       */
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

void	show_stack(t_stack *node, char c)
{
	t_stack			*tmp;
	unsigned int	idx;

	if (!node)
		return ;
	tmp = node;
	idx = 0;
	write(1, "\n", 1);
	while (tmp)
	{
		ft_printf("Stack (%d) ➔	  %d\n", idx++, tmp->content);
		tmp = tmp->next;
	}
	ft_printf("		  —\n");
	ft_printf("		  %c\n\n", c);
}
