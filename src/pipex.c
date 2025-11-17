/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:50:58 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/17 14:34:45 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_here_doc(t_data *data)
{
	if (ft_strncmp(data->av[1], "here_doc", 9) == 0)
	{
		data->i = 3;
		data->flag_HD = 1;
	}
	else
	{
		data->i = 2;
		data->flag_HD = 0;
	}
}

int	ac_count(int ac)
{
	int	count;

	count = 0;
	while (count < ac)
		count++;
	if (count < 5)
	{
		write (2, "Wrong Argc, please retry.\n", 27);
		return (0);
	}
	else
		return(1);
}

int	main(int ac, char **av, char **envp)
{
	t_data data;

	data.ac = ac;
	if (ac_count(ac))
	{
		data.pipecount = (data.ac - 3);
		data.av = av;
		data.envp = envp;
		check_here_doc(&data);
		if (data.flag_HD == 0)
			data.fd_in = open_fd_in(av[1]);
		data.fd_out = open_fd_out(av[ac - 1]);
		crea_process(&data);
	}
	return(0);
}
