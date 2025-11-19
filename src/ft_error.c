/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:06:50 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/18 21:53:04 by lucasdebarn      ###   ########.fr       */
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
