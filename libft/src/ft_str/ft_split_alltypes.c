/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_alltypes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:29:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/08 21:46:00 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	word_len(char const *s)
{
	int	len;

	len = 0;
	while (*s && *s != iam_a_space(*s))
	{
		len++;
		s++;
	}
	return (len);
}

static int	word_count(char const *s)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s != iam_a_space(*s))
		{
			counter++;
			s += word_len(s);
		}
		else
			s++;
	}
	return (counter);
}

static void	*free_f(char **split, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
	return (NULL);
}

static char	*ft_strdup2(char const *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != iam_a_space(*s))
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split_alltypes(char const *s)
{
	char	**split;
	int		i;
	int		counter;

	if (!s)
		return (NULL);
	counter = word_count(s);
	split = malloc(sizeof(char *) * (counter + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != iam_a_space(*s))
		{
			split[i] = ft_strdup2(s);
			if (!split[i++])
				return (free_f(split, i));
			s += word_len(s);
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**split = NULL;

	i = 0;
	if (argc < 3)
		return (0);
	split = ft_split_alltypes(argv[1]);
	if (!split)
		return (0);
	while (i < word_count(argv[1]))
	{
		printf("%s\n", split[i++]);
		free(split[i++]);
	}
	free(split);
}