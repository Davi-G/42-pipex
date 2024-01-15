/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:08:52 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/31 16:37:24 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	pipex(char **av, char **env)
{
	char	**path;

	s_pipex.i = 0;
	path = path_finder(env);
	pipe(s_pipex.fd);
	if (pipe(s_pipex.fd) < 0)
		exit(EXIT_FAILURE);
	s_pipex.fd_file[0] = open(av[1], O_RDONLY);
	if (s_pipex.fd_file[0] == -1)
		exit(EXIT_FAILURE);
	s_pipex.fd_file[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (s_pipex.fd_file[1] == -1)
		exit(EXIT_FAILURE);
	child_1(av, path, env);
	child_2(av, path, env);
	while (path[s_pipex.i])
		clear_elements(path[s_pipex.i++]);
	free(path);
	close(s_pipex.fd[0]);
	close(s_pipex.fd[1]);
}

void	child_1(char **av, char **path, char **env)
{
	char	*aux;
	char	**command;

	s_pipex.i = 0;
	s_pipex.pid = fork();
	if (s_pipex.pid == -1)
	{
		while (path[s_pipex.i])
			clear_elements(path[s_pipex.i++]);
		free(path);
		exit(EXIT_FAILURE);
	}
	if (s_pipex.pid == 0)
	{
		close(s_pipex.fd[0]);
		dup2(s_pipex.fd_file[0], STDIN_FILENO);
		close(s_pipex.fd_file[0]);
		dup2(s_pipex.fd[1], STDOUT_FILENO);
		close(s_pipex.fd[1]);
		command = split_command(av[2]);
		aux = check_access(command, path);
		execve(aux, command, env);
		exit(EXIT_FAILURE);
	}
}

void	child_2(char **av, char **path, char **env)
{
	char	*aux;
	char	**command;

	s_pipex.i = 0;
	s_pipex.pid = fork();
	if (s_pipex.pid == -1)
	{
		while (path[s_pipex.i])
			clear_elements(path[s_pipex.i++]);
		free(path);
		exit(EXIT_FAILURE);
	}
	if (s_pipex.pid == 0)
	{
		close(s_pipex.fd[1]);
		dup2(s_pipex.fd[0], STDIN_FILENO);
		close(s_pipex.fd[0]);
		dup2(s_pipex.fd_file[1], STDOUT_FILENO);
		close(s_pipex.fd_file[1]);
		command = split_command(av[3]);
		aux = check_access(command, path);
		execve(aux, command, env);
		exit(EXIT_FAILURE);
	}
}
