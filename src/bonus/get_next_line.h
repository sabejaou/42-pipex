/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:41:47 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/01/18 04:15:09 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# define OPEN_MAX 65534

void	ft_gnlbzero(void *s, size_t n);
char	*get_next_line(int fd);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*ft_gnlstrealloc(char *src, int n);
char	*ft_gnlstrcat(char *dest, char *src, int size);
size_t	ft_gnlstrlen(char *str);
int		ft_gnlstrchr(char *str, char to_find);

#endif