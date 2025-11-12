/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:09:31 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/12 05:50:06 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strjoin_path(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len1 + len2 + 2));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	if (newstr[len1 - 1] != '/')
	{
		newstr[len1++] = '/';
		newstr[len1 + 1] = '\0';
	}
	ft_strlcat(newstr, s2, (len1 + len2 + 1));
	return (newstr);
}

char	*find_path(char **envp, char **cmd)
{
	int		i;
	char	*cmd_path;
	char	**path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		cmd_path = ft_strjoin_with_slash(path[i], cmd[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_freetab(path);
			return (cmd_path);
		}
		else
			free(cmd_path);
		i++;
	}
	ft_freetab(path);
	return (NULL);
}
void	close_all(t_data *data)
{
	close(data->fd_in);
	close(data->fd_out);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}
int	open_fd_in(char *filename)
{
	int	fd_in;

	fd_in = open("input", O_RDONLY);
	if (fd_in < 0)
		ft_error("Can't open files for input\n");
	return (fd_in);
}

int	open_fd_out(char *filename)
{
	int	fd_out;

	fd_out = open("output", O_WRONLY);
	if (fd_out < 0)
		ft_error("Can't open files for output\n");
	return (fd_out);
}

