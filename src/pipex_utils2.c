/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:20:17 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/22 14:49:39 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**check_cmd(t_data *data)
{
	int		i;
	char	**ret;
	char	*temp;

	i = 0;
	ret = ft_split(data->av[data->i], ' ');
	if (!*ret || !ret)
	{
		free(ret);
		return(NULL);
	}
	if (access(ret[0], F_OK | X_OK) == 0)
	{
		while (ret[0][i])
			i++;
		while (ret[0][i] != '/')
			i--;
		temp = ft_substr(ret[0], i, (ft_strlen(ret[0]) - i));
		free(ret[0]);
		ret[0] = ft_strdup(temp);
		free(temp);
	}
	return (ret);
}

void	dup_and_close(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		ft_error("Dup2");
	close(oldfd);
}
