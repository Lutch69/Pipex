/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:20:17 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/15 16:01:39 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(t_data *data, int *i, int flag)
{
	if (*i == 2)
		close(data->pipe_fd[1]);
	else if (*i == data->ac - 2 && flag == 1)
		close(data->pipe_fd2[0]);
	else if (*i == data->ac - 2 && flag == 0)
		close(data->pipe_fd[0]);
	else if (*i >= 3 && *i < data->ac -2 && flag == 1)
		{
			close(data->pipe_fd[0]);
			close(data->pipe_fd2[1]);
		}
	else if (*i >= 3 && *i < data->ac -2 && flag == 0)
		{
			close(data->pipe_fd2[0]);
			close(data->pipe_fd[1]);
		}
}

int	crea_pipe(t_data *data, int flag)
{
	if (flag == 0)
	{
		if (pipe(data->pipe_fd) < 0)
			ft_error("pipe");
		return(0);
	}
	else
		if (pipe(data->pipe_fd2) < 0)
			ft_error("pipe2");
	return(1);
}
void	crea_pid(t_data *data, int *pid, int *i, int flag)
{
	if (*pid < 0)
		ft_error("Fork");
	if (*pid == 0)
	{
		if (*i == 2)
		{
			close(data->pipe_fd[0]);
			crea_first_child(data);
		}
		if (*i >= 3 && *i <= (data->ac - 3) && flag == 1)
			crea_child(data, i, flag);
		if (*i == (data->ac - 2))
			crea_last_child(data, flag);
	}
	else
		wait(NULL);
}
