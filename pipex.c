/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:33:40 by olachhab          #+#    #+#             */
/*   Updated: 2025/01/13 09:11:21 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		status1;
	int		status2;

	chek_in_first(ac, pipe_fd);
	pid_1 = fork();
	if (pid_1 < 0)
		error_check("Fork error");
	if (pid_1 == 0)
		first_child(pipe_fd, av, envp);
	pid_2 = fork();
	if (pid_2 < 0)
		error_check("Fork error");
	if (pid_2 == 0)
		second_child(pipe_fd, av, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid_1, &status1, 0);
	waitpid(pid_2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}
