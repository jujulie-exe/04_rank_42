#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define	MSG_EXE ""
#define	MSG_CD ""
#define	MSG_BAD_ARG ""
#define	AR argv[s + f]
void	ft_error(char *s, char *s2)
{
	if (s2)
		while (*s2)
			write(2, s2++, 1);
	write(2, "Error\n", 6);
}

void	ft_execute(char **arg, char **env, size_t i, int saved_fd)
{
	arg[i] = NULL;
	dup2(saved_fd, STDIN_FILENO);
	close(saved_fd);
	execve(arg[0], arg, env);
	//ft_error("MSG_EXE", arg[0]);
	exit (1);	
}


int	main(int argc, char **argv, char **env)
{
	size_t	f;
	size_t	s;
	int	saved_fd;
	int	fd[2];
	(void)	argc;

	s = 0;
	f = 0;
	saved_fd = dup(STDIN_FILENO);
	while(argv[f] && argv[f + 1])
	{
		s = f + 1;
		f = 0;
		while(argv[s + f] && strcmp(argv[s + f], "|") && strcmp(argv[s + f], ";"))
			f++;
		if (strcmp(argv[s], "cd") == 0)
		{
			if (f != 2)
				ft_error("MSG_CD", NULL);
			else if (chdir(argv[s + 1]) != 0)
				ft_error("MSG_BAD_ARG", argv[s + 1]);
		}
		else if ( f != 0 && (argv[s + f] == NULL || strcmp(argv[s + f], ";") == 0))
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
		else if (f != 0 && strcmp(argv[s + f] , "|") == 0)
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
