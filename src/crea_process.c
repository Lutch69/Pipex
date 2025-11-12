/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:54:00 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/12 07:17:36 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	crea_first_child(t_data *data)
{
	char	**cmd1;
	char	*cmd_path;
	pid_t	pid;

	dup2(data->fd_in, 0);
	dup2(data->pipe_fd[1], 1);
	cmd1 = ft_split(data->av[2], ' ');
	cmd_path = find_path(data->envp, cmd1);
	close(data->fd_in);
	close(data->pipe_fd[1]);
	execve(cmd_path, cmd1, data->envp);
}
pid_t	crea_process(t_data *data)
{
	int		i;
	pid_t	pid;
	pid_t	pid1;
	char	**cmd1;
	char	*cmd_path;

	i = 0;
	pid = fork();
	if (pid == 0)
		crea_first_child(data);
	pid1 = fork();
	if (pid1 == 0)
		crea_second_child(data);
	else
	{
		close(data->pipe_fd[0]);
		close(data->pipe_fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid1, NULL, 1);
	}
}
