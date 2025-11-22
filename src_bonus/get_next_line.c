/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:24:48 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/19 15:47:04 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_stash(char *stash)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free (stash);
		return (NULL);
	}
	tmp = ft_strndup(&stash[i], ft_strlen_gnl(stash) - i);
	free(stash);
	return (tmp);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = ft_strndup(stash, i);
	return (res);
}

char	*read_line(const int fd, char *stash)
{
	int		read_size;
	char	*temp;

	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(temp);
			if (stash)
				free(stash);
			return (NULL);
		}
		temp[read_size] = '\0';
		stash = ft_strjoin_gnl(stash, temp);
		if (ft_strchr_gnl(stash, '\n'))
			break ;
	}
	free(temp);
	return (stash);
}

char	*get_next_line(const int fd)
{
	static char	*stash[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	stash[fd] = read_line(fd, stash[fd]);
	if (stash[fd] && *stash[fd] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stash[fd]);
	stash[fd] = new_stash(stash[fd]);
	return (line);
}
