/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:30:10 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/20 14:05:34 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (nb == 0 && power == 0)
		return (1);
	if (power < 0)
		return (0);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

/*#include <stdio.h>

int	main()
{
	int	nb;
	int	power;

	nb = 2;
	power = 6;
	printf("%d\n", ft_recursive_power(nb, power));
}*/
