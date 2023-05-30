/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:42:10 by gansard           #+#    #+#             */
/*   Updated: 2023/03/16 17:56:37 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec(int in, int out, t_data *data, char **cmd)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	ft_close_all(data);
	if (ft_trigger(data, cmd) == -1)
		return (perror(cmd[0]), 0);
	return (0);
}

char	*ft_get_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		if (!access(cmd, X_OK))
			return (cmd);
		tmp = ft_strjoin(path[i], cmd);
		if (!access(tmp, X_OK))
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

int	ft_trigger(t_data *data, char **cmd)
{
	int		i;
	char	*path;

	path = NULL;
	if (!cmd[0])
		return (ft_error(2, NULL), 0);
	if (data->paths)
		path = ft_get_path(data->paths, cmd[0]);
	else
	{
		if (!access(cmd[0], X_OK))
			path = cmd[0];
	}
	if (!path)
		return (ft_error(1, cmd[0]), 0);
	return (execve(path, cmd, data->env));
}
