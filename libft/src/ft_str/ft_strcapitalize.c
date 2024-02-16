/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:54:54 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/09 20:57:36 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alphanumeric(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_alphanumeric(str[i]))
		{
			if (str[i] >= 97 && str[i] <= 122)
				str[i] -= 32;
			i++;
		}
		while (ft_is_alphanumeric(str[i]))
		{
			if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
			i++;
		}
		i++;
	}
	return (str);
}
