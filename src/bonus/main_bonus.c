/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:03:26 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/06 00:09:25 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_sorted(t_stack *node)
{
	t_stack	*tmp;

	if (!node)
		return (false);
	tmp = node;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static int	checker(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0, false);
		if (!line)
			break ;
		if (do_op(a, b, line) == EXIT_FAILURE)
		{
			get_next_line(0, true);
			free(line);
			return (1);
		}
		free(line);
	}
	get_next_line(0, true);
	return (0);
}

static void	begin_main(int argc, char ***argv)
{
	if (argc < 2)
		exit (EXIT_FAILURE);
	if (argc == 2)
	{
		*argv = ft_split(*argv[1], " \t");
		if (!*argv)
			exit (1);
	}
	else
		(*argv)++;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	begin_main(argc, &argv);
	if (!global_check_successful(argv))
		return (free_split(argc, argv), EXIT_FAILURE);
	a = convert_n_fill_stack(argc, argv);
	if (!a)
		exit_error_stack(&a, NULL, argc, argv);
	b = NULL;
	if (checker(&a, &b))
		return ((clear_stack(&a), clear_stack(&b)), free_split(argc, argv),
			EXIT_FAILURE);
	if (is_sorted(a) && b == NULL)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	(clear_stack(&a), clear_stack(&b), free_split(argc, argv));
	return (EXIT_SUCCESS);
}
