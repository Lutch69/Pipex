/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:20:17 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/13 17:29:29 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	crea_pid(t_data *data)
{
	int	i;

	i = 3;
	while(i <= (data->ac - 3))
	{
		int	pid;

		pid = fork();
		if (pid < 0)
			ft_error();
		else if (pid == 0)
			crea_child(data, i);

		i++;
	}
}
