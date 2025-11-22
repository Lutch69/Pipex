/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:06:50 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/22 18:03:27 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *errorname)
{
	perror(errorname);
	exit(EXIT_FAILURE);
}

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_close_all(t_data *data)
{
	if (data->i == 2)
	{
		close(data->pipe_fd[1]);
		close(data->fd_in);
	}
	close(data->pipe_fd[0]);
	close(data->fd_out);
}
