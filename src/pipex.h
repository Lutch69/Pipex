/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:05:47 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/15 16:36:17 by ludebarn         ###   ########.fr       */
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
	char	**av;
	char	**envp;
	int		ac;
	int		pipe_fd[2];
	int		pipe_fd2[2];
	int		fd_in;
	int		fd_out;
	int		pipecount;
}			t_data;

void	ft_freetab(char **tab);
void	ft_error(char *errorname);
void	close_all(t_data *data);
void	ft_close(t_data *data, int *i, int flag);
int		check_here_doc(t_data *data);
int		open_fd_in(char *filename);
int		open_fd_out(char *filename);
char	*find_path(char **envp, char **cmd);
char	*ft_strjoin_path(char const *s1, char const *s2);
// void	crea_pid(t_data *data, int *pid, int *i, int flag);
void	crea_process(t_data *data);
int		crea_pipe(t_data *data, int flag);
void	crea_first_child(t_data *data);
void	crea_last_child (t_data *data, int flag);
void	crea_child(t_data *data, int *i, int flag);

#endif
