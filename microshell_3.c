#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define	AR argv[s + f]
#define	MSG_CD "ciao cd "
#define	MSG_BAD	"cattivi arggg "
#define	MSG_EXE	"exe non va porca madonna "




void ft_error(char *s, char *s1)
{
	while (*s)
		write(2, s++, 1);
	if (s1)
		while(*s1)
			write(2, s1++, 1);
	write(2, "\n", 1);
}

void	ft_execute(char **agrv, char **env, size_t i, int saved_fd)
{
	agrv[i] = NULL;
	dup2(saved_fd, STDIN_FILENO);
	close(saved_fd);
	execve(agrv[0], agrv, env);
	ft_error(MSG_EXE, agrv[0]);
	exit(1);
}

int	main(int argc, char **argv, char **env)
{
	size_t	f;
	size_t	s;
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
		while (AR && strcmp(AR, "|") && strcmp(AR, ";"))
			f++;
		if (strcmp(argv[s], "cd") == 0)
		{
			if (f != 2)
				ft_error(MSG_BAD, NULL);
			else if (chdir(argv[s + 1]) != 0)
				ft_error(MSG_CD, argv[s + 1]);
		}
		else if (f != 0 && ( AR == NULL || strcmp(AR, ";") == 0))
		{
			if (fork() == 0)
				ft_execute(&argv[s], env, f, saved_fd);
			else
			{
				close(saved_fd);
				while ( waitpid( -1, NULL, WUNTRACED) != -1)
					;
				saved_fd = dup(STDIN_FILENO);
			}
		}
		else if (f != 0 && strcmp(AR, "|") == 0)
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
