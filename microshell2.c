/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malord <malord@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:04:38 by malord            #+#    #+#             */
/*   Updated: 2023/01/06 15:05:44 by malord           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int g_fd;

static int	print(char *string)
{
	int	length = 0;

	while (string[length])
		length++;
	write(2, string, length);
	return (1);
}

int	count_commands(char **argv)
{
	int i = 0;
	int count = 1;
	while (argv[i])
	{
		if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
			count++;
		i++;
	}
	printf("count = %d\n", count);
	return (count);
}

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
		return (print("error: fatal\n"));
	pid = fork();
	if (pid == -1)
		return (print("error: fatal\n"));
	else if (pid == 0)
	{
		//close(fd[0]);
		dup2(g_fd, 0);
		argv[i] = 0;
		if (next)
			dup2(fd[1], 1);
		if (g_fd != 0)
			close(g_fd);
		//close(fd[1]);
		if (execve(*argv, argv, env) == -1)
		{
			print("error: cannot execute ");
			print(*argv);
			print("\n");
			exit(0);
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
	//if (!argv[i + 1])
	//{
	//	write (2, "error: cd: bad arguments\n", 25);
	//	return (1);
	//}
	//if (chdir(argv[i + 1]) != 0)
	//{
	//	write(2, "error: cd: cannot change directory to ", 38);
	//	write(2, argv[i + 1], ft_strlen(argv[i + 1]));
	//	write (2, "\n", 1);
	//	return (1);
	//}
	
	if (argv[2] && strcmp(argv[2], "|") != 0 && strcmp(argv[2], ";") != 0)
		return (print("error: cd : bad arguments\n"));
	if (chdir(argv[1]) == -1)
	{
		write(2, "error: cannot change directory to ", 34);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		return (1);
	}
	else
	{
		printf("on rentre\n");
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("Current working dir: %s\n", cwd);
	}
	return (0);
}
int main (int argc, char **argv, char **envp)
{
	(void)envp;
	//pid_t pid;
	//int fd[2];
	int i = 1;
	//int j = 0;
	if (argc == 1)
	{
		write(2, "error: bad arguments\n", 21);
		return (1);
	}
	//int count = count_commands(argv);
	//printf("Count commands = %d\n", count);
	//int test_fd = open("result.txt", O_WRONLY | O_APPEND);
	//dup2(test_fd, 1);
	//int count = count_commands(argv);
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
	//for (int i = 1; argv[i]; i++)
	//{
	//	if (!strcmp(argv[i], "cd"))
	//	{
	//		builtin_cd(argv, i);
	//		while (count > 1)
	//		{
	//			//pid = fork();
	//			//if (!pid)
	//			//{
	//			//	write(2, "error: fatal\n", 13);
	//			//	return (1);
	//			//}
	//			//else
	//			{
	//				//dup2(fd[1], 1);
	//				//execve(argv[i], argv, envp);
	//			}
	//			count--;
	//		}
	//	}
	//}
	return (0);
}