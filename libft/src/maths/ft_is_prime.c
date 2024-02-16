/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:51:51 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/21 23:06:00 by annabrag         ###   ########.fr       */
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

/*#include <stdio.h>

int	main()
{
	printf("%d\n", ft_is_prime(-2147483648));
	printf("%d", ft_is_prime(2147483647));
}*/
