/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:21:32 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/18 20:41:49 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_data *data)
{
	char	*cmd_path;
	char	**cmd1;
	if (data->flag_HD == 1)
	{
		if_heredoc(data);
		dup_and_close(data->pipeHD[0], 0);
		dup_and_close(data->pipe_fd[1], 1);
	}
	else
	{
		dup_and_close(data->fd_in, 0);
		dup_and_close(data->pipe_fd[1], 1);
	}
	cmd1 = ft_split(data->av[data->i], ' ');
	cmd_path = find_path(data);
	if (!(cmd1 || cmd1))
		ft_error("Split or path first");
	if (execve(cmd_path, cmd1, data->envp) < 0)
	{
		// ft_freetab(data);
		free(cmd_path);
		ft_error("Execve first");
	}
}
void	crea_child(t_data *data)
{
	char	**cmdn;
	char	*cmd_path;
	dup_and_close(*data->fdtemp, 0);
	dup_and_close(data->pipe_fd[1], 1);
	cmdn = ft_split(data->av[data->i], ' ');
	cmd_path = find_path(data);
	if(!(cmdn || cmd_path))
		ft_error("split or path");
	if (execve(cmd_path, cmdn, data->envp) < 0)
	{
		// ft_freetab(data);
		free(cmd_path);
		ft_error("Execve");
	}
}
void	last_child(t_data *data)
{
	char	**last_cmd;
	char	*cmd_path;
	// printf ("next[%d]\n", *data->fdtemp);
	dup_and_close(*data->fdtemp, 0);
	dup_and_close(data->fd_out, 1);
	last_cmd = ft_split(data->av[data->ac - 2], ' ');
	cmd_path = find_path(data);
	if (execve(cmd_path, last_cmd, data->envp) < 0)
	{
		// ft_freetab(data);
		free(cmd_path);
		ft_error("Execve last");
	}
}
void	crea_process(t_data *data)
{
	while(data->i < data->ac - 1)
	{
		pipe(data->pipe_fd);
		// printf("pipefd[0] = %d\npipefd[1] = %d\n", data->pipe_fd[0], data->pipe_fd[1]);
		data->pid = fork();
		if (data->pid == 0)
		{
			if (data->i == 2 || (data->i == 3 && data->flag_HD == 1))
			{
				close(data->pipe_fd[0]);
				first_child(data);
			}
			else if (data->i == data->ac - 2)
			{
				close(data->pipe_fd[0]);
				last_child(data);
			}
			else if (data->i < data->ac - 2)
			{
				close(data->pipe_fd[0]);
				crea_child(data);
			}
		}
		data->fdtemp = &data->pipe_fd[0];
		// printf("fdtemp = [%d]\n", *data->fdtemp);
		data->i++;
	}
	wait(NULL);
}
