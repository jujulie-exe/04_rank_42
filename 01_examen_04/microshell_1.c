#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


void	ft_error(char *s, char *s1)
{
	while(*s)
		write(2, s++, 1);
	if(s1)
		while(*s1)
			write(2, s1++, 1);
	write(2, "\n", 1);
}


void	ft_execute(char **arg, char **env, size_t i, int saved_fd)
{
	arg[i] = NULL;
	dup2(saved_fd, STDIN_FILENO);
	close(saved_fd);
	execve(arg[0], arg, env);
	ft_error("ciao ", arg[0]);
	exit (1);
}

int	main(int argc, char **argv, char **env)
{
	size_t	s;
	size_t	f;
	int	saved_fd;
	int	fd[2];
	(void)	argc;

	f = 0;
	s = 0;
	saved_fd = dup(STDIN_FILENO);
	while(argv[f] && argv[f + 1])
	{
		s = f + 1;
		f = 0;
		while(argv[f + s] && strcmp(argv[f + s], "|") && strcmp(argv[s + f], ";"))
			f++;
		if (strcmp(argv[s], "cd") == 0)
		{
			if (f != 2)
				ft_error("bad argument", NULL);
			else if (chdir(argv[s + 1]) != 0)
				ft_error("dont exist", argv[s + 1]);
		}
		else if (f != 0 && (argv[f + s] == NULL || strcmp(argv[s + f], ";") == 0))
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
		else if (f != 0 && strcmp(argv[f + s], "|") == 0)
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
