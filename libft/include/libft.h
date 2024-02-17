/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:44:52 by annabrag          #+#    #+#             */
/*   Updated: 2024/02/17 01:54:15 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "colors.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// MANDATORY and BONUS functions
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strisnum(char *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr_color_fd(char *color, char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				iam_a_space(char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char *s, char *charset);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				display_list(t_list *lst);

// POOL functions
int					base_check(char *base);
int					i_belong2base(char c, char *base);
int					ft_atoi_base(char *str, char *base);
int					ft_len_nbr(int nbr, char *base);
void				ft_putnbr_base2(int nbr, char *base_to, char *str);
void				ft_putnbr_base(int nbr, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);

void				ft_rev_params(int argc, char **argv);

int					ft_strcmp(char *s1, char *s2);
char				*ft_strcapitalize(char *str);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, unsigned int nb);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
char				*ft_strstr(char *str, char *to_find);
void				ft_swap(char **a, char **b);

void				ft_print_comb(void);
void				ft_print_comb2(void);
void				ft_swap_tab(int *a, int *b);
;
void				ft_rev_int_tab(int *tab, int size);
void				ft_sort_int_tab(int *tab, int size);
int					*ft_range(int min, int max);
int					ft_ultimate_range(int **range, int min, int max);

int					ft_iterative_factorial(int nb);
int					ft_recursive_factorial(int nb);
int					ft_iterative_power(int nb, int power);
int					ft_recursive_power(int nb, int power);
int					ft_is_prime(int nb);
int					ft_find_next_prime(int nb);
int					ft_sqrt(int nb);
int					ft_fibonacci(int index);

int					*ft_map(int *tab, int length, int (*f)(int));
void				ft_foreach(int *tab, int length, void (*f)(int));

#endif
