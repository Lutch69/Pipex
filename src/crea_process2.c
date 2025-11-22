/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:21:32 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/22 18:39:02 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_data *data)
{
	dup_and_close(data->fd_in, 0);
	dup_and_close(data->pipe_fd[1], 1);
	if (execve(data->cmd_path, data->cmd, data->envp) < 0)
	{
		ft_freetab(data->cmd);
		free(data->cmd_path);
		ft_error("Execve");
	}
}

void	last_child(t_data *data)
{
	dup_and_close(data->pipe_fd[0], 0);
	dup_and_close(data->fd_out, 1);
	if (execve(data->cmd_path, data->cmd, data->envp) < 0)
	{
		ft_freetab(data->cmd);
		free(data->cmd_path);
		ft_error("Execve last");
	}
}

void	crea_process(t_data *data)
{
	pipe(data->pipe_fd);
	while (data->i < data->ac - 1)
	{
		set_up_cmd(data);
		data->pid = fork();
		if (data->pid == 0)
		{
			if (data->i == data->ac - 2)
				last_child(data);
			if (data->i < data->ac - 2)
				first_child(data);
		}
		if (data->i == 2)
			close(data->fd_in);
		close(data->pipe_fd[1]);
		ft_freetab(data->cmd);
		free(data->cmd_path);
		data->i++;
	}
	ft_close_all(data);
	wait_child();
}
