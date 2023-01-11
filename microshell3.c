#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int global_fd;

static int ft_strlen(char *str)
{
	int len = 0;
	
	while (str[len])
		len++;
	return (len);
}

int builtin_cd(char **argv)
{
	if (argv[2] && (!strcmp(argv[2], "|") || !strcmp(argv[2], ";")))
	{
		write(2, "error: cd: bad arguments\n", 25);
		return (1);
	}
	if (chdir(argv[1]) == -1)
	{
		write(2, "error: cd: cannot change directory to ", 38);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		return (1);
	}
	return (0);
}

static int exec_cmd(char **argv, char **envp, int i)
{
	int status;
	int pid;
	int next = 0;
	int fd[2];
	
	if (argv[i] && !strcmp(argv[i], "|"))
		next = 1;
	if (argv[i] == *argv)
		return (0);
	if (pipe(fd) == -1)
	{
		write(2, "error: fatal\n", 13);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		write(2, "error: fatal\n", 13);
		return (1);
	}
	else if (pid == 0)
	{
		dup2(global_fd, 0);
		argv[i] = 0;
		if (next)
			dup2(fd[1], 1);
		if (global_fd)
			close(global_fd);
		if (execve(*argv, argv, envp) == -1)
		{
			write (2, "error: cannot execute ", 22);
			write (2, *argv, ft_strlen(*argv));
			write (2, "\n", 1);
			return (1);
		}	
	}
	else
	{
		close (fd[1]);
		waitpid(pid, &status, 0);
		if (global_fd)
			close(global_fd);
		if(next)
			global_fd = dup(fd[0]);
		close(fd[0]);
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	int i = 1;

	if (argc == 1)
	{
		write(2, "error: bad arguments\n", 21);
		return (1);
	}
	argv[argc] = 0;
	while(argv[i - 1] && argv[i])
	{
		argv = argv + i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			builtin_cd(argv);
		else
			exec_cmd(argv, envp, i);
		i++;
	}
	return(0);
}