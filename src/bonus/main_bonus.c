/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:14 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/03/27 01:30:08 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"
#include <errno.h>

void	ft_heredoc(t_gnrl **pidfd, char *limiter)
{
	char	*line;

	(*pidfd)->fdw[0] = open(".tmp.txt", O_CREAT | O_RDWR | O_TRUNC, 420);
	if ((*pidfd)->fdw[0] < 0 || (*pidfd)->fdw[0] > OPEN_MAX)
		return ;
	line = get_next_line(0);
	while (ft_strcmp(line, limiter))
	{
		ft_putstr_fd(line, (*pidfd)->fdw[0]);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close((*pidfd)->fdw[0]);
	(*pidfd)->fdw[0] = open(".tmp.txt", O_RDONLY);
}

void	ft_begin(int *argc, char ***argv, t_gnrl	*pidfd)
{
	if ((*argc) < 5)
		ft_errors(-4, "", NULL);
	pidfd->fdw[0] = -1;
	pidfd->fdw[1] = -1;
	if (ft_strcmp((*argv)[1], "here_doc"))
	{
		pidfd->fdw[0] = open((*argv)[1], O_RDONLY);
		pidfd->fdw[1] = open((*argv)[(*argc) - 1], 0100 | 0200 | 01, 420);
	}
	else
	{
		ft_heredoc(&pidfd, (*argv)[2]);
		pidfd->fdw[1] = open((*argv)++[(*argc)-- - 1], 0100 | 0200 | 01, 420);
	}
	if (pidfd->fdw[0] < 0 || pidfd->fdw[0] > OPEN_MAX)
	{
		ft_errors(-2, (*argv)[1], NULL);
		ft_close(pidfd->fdw[0]);
		pidfd->fdw[0] = open("/dev/null", O_RDONLY);
	}
	if (pidfd->fdw[1] < 0 || pidfd->fdw[1] > OPEN_MAX)
	{
		ft_close(pidfd->fdw[0]);
		ft_errors(-2, (*argv)[(*argc) - 1], NULL);
	}
}

void	ft_end(t_gnrl pidfd, t_cmd *cmd, int j)
{
	int	i;

	i = 0;
	while (i <= j)
		waitpid(pidfd.pid[i++], NULL, 0);
	ft_close(pidfd.fd[0]);
	ft_close(pidfd.fd[1]);
	ft_close(pidfd.fdw[0]);
	ft_close(pidfd.fdw[1]);
	free(pidfd.pid);
	ft_lstclear(&cmd, &ft_freetab);
	unlink(".tmp.txt");
	exit(0);
}

void	ft_idk(t_gnrl pidfd, t_cmd **cmd, int *i)
{
	*i = 0;
	dup2(pidfd.fdw[0], 0);
	while ((*cmd)->next)
	{
		pipe(pidfd.fd);
		pidfd.pid[*i] = fork();
		if (pidfd.pid[*i] < 0)
			ft_errors(-1, (*cmd)->cmd[0], *cmd);
		if (pidfd.pid[*i] == 0)
		{
			ft_close(pidfd.fd[0]);
			dup2(pidfd.fd[1], 1);
			execve((*cmd)->path, (*cmd)->cmd, NULL);
			ft_errors(-3, (*cmd)->cmd[0], *cmd);
		}
		else
		{
			ft_close(pidfd.fd[1]);
			dup2(pidfd.fd[0], 0);
			ft_close(pidfd.fd[0]);
		}
		(*cmd) = (*cmd)->next;
		(*i)++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_cmd	*fcmd;
	t_gnrl	pidfd;
	int		i;

	errno = 0;
	cmd = NULL;
	pidfd.fd[0] = -1;
	pidfd.fd[1] = -1;
	ft_begin(&argc, &argv, &pidfd);
	ft_parse(argc, argv, &cmd, env);
	fcmd = cmd;
	pidfd.pid = (int *)malloc(sizeof(int) * ft_lstsize(cmd) + 1);
	if (!pidfd.pid)
		return (-1);
	ft_idk(pidfd, &cmd, &i);
	pidfd.pid[i] = fork();
	if (pidfd.pid[i] == 0)
	{
		ft_close(pidfd.fd[0]);
		dup2(pidfd.fdw[1], 1);
		execve(cmd->path, cmd->cmd, NULL);
		ft_errors(-3, cmd->cmd[0], cmd);
	}
	ft_end(pidfd, fcmd, i);
}
