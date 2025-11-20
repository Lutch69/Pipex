/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:21:32 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/20 18:35:28 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_child(t_data *data)
{
	int	waitnb = 1;
	int	status;

	status = 0;
	while (waitnb > 0)
	{
		waitnb = wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status))
			{
				ft_close_all(data);
				exit(EXIT_FAILURE);
			}
	}
	ft_freetab(data->cmd);
	free(data->cmd_path);
	ft_close_all(data);
}

void	crea_child(t_data *data)
{
	close(data->pipe_fd[0]);
	if (data->flag_hd == 1 && data->i == 3)
		dup_and_close(data->pipehd[0], 0);
	else
		dup_and_close(data->previous, 0);
	if (data->i == data->ac - 2)
		dup_and_close(data->fd_out, 1);
	else
		dup_and_close(data->pipe_fd[1], 1);
	if (execve(data->cmd_path, data->cmd, data->envp) < 0)
	{
		ft_freetab(data->cmd);
		free(data->cmd_path);
		ft_error("Execve");
	}
}

// void	last_child(t_data *data)
// {
// 	close(data->pipe_fd[0]);
// 	dup_and_close(data->previous, 0);
// 	dup_and_close(data->fd_out, 1);
// 	if (execve(data->cmd_path, data->cmd, data->envp) < 0)
// 	{
// 		ft_freetab(data->cmd);
// 		free(data->cmd_path);
// 		ft_error("Execve last");
// 	}
// }

void	crea_process(t_data *data)
{
	while (data->i < data->ac - 1)
	{
		data->cmd = check_cmd(data);
		data->cmd_path = find_path(data, data->cmd);
		if (!data->cmd || !*data->cmd || !data->cmd_path)
		{
			ft_freetab(data->cmd);
			free(data->cmd_path);
			ft_error("Cmd or Path not found");
		}
		pipe(data->pipe_fd);
		data->pid = fork();
		if (data->pid == 0)
			if (data->i < data->ac - 2)
				crea_child(data);
		if (data->flag_hd == 1 && data->i == 3)
			close(data->pipehd[0]);
		else
			close(data->previous);
		data->previous = data->pipe_fd[0];
		close(data->pipe_fd[1]);
		data->i++;
	}
	wait_child(data);
}
