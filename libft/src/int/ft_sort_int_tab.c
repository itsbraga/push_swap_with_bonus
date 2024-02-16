/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:41:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/01/17 18:51:35 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_tab(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (&tab[j] < &tab[j + 1])
				ft_swap_tab(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
