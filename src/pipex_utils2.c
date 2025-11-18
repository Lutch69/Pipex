/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:20:17 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/18 08:05:50 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_and_close(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		ft_error("Dup2");
	close(oldfd);
}

void	if_heredoc(t_data *data)
{
	char	*line;

	pipe(data->pipeHD);
	while(1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, "LIMITER\n", 8) == 0)
		{
			free(line);
			close(data->pipeHD[1]);
			break;
		}
		ft_putstr_fd(line, data->pipeHD[1]);
	}
}

void	ft_close(t_data *data)
{
	int	check_error;

	check_error = 0;
	// if (data->flag_HD == 1 && data->i == 3)
	// 	check_error = close(data->pipeHD[1]);
	if (data->i == 2 && data->flag_HD == 0)
		check_error = close(data->pipe_fd[1]);
	else if (data->flag_HD == 0 && data->i == 2)
		check_error = close(data->pipe_fd2[1]);
	else if (data->i == data->ac - 2 && data->flag == 1)
		check_error = close(data->pipe_fd2[0]);
	else if (data->i == data->ac - 2 && data->flag == 0)
		check_error = close(data->pipe_fd[0]);
	else if (data->i >= 3 && data->i < data->ac -2 && data->flag == 1)
		{
			check_error = close(data->pipe_fd[0]);
			check_error = close(data->pipe_fd2[1]);
		}
	else if (data->i >= 3 && data->i < data->ac -2 && data->flag == 0)
		{
			check_error = close(data->pipe_fd2[0]);
			check_error = close(data->pipe_fd[1]);
		}
	if (check_error < 0)
		ft_error("Close");
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
// void	crea_pid(t_data *data, int *pid, int *i, int flag)
// {
// 	if (*pid < 0)
// 		ft_error("Fork");
// 	if (*pid == 0)
// 	{
// 		if (*i == 2)
// 		{
// 			close(data->pipe_fd[0]);
// 			crea_first_child(data);
// 		}
// 		if (*i >= 3 && *i <= (data->ac - 3) && flag == 1)
// 			crea_child(data, i, flag);
// 		if (*i == (data->ac - 2))
// 			crea_last_child(data, flag);
// 	}
// 	else
// 		wait(NULL);
// }
