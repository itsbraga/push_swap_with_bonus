/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:59:29 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/23 00:14:37 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	n;

	n = 2;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	if (nb >= 2)
	{
		while ((n * n) <= nb)
		{
			if ((n * n) == nb)
				return (n);
			n++;
		}
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	int	nb;

	nb = 25;
	printf("%d\n", ft_sqrt(nb));
}*/
