/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:20:17 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/22 18:44:12 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_trim(t_data *data)
{
	char *temp;

	if (data->cmd[1] != NULL)
	{
		if (ft_strchr(data->cmd[1], 39))
		{
			temp = ft_strtrim(data->cmd[1], "'");
			free(data->cmd[1]);
			data->cmd[1] = ft_strdup(temp);
			free(temp);
		}
	}
}

void	set_up_cmd(t_data *data)
{
	data->cmd = check_cmd(data);
	if (!data->cmd || !*data->cmd)
	{
		if (data->i == 3)
			wait(NULL);
		ft_close_all(data);
		ft_error("Wrongs cmd");
	}
	cmd_trim(data);
	data->cmd_path = find_path(data, data->cmd);
	if (!data->cmd_path)
	{
		if (data->i == 3)
			wait(NULL);
		ft_freetab(data->cmd);
		free(data->cmd_path);
		ft_close_all(data);
		ft_error("Wrongs cmd");
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
		return (NULL);
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
