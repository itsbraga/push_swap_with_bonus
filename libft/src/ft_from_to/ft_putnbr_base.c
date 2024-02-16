/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:43:51 by annabrag          #+#    #+#             */
/*   Updated: 2024/01/17 18:35:18 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen2(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		len_b;

	n = nbr;
	len_b = ft_strlen2(base);
	if (base_check(base) == 1)
	{
		if (n < 0)
		{
			n = -n;
			ft_putchar('-');
		}
		if (n < len_b)
			ft_putchar(base[n]);
		if (n >= len_b)
		{
			ft_putnbr_base(n / len_b, base);
			ft_putchar(base[n % len_b]);
		}
	}
}

/*#include <stdio.h>

int	main()
{
	ft_putnbr_base(74, "01234567");
	ft_putchar('\n');
	ft_putnbr_base(1000, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(1, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(-1, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(0, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(9, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(2147483647, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(-9867000, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(42, "12 3 2435");
	ft_putchar('\n');
	ft_putnbr_base(42, " ");
	ft_putchar('\n');
	ft_putnbr_base(42, "");
	ft_putchar('\n');
	ft_putnbr_base(42, "dfd	");
	ft_putchar('\n');
	ft_putnbr_base(42, "1234+");
	ft_putchar('\n');
	ft_putnbr_base(42, "dsklfsj-");
	ft_putchar('\n');
	ft_putnbr_base(42, "\ndsf");
	ft_putchar('\n');
	ft_putnbr_base(42, "01");
}*/
