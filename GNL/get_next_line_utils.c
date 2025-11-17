/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:49:14 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/16 16:12:34 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat_GNL(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	if (!dst || !src)
		return (0);
	i = 0;
	srclen = ft_strlen_GNL(src);
	dstlen = ft_strlen_GNL(dst);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while ((src[i]) && (i < dstsize - dstlen - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

char	*ft_strndup(char *s1, size_t len)
{
	size_t	i;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	s2 = malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr_GNL(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin_GNL(char *s1, char *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strndup(s2, ft_strlen_GNL(s2)));
	else if (!s2)
		return (ft_strndup(s1, ft_strlen_GNL(s1)));
	len1 = ft_strlen_GNL(s1);
	len2 = ft_strlen_GNL(s2);
	i = -1;
	newstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (free(s1), NULL);
	while (s1[++i])
		newstr[i] = s1[i];
	newstr[i] = '\0';
	ft_strlcat_GNL(newstr, s2, len1 + len2 + 1);
	free(s1);
	return (newstr);
}

size_t	ft_strlen_GNL(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
