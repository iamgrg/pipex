/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:56:50 by gansard           #+#    #+#             */
/*   Updated: 2023/03/15 18:26:19 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_cmds
{
	char	**cmd1;
	char	**cmd2;
}			t_cmds;

typedef struct s_data
{
	t_cmds	*cmds;
	char	**paths;
	char	**env;
	int		fd[2];
	int		pid;
	int		pid2;
	int		infile;
	int		outfile;
}			t_data;
void		ft_close_all(t_data *data);
t_cmds		*ft_parse_cmds(char **tab);
void		ft_free_paths(char **paths);
char		**ft_parse_env(int i, int j);
void		ft_free_cmds(t_cmds *cmds);
int			ft_trigger(t_data *data, char **cmd);
void		ft_free_all(t_data *data);
int			ft_exec(int in, int out, t_data *data, char **cmd);
#endif