/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:29:45 by olachhab          #+#    #+#             */
/*   Updated: 2025/01/13 09:02:53 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	chek_in_first(int ac, int pipe_fd[2])
{
	if (ac != 5)
		error_check("we need: ./pipex infile cmd1 cmd2 outfile\n");
	if (pipe(pipe_fd) == -1)
		error_check("Pipe error");
}
