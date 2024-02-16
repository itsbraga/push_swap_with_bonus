/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:01:38 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/20 13:06:27 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0 || index == 1)
		return (index);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

/*#include <stdio.h>

int	main()
{
	printf("%d, ", ft_fibonacci(0));
	printf("%d, ", ft_fibonacci(1));
	printf("%d, ", ft_fibonacci(2));
	printf("%d, ", ft_fibonacci(3));
	printf("%d\n", ft_fibonacci(4));
}*/
