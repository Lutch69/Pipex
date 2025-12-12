/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:49:42 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/25 11:30:50 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (data->flag_hd == 1 && data->i == 3)
		close(data->pipehd[0]);
	else if (data->i == 2 && data->flag_hd == 0)
		close(data->fd_in);
	else if (data->i > 2)
		close(data->previous);
	close(data->fd_out);
}
