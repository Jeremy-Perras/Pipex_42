/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:27:39 by jperras           #+#    #+#             */
/*   Updated: 2022/03/25 08:59:43 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
/*
void	run_pipe(void)
{
	int const	READ_END = 0;
	int const	WRITE_END = 1;
	pid_t		child = -1;
	char		*cmd1 = NULL;
	char		*cmd2 = NULL;
	char		*args1[3];
	char		*args2[3];
	int			pdes[2];

	cmd1 = "/bin/ls";
	args1[0] = cmd1;
	args1[1] = "-lF";
	args1[2] = NULL;

	cmd2 = "/bin/cat";
	args2[0] = cmd2;
	args2[1] = "-e";
	args2[2] = NULL;

	pipe(pdes);
	
	child = fork();
	switch ((int)child)
	{
		case -1:
			close(pdes[READ_END]);
			close(pdes[WRITE_END]);
			perror("error");
			break;
		case 0:
			dup2(pdes[WRITE_END], STDOUT_FILENO);
			close(pdes[READ_END]);
			execve(cmd1, args1, NULL);
			perror("error");
			break;
	}
	dup2(pdes[READ_END], STDIN_FILENO);
	close(pdes[WRITE_END]);
	wait(NULL);
	execve (cmd2, args2, NULL);
	return;
}

int main(void)
{
	pid_t	child = -1;
	
	child = fork();
	printf("%d",child);
	switch((int)child)
	{
		case -1:
			perror("error");
			break;
		case 0:
			run_pipe();
			perror("error");
			break;
	}
	wait(NULL);
	return (0);
}*/
#include <stdio.h>
int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	char	*argv1[4];
	pid_t	father = -1;

	argv1[0]="/bin/ls";
	argv1[1]="-a";
	argv1[2]="-l";
	argv1[3]=NULL;

	father = fork();
	
	if (father == 0)
	{
		sleep(3);
		execve("/bin/ls", argv1, NULL);
		printf("test2\n");
	}
	if (father > 0)
	{
		wait(NULL);
	   	printf("Je fais des testes : %s",env[0]);
	}
	
}
