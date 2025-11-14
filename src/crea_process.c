/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:54:00 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/14 16:27:32 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	crea_first_child(t_data *data)
{
	char	**cmd1;
	char	*cmd_path;

	dup2(data->fd_in, 0);
	dup2(data->pipe_fd[1], 1);
	cmd1 = ft_split(data->av[2], ' ');
	cmd_path = find_path(data->envp, cmd1);
	close(data->fd_in);
	close(data->pipe_fd[1]);
	if (execve(cmd_path, cmd1, data->envp) < 0)
	{
		ft_freetab(cmd1);
		free(cmd_path);
		ft_error("Execve");
	}
}

void	crea_last_child (t_data *data)
{
	char	**cmd2;
	char	*cmd_path;

	dup2(data->pipe_fd[0], 0);
	dup2(data->fd_out, 1);
	cmd2 = ft_split(data->av[3], ' ');
	cmd_path = find_path(data->envp, cmd2);
	close(data->fd_out);
	close(data->pipe_fd[0]);
	if (execve(cmd_path, cmd2, data->envp)< 0)
	{
		ft_freetab(cmd2);
		free(cmd_path);
		ft_error("Execve");
	}
}

void	crea_child(t_data *data, int *i)
{
	char	**cmdn;
	char	*cmd_path;

	dup2(data->pipe_fd[0], 0);
	dup2(data->pipe_fd[1], 1);
	cmdn = ft_split(data->av[*i], ' ');
	cmd_path = find_path(data->envp, cmdn);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	if (execve(cmd_path, cmdn, data->envp) < 0)
	{
		ft_freetab(cmdn);
		free(cmd_path);
		ft_error("Execve");
	}
}

void	crea_process(t_data *data)
{
	pipe(data->pipe_fd);
	int	 pid;
	int	i;

	i = 2;
	while (i <= (data->ac - 2))
	{
		pid = fork();
		crea_pid(data, &pid, &i);
		i++;
	}
	// int	pid;
	// int	pid1;
	// pipe(data->pipe_fd);
	// pid = fork();
	// if (pid < 0)
	// 	ft_error();
	// if (pid == 0)
	// {
	// 	close(data->pipe_fd[0]);
	// 	crea_first_child(data);
	// }
	// pid1 = fork();
	// if (pid1 < 0)
	// 	ft_error();
	// if (pid1 == 0)
	// {
	// 	close(data->pipe_fd[1]);
	// 	crea_last_child(data);
	// }
	// close(data->pipe_fd[0]);
	// waitpid(pid, NULL, 0);
	// waitpid(pid1, NULL, 1);

}
