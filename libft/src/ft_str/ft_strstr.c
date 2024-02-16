/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:01:10 by annabrag          #+#    #+#             */
/*   Updated: 2023/02/20 14:04:44 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
		{
			j++;
			if (to_find[j] == '\0')
				return (str + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	char	str[]="Je prefere la soupe au McDo";
	char	to_find[]="soupe";
	char	str2[]="Je prefere le McDo aux soupes";
	char	to_find2[]="";

	printf("%s\n", ft_strstr(str, to_find));
	printf("%s\n", ft_strstr(str2, to_find2));
}*/
