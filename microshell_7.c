#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define AF argv[s + f]


void	ft_error(char *s, char *s2)
{
	while(*s)
		write(2, s++, 1);
	if(s2)
		while(*s2)
			write(2, s2++, 1);
	write(2, "\n", 1);
}

void	ft_execute(char **argv, char **env, size_t i, int saved_fd)
{
	argv[i] = NULL;
	dup2(saved_fd, STDIN_FILENO);
	close(saved_fd);
	execve(argv[0], argv, env);
	ft_error("Failure exeve ", argv[0]);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	size_t	s;
	size_t	f;
	int	fd[2];
	int	saved_fd;
	(void) argc;

	s = 0;
	f = 0;
	saved_fd = dup(STDIN_FILENO);
	while (argv[f] && argv[f + 1])
	{
		s = f + 1;
		f = 0;
		while (AF && strcmp(AF, "|") && strcmp(AF, ";"))
				f++;
		if (!strcmp(argv[s], "cd"))
		{
			if (f != 2)
				ft_error("bad arg", NULL);
			else if (chdir(argv[s + 1]) != 0)
				ft_error("no perm", argv[s + 1]);
		}
		else if (f != 0 && (AF == NULL || !strcmp(AF, ";")))
		{
			if (fork() == 0)
				ft_execute(&argv[s], env, f, saved_fd);
			else
			{
				close(saved_fd);
				while (waitpid( -1, NULL, WUNTRACED) != -1)
				//while (waitpid( -1, NULL, WUNTRACED) != 1)
					;
				saved_fd = dup(STDIN_FILENO);
			}

		}
		else if (f != 0 && !strcmp(AF, "|"))
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
	return(0);
}
