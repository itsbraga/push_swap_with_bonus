/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:24:46 by annabrag          #+#    #+#             */
/*   Updated: 2024/01/17 18:51:10 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_tab(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap_tab(&tab[i], &tab[size - i - 1]);
		i++;
	}
}

/*#include <stdio.h>

int	main()
{
	int	tab[] = {2, 5, 6, 1, 3, 8};

	ft_rev_int_tab(tab, 6);
	printf("%d%d%d%d%d%d", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
}*/
