/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:09:56 by gansard           #+#    #+#             */
/*   Updated: 2023/03/15 17:23:06 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmds	*ft_parse_cmds(char **tab)
{
	t_cmds	*cmds;

	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (0);
	cmds->cmd1 = ft_split(tab[2], ' ');
	cmds->cmd2 = ft_split(tab[3], ' ');
	if (!cmds->cmd1 || !cmds->cmd2)
		return (ft_free_cmds(cmds), NULL);
	return (cmds);
}

char	**ft_parse_env(int i, int j)
{
	char	**temp;
	char	**paths;

	if (!getenv("PATH"))
		return (NULL);
	temp = ft_split(getenv("PATH"), ':');
	if (!temp)
		return (NULL);
	i = -1;
	while (temp[++i])
		;
	paths = malloc(sizeof(char *) * (i + 1));
	if (!paths)
		return (NULL);
	j = 0;
	while (j < i)
	{
		paths[j] = ft_strjoin(temp[j], "/");
		if (!paths[j])
			ft_free_paths(paths);
		j++;
	}
	paths[i] = NULL;
	ft_free_paths(temp);
	return (paths);
}
