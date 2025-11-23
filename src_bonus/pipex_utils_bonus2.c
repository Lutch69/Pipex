/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:53:33 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/23 17:07:15 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	set_up_cmd(t_data *data)
{
	data->cmd = check_cmd(data);
	if (!data->cmd || !*data->cmd)
	{
		ft_close_all(data);
		wait_child();
		ft_close_all(data);
		ft_error("Command not found");
	}
	cmd_trim(data);
	data->cmd_path = find_path(data, data->cmd);
	if (!data->cmd || !*data->cmd || !data->cmd_path)
	{
		ft_close_all(data);
		ft_freetab(data->cmd);
		free(data->cmd_path);
		ft_error("Command not found");
	}
}

char	**check_cmd(t_data *data)
{
	int		i;
	char	**ret;
	char	*temp;

	i = 0;
	if (!data->av[data->i] || !*data->av[data->i])
		return (NULL);
	else
		ret = ft_split(data->av[data->i], ' ');
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

void	if_heredoc(t_data *data)
{
	char	*line;

	pipe(data->pipehd);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, data->av[2], (ft_strlen(line) - 1)) == 0
			&& line[0] != '\n')
		{
			free(line);
			close(data->pipehd[1]);
			break ;
		}
		ft_putstr_fd(line, data->pipehd[1]);
		free(line);
	}
}

void	wait_child(void)
{
	int	waitnb;
	int	status;

	waitnb = 1;
	status = 0;
	while (waitnb > 0)
	{
		waitnb = wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status))
			exit(EXIT_FAILURE);
	}
}
