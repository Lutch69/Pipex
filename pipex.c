/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:50:58 by ludebarn          #+#    #+#             */
/*   Updated: 2025/11/11 20:33:41 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int ac, char **av, char **envp)
{

	
	// int pipefd[2];
	// int fd_in;
	// int fd_out;
	// pid_t pid;

	// fd_in = open("input", O_RDONLY);
	// fd_out = open("output", O_WRONLY);
	// pipe(pipefd);
	// pid = fork();
	// if (pid == 0)
	// {
	// 	dup2(fd_in, 0); //l'entree viens du fichier input
	// 	dup2(pipefd[1], 1); // la sortie vas dans le pipe
	// 	execve("/bin/ls", av, envp);
	// }
	// else
	// 	waitpid(pid, NULL, 0);
}
