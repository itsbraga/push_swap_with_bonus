/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:31:21 by annabrag          #+#    #+#             */
/*   Updated: 2024/01/17 19:27:54 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen2(char *str);
int	base_check(char *base);
int	i_belong2base(char c, char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_len_nbr(int nbr, char *base)
{
	int		len_b;
	int		len_nbr;

	len_b = ft_strlen2(base);
	len_nbr = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		len_nbr++;
	}
	while (nbr > 0)
	{
		nbr = nbr / len_b;
		len_nbr++;
	}
	len_nbr = len_nbr + 1;
	return (len_nbr);
}

void	ft_putnbr_base2(int nbr, char *base_to, char *str)
{
	int		len_b;
	int		j;

	len_b = ft_strlen2(base_to);
	j = ft_len_nbr(nbr, base_to);
	str[--j] = '\0';
	if (nbr == 0)
		str[0] = base_to[0];
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		str[--j] = base_to[nbr % len_b];
		nbr = nbr / len_b;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		len_finale;
	int		post_atoi;

	str = NULL;
	if (base_check(base_from) == 0 || base_check(base_to) == 0)
		return (NULL);
	post_atoi = ft_atoi_base(nbr, base_from);
	len_finale = ft_len_nbr(post_atoi, base_to);
	str = malloc(sizeof(char) * (len_finale + 1));
	if (!str)
		return (NULL);
	ft_putnbr_base2(post_atoi, base_to, str);
	str[len_finale] = '\0';
	return (str);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	}
	else
		return (0);
}*/
