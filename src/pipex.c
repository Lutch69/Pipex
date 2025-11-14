/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:50:58 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/14 16:55:36 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ac_count(int ac)
{
	int	count;

	count = 0;
	while (count < ac)
		count++;
	if (count == 5)
		return(1);
	else
		return(0);
}

int	main(int ac, char **av, char **envp)
{
	t_data data;

	data.ac = ac;
	// if (ac_count(ac) == 1)
	// {
		data.pipecount = (data.ac - 3);
		// data.fd_in = open_fd_in(av[1]);
		// data.fd_out = open_fd_out(av[ac - 1]);
		data.av = av;
		data.envp = envp;
	crea_pipe(&data);
		// crea_process(&data);
	// }
	return(0);
}
