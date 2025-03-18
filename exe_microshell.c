/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_microshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:37:34 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/18 11:30:17 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void ft_error(char *s, char *s2)
{
	while (*s)
		write(2, s++, 1);
	if (s2 != NULL)
		while (*s2)
			write(2, s2++, 1);
	write(2, "\n", 1);
}

void	ft_execute(char **arg, char **env, size_t i, int saved_fd)
{
	arg[i] = NULL;
	dup2(saved_fd, STDIN_FILENO);
	close(saved_fd);
	execve(arg[0], arg, env);
	ft_error("error ", arg[0]);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	size_t	f;
	size_t	s;
	int	saved_fd;
	int	fd[2];

	f = 0;
	s = 0;
	saved_fd = dup(STDIN_FILENO);
	while (argv[f] && argv[f + 1])
	{
		s = f + 1;
		f = 0;
		while (argv[s + f] != NULL && strcmp(argv[s + f], ";") && strcmp(argv[s + f], "|"))
				f++;
		if (strcmp(argv[s], "cd") == 0)
		{
			if ( f != 2)
				ft_error("bad argument", NULL);
			if (chdir(argv[s + 1]) != 0)
				ft_error("not exist", argv[s]);
		}
		else if (f != 0 && (argv[f + s] == NULL || strcmp(argv[f + s], ";") == 0))
		{
			if (fork() == 0)
				ft_execute(&argv[s], env, f, saved_fd);
			else
			{
				close(saved_fd);
				while (waitpid( -1, NULL, WUNTRACED) != -1)
					;
				saved_fd = dup(STDIN_FILENO);
			}
		}
		else if (f != 0 && strcmp(argv[s + f], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				ft_execute(&argv[s], env, f, saved_fd);
			}
			else
			{
				close(fd[1]);
				close(saved_fd);
				saved_fd = fd[0];
			}
		}
		f = f + s;
	}
	close(saved_fd);
	return (0);
}

