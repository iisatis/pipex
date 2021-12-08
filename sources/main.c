/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:37:35 by pflorent          #+#    #+#             */
/*   Updated: 2021/12/08 19:34:16 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	err_display(int err)
{
	if (err == 1)
		perror("error, correct usage: ./pipex file1 cmd1 cmd2 file2\n");
	else if (err == 2)
		perror("error, something went wrong");
	else if (err == 3)
		perror("input file error");
	else if (err == 4)
		perror("output file error");
	else if (err == 5)
		perror("path error");
	else if (err == 6)
		perror("command not found");
	exit(EXIT_FAILURE);
}

static void	ft_exec(char *cmd, char *envp[])
{
	int		n;
	char	**cmnds;
	char	**paths;
	char	*path_buf;

	cmnds = ft_split(cmd, ' ');
	paths = paths_split(envp);
	if (paths == NULL)
		err_display(5);
	n = 0;
	while (paths[n])
	{
		path_buf = ft_join(paths[n], '/', cmnds[0]);
		if (access(path_buf, F_OK) == 0)
		{
			if (execve(path_buf, cmnds, NULL) == -1)
				err_display(2);
		}
		free(path_buf);
		n++;
	}
	clear(cmnds);
	clear(paths);
	err_display(2);
}

static void	exec_snd_cmnd(int *fd, char *argv[], char *envp[])
{
	int	out_fl;

	out_fl = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (out_fl < 0)
		err_display(4);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		err_display(2);
	if (dup2(out_fl, STDOUT_FILENO) == -1)
		err_display(2);
	close(fd[1]);
	close(out_fl);
	close(fd[0]);
	if (!*argv[3])
		err_display(6);
	ft_exec(argv[3], envp);
}

static void	exec_fst_cmnd(int *fd, char *argv[], char *envp[])
{
	int	in_fl;

	in_fl = open(argv[1], O_RDONLY);
	if (in_fl < 0)
		err_display(3);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		err_display(2);
	if (dup2(in_fl, STDIN_FILENO) == -1)
		err_display(2);
	close(fd[0]);
	close(in_fl);
	close(fd[1]);
	if (!*argv[2])
		err_display(6);
	ft_exec(argv[2], envp);
}

int	main(int argc, char *argv[], char*envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		err_display(1);
	if (pipe(fd) == -1)
		err_display(2);
	pid1 = fork();
	if (pid1 == -1)
		err_display(2);
	if (pid1 == 0)
		exec_fst_cmnd(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		err_display(2);
	if (pid2 == 0)
		exec_snd_cmnd(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
