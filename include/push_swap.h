/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:26:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/02/18 15:33:49 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/************************************************************************/
/*									*/
/*				LIBRARIES				*/
/*									*/
/************************************************************************/

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

/************************************************************************/
/*									*/
/*				REDEFINITIONS				*/
/*									*/
/************************************************************************/

// typedef enum Bool
// {
// 	false,
// 	true
// }		bool;

// idx est la ou est situe la valeur dans la stack
// pos est la ou doit etre situee la valeur apres le tri
typedef struct s_stack
{
	int				content;
	int				idx;
	int				pos;
	int				target_idx;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/************************************************************************/
/*									*/
/*				INSTRUCTIONS				*/
/*									*/
/************************************************************************/

void		do_swap(t_stack **stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

void		do_rotate(t_stack **stack);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

void		do_reverse_rotate(t_stack **stack);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

void		do_push(t_stack **from, t_stack **to);
void		pa(t_stack **from_b, t_stack **to_a);
void		pb(t_stack **from_a, t_stack **to_b);

/************************************************************************/
/*									*/
/*				COSTS AND MOVES				*/
/*									*/
/************************************************************************/

void		get_cost2move(t_stack **a, t_stack **b);
void		best_cost_move(t_stack **a, t_stack **b);
void		exec_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/************************************************************************/
/*									*/
/*				ALGORITHM				*/
/*									*/
/************************************************************************/

void		sort_mini(t_stack **a);
void		sort(t_stack **a, t_stack **b);
bool		is_sorted(t_stack *node);

/************************************************************************/
/*									*/
/*				SORT FUNCTION				*/
/*									*/
/************************************************************************/

void		push_swap(t_stack **a, t_stack **b);

/************************************************************************/
/*									*/
/*				STACK HANDLER				*/
/*									*/
/************************************************************************/

t_stack		*stack_new(int number);
t_stack		*get_last(t_stack *node);
t_stack		*get_before_last(t_stack *node);
void		add2bottom(t_stack **stack, t_stack *new);
int			stack_size(t_stack *node);

/************************************************************************/
/*									*/
/*			PROTECTION FUNCTIONS				*/
/*									*/
/************************************************************************/

void		clear_stack(t_stack **stack);
int			exit_error_stack(t_stack **a, t_stack **b, int argc, char **argv);
void		free_split(int argc, char **argv);

/************************************************************************/
/*									*/
/*				UTIL FUNCTIONS				*/
/*									*/
/************************************************************************/

t_stack		*find_min(t_stack *node);
void		set_idx(t_stack **stack);
void		set_pos(t_stack **stack);
int			get_lowest_idx(t_stack **stack);
void		get_target_idx(t_stack **b, t_stack **a);
void		show_stack(t_stack *node, char c);

/************************************************************************/
/*									*/
/*			PARSING AND INITIALIZATION			*/
/*									*/
/************************************************************************/

bool		is_sign(char c);
int			nb_strcmp(const char *s1, const char *s2);
void		check_doubles(t_stack *a, int argc, char **argv);

int			have_zeros(char *str);
bool		global_check_successful(char **argv);
int			split_case(char **argv, t_stack *a);
t_stack		*convert_n_fill_stack(int argc, char **argv);

/************************************************************************/
/*									*/
/*				BONUS					*/
/*									*/
/************************************************************************/

int			do_op(t_stack **a, t_stack **b, char *move);

#endif