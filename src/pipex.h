/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:05:47 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/12 07:12:16 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_data
{
	char **av;
	char **envp;
	int pipe_fd[2];
	int fd_in;
	int fd_out;
}	t_data;

void	ft_freetab(char **tab);
void	ft_error(char *str);
void	close_all(t_data *data);
int		open_fd_in(char *filename);
int		open_fd_out(char *filename);
char	*find_path(char **envp, char **cmd);
pid_t	crea_process(t_data *data);

#endif
