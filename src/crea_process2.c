/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:21:32 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/19 16:50:10 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	crea_child(t_data *data)
{
	char	*cmd_path;
	char	**cmd;

	close(data->pipe_fd[0]);
	if (data->flag_hd == 1 && data->i == 3)
		dup_and_close(data->pipehd[0], 0);
	else
		dup_and_close(data->previous, 0);
	dup_and_close(data->pipe_fd[1], 1);
	cmd = check_cmd(data);
	if (!cmd || !cmd[0])
		ft_error("Wrong cmds");
	cmd_path = find_path(data, cmd);
	if (execve(cmd_path, cmd, data->envp) < 0)
	{
		ft_freetab(cmd);
		free(cmd_path);
		ft_error("Execve");
	}
}

void	last_child(t_data *data)
{
	char	**last_cmd;
	char	*cmd_path;

	close(data->pipe_fd[0]);
	dup_and_close(data->previous, 0);
	dup_and_close(data->fd_out, 1);
	last_cmd = check_cmd(data);
	if (!last_cmd || !last_cmd[0])
		ft_error("Wrong cmds");
	cmd_path = find_path(data, last_cmd);
	if (execve(cmd_path, last_cmd, data->envp) < 0)
	{
		ft_freetab(last_cmd);
		free(cmd_path);
		ft_error("Execve last");
	}
}

void	crea_process(t_data *data)
{
	int	waitnb;

	waitnb = 1;
	while (data->i < data->ac - 1)
	{
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
		data->i++;
	}
	while (waitnb > 0)
		waitnb = wait(NULL);
}
