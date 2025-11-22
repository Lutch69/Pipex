/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:05:47 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/11/22 18:47:12 by ludebarn         ###   ########.fr       */
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
	char	**cmd;
	char	*cmd_path;
	pid_t	pid;
	int		ac;
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
	int		i;
}			t_data;

// UTILS
void	ft_close_all(t_data *data);
void	ft_freetab(char **tab);
void	ft_error(char *errorname);
void	dup_and_close(int oldfd, int newfd);
char	**check_cmd(t_data *data);
void	wait_child(void);
void	set_up_cmd(t_data *data);
void	cmd_trim(t_data *data);

// OPEN
int		open_fd_in(char *filename);
int		open_fd_out(char *filename);

// PATH
char	*find_path(t_data *data, char **cmd);
char	*ft_strjoin_path(char const *s1, char const *s2);

// PROCESS
void	crea_process(t_data *data);
void	last_child(t_data *data);
void	first_child(t_data *data);

#endif
