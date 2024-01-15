/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:42:26 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/31 16:37:27 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../42-libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

struct s_pipex_fd
{
	int	fd[2];
	int	fd_file[2];
	int	pid;
	int	i;
}s_pipex;

void	pipex(char **av, char **env);
char	**parse_path(char **env);
char	**path_finder(char **env);
char	*check_access(char **command, char **env);
char	**split_command(char *av);
void	child_1(char **av, char **path, char **env);
void	child_2(char **av, char **path, char **env);
void	clear_elements(char *a);

#endif