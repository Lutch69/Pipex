/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:50:58 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/18 20:13:11 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	check_cmd(t_data *data, char **av, int ac)
// {
// 	int i = 0;

// 	data->av = malloc(sizeof(char *) * ac - 1);
// 	if(!data->ac)
// 		return ;
// 	while(av[i])
// 	{
// 		if (av[i][0] == '\0')
// 		{
// 			ft_freetab(data->av);
// 			ft_putstr_fd("Wrong Command, please retry\n", 2);
// 			exit(EXIT_FAILURE);
// 		}
// 		if (ft_strncmp(av[i], "/usr/bin/", 9) == 0)
// 			data->av[i] = ft_substr(av[i], 9, (ft_strlen(av[i]) - 9));
// 		else if (ft_strncmp(av[i], "/bin/", 5) == 0)
// 			data->av[i] = ft_substr(av[i], 5, ft_strlen(av[i]) - 5);
// 		else
// 			data->av[i] = ft_strdup(av[i]);
// 		i++;
// 	}
// }

void	check_here_doc(t_data *data, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
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
		data.envp = envp;
		check_here_doc(&data, av);
		// check_cmd(&data, av, ac);
		data.av = av;
		if (data.flag_HD == 0)
			data.fd_in = open_fd_in(av[1]);
		data.fd_out = open_fd_out(av[ac - 1]);
		crea_process(&data);
	}
	return(0);
}
