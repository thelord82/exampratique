/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:04:38 by malord            #+#    #+#             */
/*   Updated: 2023/01/09 15:10:01 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int g_fd;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	executor(char **argv, int i, char **env)
{
	int	status;
	int	fd[2];
	int	pid;
	int	next = 0;

	if (argv[i] && strcmp(argv[i], "|") == 0)
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
		dup2(g_fd, 0);
		argv[i] = 0;
		if (next)
			dup2(fd[1], 1);
		if (g_fd != 0)
			close(g_fd);
		if (execve(*argv, argv, env) == -1)
		{
			write(2, "error: cannot execute ", 22);
			write(2, *argv, ft_strlen(*argv));
			write(2, "\n", 1);
			exit(1);
		}
	}
	else
	{
		close(fd[1]);
		waitpid(pid, &status, 0);
		if (g_fd != 0)
			close(g_fd);
		if (next)
			g_fd = dup(fd[0]);
		close(fd[0]);
	}
	return (0);
}

int	builtin_cd(char **argv)
{
	char cwd[10000];
	if (argv[2] && strcmp(argv[2], "|") != 0 && strcmp(argv[2], ";") != 0)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return (1);
	}
	if (chdir(argv[1]) == -1)
	{
		write(2, "error: cannot change directory to ", 34);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		return (1);
	}
	//else
	//{
	//	printf("on rentre\n");
	//	if (getcwd(cwd, sizeof(cwd)) != NULL)
	//		printf("Current working dir: %s\n", cwd);
	//}
	return (0);
}
int main (int argc, char **argv, char **envp)
{
	(void)envp;
	int i = 1;
	if (argc == 1)
	{
		write(2, "error: bad arguments\n", 21);
		return (1);
	}
	argv[argc] = 0;
	while (argv[i - 1] && argv[i])
	{
		argv = argv + i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
			i++;
		if (!strcmp(*argv, "cd"))
			builtin_cd(argv);
		else
			executor(argv, i, envp);
		i++;
	}
	return (0);
}