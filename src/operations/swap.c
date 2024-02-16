/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:57:48 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/15 08:10:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_stack **stack)
{
	t_stack		*tmp;

	if (stack_size(*stack) < 2)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

// swap the first two elem at the top of stack_a
void	sa(t_stack **a)
{
	do_swap(a);
	ft_printf("sa\n");
}

// swap the first two elem at the top of stack_b
void	sb(t_stack **b)
{
	do_swap(b);
	ft_printf("sb\n");
}

// swap the first two elem at the top of both stacks
void	ss(t_stack **a, t_stack **b)
{
	do_swap(a);
	do_swap(b);
	ft_printf("ss\n");
}
