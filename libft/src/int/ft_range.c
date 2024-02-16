/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:44:55 by annabrag          #+#    #+#             */
/*   Updated: 2023/03/01 17:15:43 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	tab = NULL;
	i = 0;
	if (min >= max)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min));
	if (!tab)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}

/*#include <stdio.h>

int	main()
{
	int	min = 1;
	int	max = 13;
	int	min2 = 21;
	int	max2 = 21;
	int	min3 = 242;
	int	max3 = 240;

	int *tab = ft_range(min, max);
	int i = 0;
	int j = max - min;
	while (i < j)
	{
		printf("%d\n", tab[i]);
		i++;
	}
	printf("%ls\n", ft_range(min2, max2));
	printf("%ls\n", ft_range(min3, max3));
}*/
