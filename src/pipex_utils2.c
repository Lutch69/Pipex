/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:20:17 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/14 16:58:17 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	crea_pipe(t_data *data)
{
	int	pipetemp[2];
	int	i;

	i = 1;
	while(i < data->pipecount)
	{
		pipe(pipetemp + i);
		printf("%d\n", *pipetemp);
		i++;
	}
}
void	crea_pid(t_data *data, int *pid, int *i)
{
	*pid = fork();
	if (*pid < 0)
		ft_error("Fork");
	else if (*pid == 0)
	{
		if (*i == 2)
		{
			close(data->pipe_fd[0]);
			crea_first_child(data);
		}
		if (*i >= 3 && *i <= (data->ac - 3))
			crea_child(data, i);
		if (*i == (data->ac - 2))
		{
			close(data->pipe_fd[1]);
			crea_last_child(data);
		}
	}
}
