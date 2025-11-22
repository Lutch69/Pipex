/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:49:39 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/22 11:50:05 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin_path(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
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
	ft_strlcpy(newstr + len1, s2, (len2 + 1));
	return (newstr);
}

char	*find_path(t_data *data, char **cmd)
{
	int		i;
	int		j;
	char	*cmd_path;
	char	**path;

	i = 0;
	j = 0;
	if ((access(data->av[data->i], F_OK | X_OK)) == 0)
		return (ft_strdup(data->av[data->i]));
	while (ft_strncmp(data->envp[i], "PATH=", 5) != 0)
		i++;
	if (!data->envp[i])
		return (NULL);
	path = ft_split(data->envp[i] + 5, ':');
	while (path[j] != NULL)
	{
		cmd_path = ft_strjoin_path(path[j], cmd[0]);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (ft_freetab(path), cmd_path);
		else
			free(cmd_path);
		j++;
	}
	ft_freetab(path);
	return (NULL);
}

int	open_fd_in(char *filename)
{
	int	fd_in;

	fd_in = open(filename, O_RDONLY);
	if (fd_in < 0)
	{
		perror("Open fd_in");
		exit(EXIT_FAILURE);
	}
	return (fd_in);
}

int	open_fd_out(char *filename)
{
	int	fd_out;

	if (access(filename, O_WRONLY) < 0)
		fd_out = open(filename, O_CREAT | O_WRONLY);
	else
		fd_out = open(filename, O_WRONLY | O_TRUNC | 0644);
	if (fd_out < 0)
		ft_error("Open fd_out");
	return (fd_out);
}
