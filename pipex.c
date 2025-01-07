#include "pipex.h"

void execute_cmd(char *argv[], char *envp[], int is_first)
{
	char **args;
	char **paths;
	char *cmd_path;
	int i;

	if (is_first == 1)
		args = split_cmd(argv[2]);
	else
		args = split_cmd(argv[3]);

	// bach ila badya arguemt b "/"
	if (args[0][0] == '/')
	{
		if (access(args[0], X_OK) == 0)
			execve(args[0], args, envp);
	}
	else
	{
		paths = find_path(envp);
		i = 0;
		while (paths[i])
		{
			cmd_path = join_paths(paths[i], args[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				execve(cmd_path, args, envp);
				free(cmd_path);
			}
			free(cmd_path);
			i++;
		}
		free_array(paths);
	}
	free_array(args);
	perror("Command not found");
	exit(1);
}

int main(int ac, char *av[], char *envp[])
{
	pid_t pid_1;
	pid_t pid_2;

	int pipe_fd[2];
	// pipe_fd[0] --> read
	// pipe_fd[1] --> write

	int infile;
	int outfile;

	if (ac != 5)
	{
		perror("Number of argumet not 5");
		exit(1);
	}

	if (access(av[1], R_OK) < 0)
	{
		perror(av[1]);
		exit(1);
	}

	if (pipe(pipe_fd) == -1)
	{
		perror("Pipe not created");
		exit(1);
	}

	pid_1 = fork();

	if (pid_1 < 0)
	{
		perror("Process not created");
		exit(1);
	}

	// child 1 process
	if (pid_1 == 0)
	{
		infile = open(av[1], O_RDONLY);

		if (infile < 0)
		{
			perror("File not exist");
			exit(1);
		}

		dup2(infile, STDIN_FILENO);

		dup2(pipe_fd[1], STDOUT_FILENO);

		close(pipe_fd[1]);
		close(pipe_fd[0]);
		close(infile);
		execute_cmd(av, envp, 1);
	}

	/*---------------------------------------------------------------------------*/

	pid_2 = fork();

	if (pid_2 < 0)
	{
		perror("Process not created");
		exit(1);
	}

	// child 2 process
	if (pid_2 == 0)
	{
		outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);

		if (outfile < 0)
		{
			perror("File not exist");
			exit(1);
		}

		dup2(pipe_fd[0], STDIN_FILENO);

		dup2(outfile, STDOUT_FILENO);

		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(outfile);
		execute_cmd(av, envp, 0);
	}

	close(pipe_fd[0]);
	close(pipe_fd[1]);

	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);

	return (0);
}
