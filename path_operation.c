#include "pipex.h"

char **find_path(char *envp[])
{
	int i = 0;

	if (!envp)
		return NULL;

	while (envp[i])
	{
		// Using strncmp equivalent for better readability
		if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
			envp[i][2] == 'T' && envp[i][3] == 'H' &&
			envp[i][4] == '=')
		{
			return (split_path(envp[i] + 5));
		}
		i++;
	}
	return (NULL);
}

char *join_paths(char *path, char *cmd)
{
	char *full_path;
	int i = 0;
	int j = 0;

	full_path = malloc(ft_strlen(path) + ft_strlen(cmd) + 2);
	if (!full_path)
		return (NULL);

	// Copy path
	while (path[i])
	{
		full_path[i] = path[i];
		i++;
	}

	// Add slash
	full_path[i] = '/';
	i++;

	// Copy command
	while (cmd[j])
	{
		full_path[i + j] = cmd[j];
		j++;
	}
	full_path[i + j] = '\0';

	return (full_path);
}

char **split_path(const char *str)
{
	char **result;
	size_t i, j, k, word_count;

	if (!str)
		return (NULL);

	// Count paths
	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ':') // Only split on ':'
			i++;
		if (str[i])
			word_count++;
		while (str[i] && str[i] != ':') // Move until next ':'
			i++;
	}

	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);

	// Split into paths
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ':')
			i++;
		j = i;
		while (str[i] && str[i] != ':')
			i++;
		if (i > j)
		{
			result[k] = malloc(i - j + 1);
			if (!result[k])
			{
				free_array(result);
				return (NULL);
			}
			ft_strncpy(result[k], &str[j], i - j);
			result[k][i - j] = '\0';
			k++;
		}
	}
	result[k] = NULL;
	return (result);
}
