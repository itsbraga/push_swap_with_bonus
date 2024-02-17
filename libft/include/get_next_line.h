/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:40:54 by panther           #+#    #+#             */
/*   Updated: 2024/02/16 20:55:30 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include "colors.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

/*
** Le descripteur de fichier va de 0 à OPEN_MAX (défini dans <limits.h>)
** La valeur maximale du descripteur de fichier peut être obtenue avec :
**
** Mac : launchctl limit maxfiles
** Linux : ulimit -n 
*/

size_t	ft_strlen_gnl(char *s);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *line, char *buffer);
char	*extract_line(char *line);
char	*update_line(char *line);
char	*use_read_on_line(int fd, char *line);

char	*get_next_line(int fd, bool tofree);

#endif
