/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagomez <dagomez@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 09:58:22 by dagomez           #+#    #+#             */
/*   Updated: 2023/01/30 17:16:36 by dagomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_void(void)
{
	system("leaks -q pipex");
}

void	clear_elements(char *a)
{
	free(a);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (1);
	pipex(argv, envp);
	return (0);
}
	//atexit(ft_void);
