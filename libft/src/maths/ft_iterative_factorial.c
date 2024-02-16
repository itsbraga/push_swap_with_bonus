/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:02:36 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/15 12:35:32 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;
	int	i;

	fact = 1;
	if (nb < 0)
		return (0);
	i = 1;
	while (i <= nb)
	{
		fact *= i;
		i++;
	}
	return (fact);
}

/*#include <stdio.h>

int	main()
{
	int	n;

	n = 5;
	printf("Le factoriel de %d est : %d\n", n, ft_iterative_factorial(n));
}*/
