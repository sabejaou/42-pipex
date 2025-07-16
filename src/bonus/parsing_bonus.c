/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:19 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/03/27 00:47:30 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_freetab(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	ft_parse(int argc, char **argv, t_cmd **fcmd, char **env)
{
	t_cmd	*tmp;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		ft_lstadd_back(fcmd, ft_lstnew(ft_split(argv[i], ' '), i));
		i++;
	}
	tmp = *fcmd;
	while (tmp)
	{
		if (tmp->cmd[0])
			tmp->path = pathcmd(env, tmp->cmd[0]);
		else
			tmp->path = NULL;
		tmp = tmp->next;
	}
}
