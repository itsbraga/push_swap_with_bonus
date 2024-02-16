/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:11:45 by annabrag          #+#    #+#             */
/*   Updated: 2023/03/02 17:00:05 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;
	int	*array;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = malloc(sizeof(int) * (size));
	if (!array)
		return (-1);
	i = 0;
	*range = array;
	while (i < size)
	{
		array[i] = min + i;
		i++;
	}
	return (size);
}

/*#include <stdio.h>

int main()
{
	int	*range[10];
	int	min = 5;
	int	max = 10;

	printf("%d\n", ft_ultimate_range(range, min, max));
}*/
