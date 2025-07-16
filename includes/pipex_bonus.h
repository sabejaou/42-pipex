/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:37:59 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/03/27 01:28:19 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/*
 ERR CODES : 
	PIPE : -1
	FORK : -2
	DUP  : -3
	FD	 : -4
*/
# include "../libft/libft.h"
/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <limits.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

typedef struct s_gnrl
{
	int		*pid;
	int		fd[2];
	int		fda[2];
	int		fdw[2];
}	t_gnrl;

// parse.c
void	ft_parse(int argc, char **argv, t_cmd **fcmd, char **env);
void	ft_close(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_errors(int errcd, char *cmd, t_cmd *cmdq);

// pathing.c
char	*pathcmd(char **env, char *cmd);

// main.c
void	ft_freetab(char **cmd);

// get_next_line.c
char	*get_next_line(int fd);

#endif