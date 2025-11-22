/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:33:26 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/22 16:14:14 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	crea_child(t_data *data)
{
	close(data->pipe_fd[0]);
	if (data->flag_hd == 1 && data->i == 3)
		dup_and_close(data->pipehd[0], 0);
	else
		dup_and_close(data->previous, 0);
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
	close(data->pipe_fd[0]);
	dup_and_close(data->previous, 0);
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
	while (data->i < data->ac - 1)
	{
		set_up_cmd(data);
		pipe(data->pipe_fd);
		data->pid = fork();
		if (data->pid == 0)
		{
			if (data->i == data->ac - 2)
				last_child(data);
			else if (data->i < data->ac - 2)
				crea_child(data);
		}
		if (data->flag_hd == 1 && data->i == 3)
			close(data->pipehd[0]);
		else
			close(data->previous);
		data->previous = data->pipe_fd[0];
		close(data->pipe_fd[1]);
		ft_freetab(data->cmd);
		free(data->cmd_path);
		data->i++;
	}
	ft_close_all(data);
	wait_child();
}
