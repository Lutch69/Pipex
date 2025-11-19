/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:20:17 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/19 18:02:05 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**check_cmd(t_data *data)
{
	int		i;
	char	*temp;
	char	**ret;

	i = 0;
	temp = data->av[data->i];
	ret = NULL;
	if (access(temp, F_OK | X_OK) == 0)
	{
		ret = malloc(sizeof(char *) * 2);
		while (temp[i])
			i++;
		while (temp[i] != '/')
			i--;
		ret[0] = ft_substr(temp, i, (ft_strlen(temp) - i));
		ret[1] = NULL;
	}
	else
		ret = ft_split(data->av[data->i], ' ');
	return (ret);
}

void	dup_and_close(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
		ft_error("Dup2");
	close(oldfd);
}

void	if_heredoc(t_data *data)
{
	char	*line;

	pipe(data->pipehd);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, data->av[2], (ft_strlen(line) - 1)) == 0)
		{
			free(line);
			close(data->pipehd[1]);
			break ;
		}
		ft_putstr_fd(line, data->pipehd[1]);
		free(line);
	}
}
