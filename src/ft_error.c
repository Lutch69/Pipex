/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:06:50 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/18 18:24:46 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *errorname)
{
	perror(errorname);
	exit(EXIT_FAILURE);
}
void	ft_free(t_data *data)
{
	if(!data->av)
		return ;
	while((data->i < data->ac - 1))
	{
		free(data->av[data->i]);
		data->i++;
	}
	free(data->av);
}
void	ft_freetab(char **tab)
{
	int	i;

	if(!(*tab || tab))
		return ;
	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
