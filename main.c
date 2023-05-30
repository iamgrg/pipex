/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:09:53 by gansard           #+#    #+#             */
/*   Updated: 2023/03/16 17:57:34 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check(t_data *data, char **av)
{
	int	boule;

	boule = 1;
	if (data->infile == -1)
	{
		perror(av[1]);
		boule = 0;
	}
	if (data->outfile == -1)
	{
		perror(av[4]);
		boule = 0;
	}
	if (pipe(data->fd) == -1)
	{
		perror("Error");
		boule = 0;
	}
	return (boule);
}

t_data	*ft_init_data(char **av, char **env)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmds = ft_parse_cmds(av);
	data->paths = ft_parse_env(-1, 0);
	data->infile = open(av[1], O_RDONLY);
	data->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	data->env = env;
	if (!ft_check(data, av) || !data->cmds)
		return (ft_free_all(data), NULL);
	return (data);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac != 5)
		return (ft_printf("Error : Invalid number of args.\n"), 0);
	data = ft_init_data(av, env);
	if (!data)
		return (1);
	data->pid = fork();
	if (data->pid != 0)
		data->pid2 = fork();
	if (data->pid == 0)
		ft_exec(data->infile, data->fd[1], data, data->cmds->cmd1);
	else
	{
		if (!data->pid2)
			ft_exec(data->fd[0], data->outfile, data, data->cmds->cmd2);
	}
	ft_close_all(data);
	waitpid(data->pid, NULL, 0);
	if (data->pid != 0)
		waitpid(data->pid2, NULL, 0);
	ft_free_all(data);
	return (0);
}
