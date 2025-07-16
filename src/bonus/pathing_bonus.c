/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:21 by sbejaoui          #+#    #+#             */
/*   Updated: 2024/03/27 01:28:07 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	ft_errors(int errcd, char *cmd, t_cmd *cmdq)
{
	if (!cmd)
		cmd = "(null)";
	if (errcd == -1)
		perror(NULL);
	else if (errcd == -2)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : ", 2);
		perror(NULL);
		return ;
	}
	else if (errcd == -3)
	{
		ft_putstr_fd(cmd, 2);
		ft_lstclear(&cmdq, &ft_freetab);
		ft_putstr_fd(" : CMD NOT FOUND\n", 2);
	}
	else if (errcd == -4)
		ft_putstr_fd("ERROR : ARGS INVALID\n", 2);
	exit(errcd);
}

char	*ft_strccpy(const char *src, char c, char *cmd)
{
	size_t	index;
	size_t	longueur;
	char	*str;

	index = 0;
	longueur = 0;
	if (!src || ft_strichr((char *) src, c) < 0)
		return (NULL);
	str = malloc(ft_strichr((char *) src, c) + ft_strlen(cmd) + 2);
	if (!str)
		return (NULL);
	while (src[index] && src[index] != c)
	{
		str[index] = src[index];
		index++;
	}
	str[index++] = '/';
	while (cmd[longueur])
	{
		str[index++] = cmd[longueur++];
	}
	str[index] = '\0';
	return (str);
}

char	*ft_testpath(char *env, char *cmd)
{
	char	*rlpath;
	int		i;

	i = 0;
	rlpath = " ";
	while (rlpath)
	{
		rlpath = ft_strccpy(env, ':', cmd);
		if (access(rlpath, F_OK) == 0)
			return (rlpath);
		else if (rlpath)
			free(rlpath);
		i = ft_strichr(env, ':');
		i++;
		env += i;
	}
	return (NULL);
}

char	*pathcmd(char **env, char *cmd)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			return (ft_testpath(env[i] + 5, cmd));
		i++;
	}
	return (NULL);
}
