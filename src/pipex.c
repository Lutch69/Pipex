/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:50:58 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/12 07:20:09 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	t_data data;
	pid_t	parent_pid;
	if (ac == 5)
	{
		data.fd_in = open_fd_in("input");
		data.fd_out = open_fd_in("output");
		data.av = av;
		data.envp = envp;
		pipe(data.pipe_fd);
		parent_pid = crea_process(&data);
	}
}
