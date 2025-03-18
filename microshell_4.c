#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define SF argv[s + f]
#define MSG_EXE "error: cannot execute executable "
#define MSG_CD "error: cd: cannot change directory to "
#define MSG_BAD "error: cd: bad arguments"



void	ft_error(char *s, char *s2)
{
	while (*s)
		write(2, s++, 1);
	if (s2)
		while (*s2)
			write(2, s2++, 1);
	write(2, "\n", 1);
}

void	ft_execute(char **argv, char **env, size_t i, int saved_fd)
{
	argv[i] = NULL;
	dup2(saved_fd, STDIN_FILENO);
	close(saved_fd);
	execve(argv[0], argv, env);
	ft_error(MSG_EXE, argv[0]);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	size_t	s;
	size_t	f;
	int	saved_fd;
	int	fd[2];
	(void)	argc;

	s = 0;
	f = 0;
	saved_fd = dup(STDIN_FILENO);
	while (argv[f] && argv[f + 1])
	{
		s = f + 1;
		f = 0;
		while (SF && strcmp(SF, "|") && strcmp(SF, ";"))
			f++;
		if (strcmp(argv[s], "cd") == 0)
		{
			if ( f != 0)
				ft_error(MSG_BAD, NULL);
			else if (chdir(argv[s + 1]) != 0)
				ft_error(MSG_CD, argv[s + 1]);
		}
		else if (f != 0 && ( SF == NULL || strcmp(SF, ";") == 0))
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
		else if (f != 0 && strcmp(SF, "|") == 0)
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
