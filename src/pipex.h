/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:05:47 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/13 13:09:50 by ludebarn         ###   ########.fr       */
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
void	ft_error(void);
void	close_all(t_data *data);
int		open_fd_in(char *filename);
int		open_fd_out(char *filename);
char	*find_path(char **envp, char **cmd);
void	crea_process(t_data *data);
char	*ft_strjoin_path(char const *s1, char const *s2);
void	crea_last_child (t_data *data);

#endif
