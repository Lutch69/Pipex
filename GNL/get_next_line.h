/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 23:48:56 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/16 16:07:44 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(const int fd);
char	*cpy_line(const int fd, char *buffer);
char	*ft_strndup(char *s1, size_t len);
size_t	ft_strlcat_GNL(char *dst, char *src, size_t dstsize);
char	*ft_strchr_GNL(char *s, int c);
char	*ft_strjoin_GNL(char *s1, char *s2);
size_t	ft_strlen_GNL(char *s);

#endif
