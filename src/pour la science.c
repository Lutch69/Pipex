/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pour la science.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 04:54:00 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/19 13:02:49 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex.h"

// void	crea_first_child(t_data *data)
// {
// 	char	**cmd1;
// 	char	*cmd_path;

// 	if (data->flag_HD == 1 && data->i == 3)
// 	{
// 		if_heredoc(data);
// 		dup_and_close(data->pipeHD[0], 0);
// 	}
// 	else
// 		dup_and_close(data->fd_in, 0);
// 	if (data->flag == 1)
// 		dup_and_close(data->pipe_fd2[1], 1);
// 	else
// 		dup_and_close(data->pipe_fd[1], 1);
// 	cmd1 = ft_split(data->av[data->i], ' ');
// 	cmd_path = find_path(data->envp, cmd1);
// 	if (execve(cmd_path, cmd1, data->envp) < 0)
// 	{
// 		ft_freetab(cmd1);
// 		free(cmd_path);
// 		ft_error("Execve first child");
// 	}
// }

// void	crea_last_child (t_data *data)
// {
// 	char	**cmd2;
// 	char	*cmd_path;

// 	if (data->flag == 0)
// 		dup_and_close(data->pipe_fd[0], 0);
// 	else if (data->flag == 1)
// 		dup_and_close(data->pipe_fd2[0], 0);
// 	dup_and_close(data->fd_out, 1);
// 	cmd2 = ft_split(data->av[data->ac - 2], ' ');
// 	cmd_path = find_path(data->envp, cmd2);
// 	// if (!cmd2 || !cmd_path)
// 	// 	ft_error("Malloc");
// 	if (execve(cmd_path, cmd2, data->envp) < 0)
// 	{
// 		ft_freetab(cmd2);
// 		free(cmd_path);
// 		ft_error("Execve last child");
// 	}
// }

// void	crea_child(t_data *data)
// {
// 	char	**cmdn;
// 	char	*cmd_path;

// 	if (data->flag == 0)
// 	{
// 		dup_and_close(data->pipe_fd[1], 1);
// 		dup_and_close(data->pipe_fd2[0], 0);
// 	}
// 	else if (data->flag == 1)
// 	{
// 		dup_and_close(data->pipe_fd2[1], 1);
// 		dup_and_close(data->pipe_fd[0], 0);
// 	}
// 	cmdn = ft_split(data->av[data->i], ' ');
// 	cmd_path = find_path(data->envp, cmdn);
// 	if (execve(cmd_path, cmdn, data->envp) < 0)
// 	{
// 		ft_freetab(cmdn);
// 		free(cmd_path);
// 		ft_error("Execve child");
// 	}
// }

// void	crea_process(t_data *data)
// {
// 	while (data->i < (data->ac - 1))
// 	{
// 		if (data->i  % 2 == 0 && data->i < (data->ac -2))
// 			data->flag = crea_pipe(data, 0);
// 		else if (data->i % 2 == 1 && data->ac > 5 && data->i < (data->ac - 2))
// 			data->flag = crea_pipe(data, 1);
// 		data->pid = fork();
// 		if (data->pid < 0)
// 			ft_error("Fork");
// 		if (data->pid == 0)
// 		{
// 			if (data->i == 2 && data->flag_HD == 0)
// 			{
// 				close(data->pipe_fd[0]);
// 				crea_first_child(data);
// 			}
// 			else if (data->i == 3 && data->flag_HD == 1)
// 			{
// 				close(data->pipe_fd2[0]);
// 				crea_first_child(data);
// 			}
// 			else if (data->i == (data->ac - 2))
// 				crea_last_child(data);
// 			else if (data->i >= 3 && data->i < (data->ac - 2))
// 				crea_child(data);
// 		}
// 		ft_close(data);
// 		data->i++;
// 	}
	// ft_freetab(data->av);
// 	wait(NULL);
// }
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
// }

// void	ft_close(t_data *data)
// {
// 	int	check_error;

// 	check_error = 0;
// 	// if (data->flag_HD == 1 && data->i == 3)
// 	// 	check_error = close(data->pipeHD[1]);
// 	if (data->i == 2 && data->flag_HD == 0)
// 		check_error = close(data->pipe_fd[1]);
// 	else if (data->flag_HD == 0 && data->i == 2)
// 		check_error = close(data->pipe_fd2[1]);
// 	else if (data->i == data->ac - 2 && data->flag == 1)
// 		check_error = close(data->pipe_fd2[0]);
// 	else if (data->i == data->ac - 2 && data->flag == 0)
// 		check_error = close(data->pipe_fd[0]);
// 	else if (data->i >= 3 && data->i < data->ac -2 && data->flag == 1)
// 		{
// 			check_error = close(data->pipe_fd[0]);
// 			check_error = close(data->pipe_fd2[1]);
// 		}
// 	else if (data->i >= 3 && data->i < data->ac -2 && data->flag == 0)
// 		{
// 			check_error = close(data->pipe_fd2[0]);
// 			check_error = close(data->pipe_fd[1]);
// 		}
// 	if (check_error < 0)
// 		ft_error("Close");
// }

// int	crea_pipe(t_data *data, int flag)
// {
// 	if (flag == 0)
// 	{
// 		if (pipe(data->pipe_fd) < 0)
// 			ft_error("pipe");
// 		return(0);
// 	}
// 	else
// 		if (pipe(data->pipe_fd2) < 0)
// 			ft_error("pipe2");
// 	return(1);
// }
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
