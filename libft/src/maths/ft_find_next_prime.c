/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:18:09 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/21 23:55:50 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	n;

	n = 2;
	if (nb <= 1)
		return (0);
	while (n <= nb / n)
	{
		if (!(nb % n))
			return (0);
		n++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (nb >= 2)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	printf("%d\n", ft_find_next_prime(4));
	printf("%d", ft_find_next_prime(9));
}*/
