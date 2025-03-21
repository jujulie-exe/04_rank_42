

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#define ERROR_MSG_EXE "error: cannot execute executable "
#define ERROR_MSG_CD ""
#define START_AND	(start_index + end_index)

void	ft_putstr_fd2(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
		while(*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
}


void ft_execute(char **arg, int saved_fd, size_t index, char **env)
{
	arg[index] = NULL;
	dup2(saved_fd, STDIN_FILENO);
	close(saved_fd);
	execve(arg[0], arg, env);
	ft_putstr_fd2("ciao", arg[0]);
	exit(1);
}


int	main(int argc, char *argv[], char *env[])
{
	int	i;
	int fd[2];
	int tmp_fd;
	size_t y;
	(void)argc;
	
	i = 0;
	y = 0;
	tmp_fd = dup(STDIN_FILENO);
	while (argv[i] && argv[i + 1])
	{
		y = i + 1;
		i = 0;
		while (argv[y + i] && strcmp(argv[y + i], ";") != 0 && strcmp(argv[y + i], "|") != 0)
			i++;
		if (strcmp(argv[y], "cd") == 0) //cd
		{
			if (i != 2)
				ft_putstr_fd2("error: cd: bad arguments", NULL);
			else if (chdir(argv[y + 1]) != 0)
				ft_putstr_fd2("error: cd: cannot change directory to ", argv[y + 1]);
		}
		else if (i != 0 && (argv[y + i] == NULL || strcmp(argv[y + i], ";") == 0)) //exec in stdout
		{
			if (fork() == 0)
				ft_execute(&argv[y], i, tmp_fd, env);
			else
			{
				close(tmp_fd);
				while(waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if(i != 0 && strcmp(argv[y + i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				ft_execute(&argv[y], i, tmp_fd, env);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
		i = y + i;
	}
	close(tmp_fd);
	return (0);
}
