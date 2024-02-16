/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:58:14 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
