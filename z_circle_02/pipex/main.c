#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void	ft_execute_cmd(char *cmd, int input_fd, int output_fd)
{
	if (dup2(input_fd, STDIN_FILENO) == -1 || dup2(output_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	execlp(cmd, cmd, NULL);
	perror("execlp");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <command1> <command2>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		ft_execute_cmd(argv[1], STDIN_FILENO, fd[1]);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		ft_execute_cmd(argv[2], fd[0], STDOUT_FILENO);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (EXIT_SUCCESS);
}
