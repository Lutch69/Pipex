/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:21:32 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/18 21:57:36 by lucasdebarn      ###   ########.fr       */
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
		dup_and_close(data->previous, 0);
		dup_and_close(data->pipe_fd[1], 1);
	}
	cmd1 = ft_split(data->av[data->i], ' ');
	cmd_path = find_path(data, cmd1);
	if (!(cmd1 || cmd1))
		ft_error("Split or path first");
	if (execve(cmd_path, cmd1, data->envp) < 0)
	{
		ft_freetab(cmd1);
		free(cmd_path);
		ft_error("Execve first");
	}
}
void	crea_child(t_data *data)
{
	char	**cmdn;
	char	*cmd_path;
	dup_and_close(data->previous, 0);
	dup_and_close(data->pipe_fd[1], 1);
	cmdn = ft_split(data->av[data->i], ' ');
	cmd_path = find_path(data, cmdn);
	if(!(cmdn || cmd_path))
		ft_error("split or path");
	if (execve(cmd_path, cmdn, data->envp) < 0)
	{
		ft_freetab(cmdn);
		free(cmd_path);
		ft_error("Execve");
	}
}
void	last_child(t_data *data)
{
	char	**last_cmd;
	char	*cmd_path;
	printf("%s\n", data->av[data->i]);
	dup_and_close(data->previous, 0);
	dup_and_close(data->fd_out, 1);
	last_cmd = ft_split(data->av[data->ac - 2], ' ');
	cmd_path = find_path(data, last_cmd);
	printf("%s\n", last_cmd[0]);
	if (execve(cmd_path, last_cmd, data->envp) < 0)
	{
		ft_freetab(last_cmd);
		free(cmd_path);
		ft_error("Execve last");
	}
}
void	crea_process(t_data *data)
{
	data->previous = data->fd_in;
	while(data->i < data->ac - 1)
	{
		pipe(data->pipe_fd);
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
		close(data->previous);
		data->previous = data->pipe_fd[0];
		close(data->pipe_fd[1]);
		data->i++;
	}
	while (wait(NULL) > 0);
}
