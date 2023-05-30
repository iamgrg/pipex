/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:41:52 by gansard           #+#    #+#             */
/*   Updated: 2023/03/16 17:56:42 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int nb, char *cmd)
{
	if (nb == 1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : Command not found\n", 2);
	}
	else if (nb == 2)
		ft_putstr_fd("Error : Command not found.\n", 2);
}

void	ft_close_all(t_data *data)
{
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->infile);
	close(data->outfile);
}

void	ft_free_cmds(t_cmds *cmds)
{
	int	i;

	i = 0;
	if (cmds->cmd1[i])
		free(cmds->cmd1[i++]);
	free(cmds->cmd1[i]);
	free(cmds->cmd1);
	i = 0;
	if (cmds->cmd2[i])
		free(cmds->cmd2[i++]);
	free(cmds->cmd2[i]);
	free(cmds->cmd2);
	if (cmds)
		free(cmds);
}

void	ft_free_paths(char **paths)
{
	int	i;

	i = 0;
	if (paths)
	{
		while (paths[i])
			free(paths[i++]);
	}
	if (paths)
		free(paths);
}

void	ft_free_all(t_data *data)
{
	if (data)
	{
		if (data->cmds)
			ft_free_cmds(data->cmds);
		if (data->paths)
			ft_free_paths(data->paths);
		free(data);
	}
}
