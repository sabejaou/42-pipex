/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:19 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/03/14 19:12:50 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_doubleclose(t_gnrl pidfd, int i)
{
	close(pidfd.fd[i]);
	close(pidfd.fdw[i]);
}

void	ft_parse(int argc, char **argv, t_cmd **fcmd, char **env)
{
	t_cmd	*tmp;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		ft_lstadd_back(fcmd, ft_lstnew(ft_split(argv[i], ' '), 0));
		i++;
	}
	tmp = *fcmd;
	if (tmp->cmd[0])
		tmp->path = pathcmd(env, tmp->cmd[0]);
	else
		tmp->path = NULL;
	if (tmp->next->cmd[0])
		tmp->next->path = pathcmd(env, tmp->next->cmd[0]);
	else
		tmp->next->path = NULL;
}
