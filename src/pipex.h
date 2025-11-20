/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:05:47 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/20 18:19:39 by ludebarn         ###   ########.fr       */
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
	char	**cmd;
	char	*cmd_path;
	pid_t	pid;
	int		ac;
	int		pipe_fd[2];
	int		pipehd[2];
	int		fd_in;
	int		fd_out;
	int		flag_hd;
	int		i;
	int		previous;
	int		*status;
}			t_data;

// UTILS
void	ft_close_all(t_data *data);
void	ft_freetab(char **tab);
void	ft_error(char *errorname);
void	dup_and_close(int oldfd, int newfd);
char	**check_cmd(t_data *data);

// IF HD
void	if_heredoc(t_data *data);
void	check_here_doc(t_data *data, char **av);

// OPEN
int		open_fd_in(char *filename);
int		open_fd_out(char *filename);

// PATH
char	*find_path(t_data *data, char **cmd);
char	*ft_strjoin_path(char const *s1, char const *s2);

// PROCESS
void	crea_process(t_data *data);
void	last_child(t_data *data);
void	crea_child(t_data *data);

#endif
