#include "pipex.h"

char **split_cmd(const char *str)
{
	char **result;
	size_t i, j, k, word_count;

	if (!str)
		return (NULL);

	 printf("Debug: Splitting command: %s\n", str);

	// Count words
	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ') // Skip spaces
			i++;
		if (str[i])
			word_count++;
		if (str[i] == '\'') // Handle single quotes
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i])
				i++;
		}
		else // Regular word
		{
			while (str[i] && str[i] != ' ')
				i++;
		}
	}

	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);

	// Split into words
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		j = i;
		if (str[i] == '\'') // Handle single quotes
		{
			i++;
			j = i;
			while (str[i] && str[i] != '\'')
				i++;
		}
		else // Regular word
		{
			while (str[i] && str[i] != ' ')
				i++;
		}
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
		if (str[i] == '\'')
			i++;
	}
	result[k] = NULL;
	return (result);
}
