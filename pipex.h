/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:51:21 by olachhab          #+#    #+#             */
/*   Updated: 2025/01/13 09:03:05 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

void	chek_in_first(int ac, int pipe_fd[2]);
void	first_child(int *pipe_fd, char **av, char **envp);
void	second_child(int *pipe_fd, char **av, char **envp);
void	error_check(char *msg);
char	**split_cmd(char *str, char *sap);
char	**splitpath(char const *s, char c);
void	execute_cmd(char *argv[], char *envp[], int is_first);
void	path_execution(char **args, char *envp[]);
char	**find_path(char *envp[]);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	free_array(char **arr);
char	*join_paths(char *phats, char *args);

#endif
