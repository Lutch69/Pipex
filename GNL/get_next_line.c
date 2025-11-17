/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:59:41 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/16 16:04:45 by lucasdebarn      ###   ########.fr       */
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
	tmp = ft_strndup(&stash[i], ft_strlen_GNL(stash) - i);
	free(stash);
	return (tmp);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = ft_strndup(stash, i);
	return (res);
}

char	*cpy_line(const int fd, char *stash)
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
				free (stash);
			return (NULL);
		}
		temp[read_size] = '\0';
		stash = ft_strjoin_GNL(stash, temp);
		if (ft_strchr_GNL(stash, '\n'))
			break ;
	}
	free(temp);
	return (stash);
}

char	*get_next_line(const int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = cpy_line(fd, stash);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = new_stash(stash);
	return (line);
}

