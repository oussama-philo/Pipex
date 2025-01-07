#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h> 

/*--------------Path operation------------*/

char **find_path(char *envp[]);
char *join_paths(char *path, char *cmd);
char **split_path(const char *str);

/*--------------CMD operation--------------*/

char **split_cmd(const char *str);

/*--------------Utils func-----------------*/

size_t ft_strlen(const char *str);
char *ft_strncpy(char *s1, const char *s2, size_t n);
void free_array(char **arr);

/*--------------Exec Cmd-----------------*/

void execute_cmd(char *argv[], char *envp[], int is_first);

#endif
