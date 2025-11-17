/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:05:47 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/16 17:23:00 by lucasdebarn      ###   ########.fr       */
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
# include "../GNL/get_next_line.h"

typedef struct s_data
{
	char	**av;
	char	**envp;
	pid_t	pid;
	int		ac;
	int		pipe_fd[2];
	int		pipe_fd2[2];
	int		pipeHD[2];
	int		fd_in;
	int		fd_out;
	int		pipecount;
	int		flag_HD;
	int		flag;
	int		i;
}			t_data;

// UTILS
void	ft_freetab(char **tab);
void	ft_error(char *errorname);
void	close_all(t_data *data);
void	ft_close(t_data *data);
void	dup_and_close(int oldfd, int newfd);

// IF HD
void	if_heredoc(t_data *data);
void	check_here_doc(t_data *data);

// OPEN
int		open_fd_in(char *filename);
int		open_fd_out(char *filename);

// UTILITY
char	*find_path(char **envp, char **cmd);
char	*ft_strjoin_path(char const *s1, char const *s2);
// void	crea_pid(t_data *data, int *pid, int *i, int flag);

// CREA PROCESS
void	crea_process(t_data *data);
int		crea_pipe(t_data *data, int flag);
void	crea_first_child(t_data *data);
void	crea_last_child (t_data *data);
void	crea_child(t_data *data);

#endif
