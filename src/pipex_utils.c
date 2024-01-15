/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:39:29 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/31 16:37:33 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*check_access(char **command, char **path)
{
	int		i;
	char	*aux;
	char	*str;

	i = 0;
	while (path[i])
	{
		aux = path[i];
		str = ft_strjoin(aux, "/");
		aux = ft_strjoin(str, command[0]);
		if (access(aux, X_OK) == 0)
		{
			return (aux);
			break ;
		}
		i++;
	}
	return (0);
}

char	**path_finder(char **env)
{
	int		i;
	char	*path;
	char	**path_split;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(env[i]);
			path_split = ft_split(path + 5, ':');
			free(path);
			return (path_split);
		}
		i++;
	}
	return (0);
}

char	**split_command(char *av)
{
	char	**split_1;

	split_1 = ft_split(av, ' ');
	return (split_1);
}
