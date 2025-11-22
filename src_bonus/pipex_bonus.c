/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:40:43 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/22 13:20:33 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_here_doc(t_data *data, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		data->i = 3;
		data->flag_hd = 1;
	}
	else
	{
		data->i = 2;
		data->flag_hd = 0;
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
		return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	data.ac = ac;
	if (ac_count(ac))
	{
		data.envp = envp;
		check_here_doc(&data, av);
		data.av = av;
		if (data.flag_hd == 0)
		{
			data.fd_in = open_fd_in(av[1]);
			data.previous = data.fd_in;
		}
		data.fd_out = open_fd_out(av[ac - 1]);
		if (data.flag_hd == 1)
			if_heredoc(&data);
		crea_process(&data);
	}
	return (0);
}
