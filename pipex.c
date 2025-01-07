/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:07:52 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/12/27 17:07:52 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"


int	main(int argc, char **argv)
{
	int	fd1;
	int	fd2;
	int bytes_read;

	if (argc != 5)
		return (perror("WRONG NUMBER OF ARGS"), 1);
	fd1 = read_file(1);
	fd2 = write_file(4);
	exec_cmd(2);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd1, 1, BUFFER_SIZE * sizeof(char));
		if (bytes_read == -1)
			return (free(tmp_buffer), free(buffer), NULL);

	input = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	input = read_file(fd1, input);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		write(fd2, &input[i], 1);
		i++;
	}
	return (close(fd1), close(fd2), free(input), 0);
}
}

pipex()
{
	pipeline(); 
	// In parent process
	close(pipefd[0]); // Close read end
	close(pipefd[1]); // Close write end

	// Wait for both children to finish
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);

	free(pipefd); // Free allocated memory
	return (0);
}

//creates a pipeline, with 2 children and a pipe. Closing the unused ends of the pipe for each child.
void	pipeline(void)
{
	pid_t	child1;
	pid_t	child2;
	int		*pipefd;
	char 	*buf_write;
	char 	buf_read[100];
	ssize_t	bytes_written; 
	ssize_t	bytes_read;

	buf_write = read_file();
	pipefd = create_pipe();
	if (!pipefd)
		return (1);
	child1 = create_child();
	if (child1 == -1)
		return (free(pipefd), 1);
	child2 = create_child();
	if (child2 == -1)
	{
		clean_up(&child1, 1);
		return (free(pipefd), 1);
	}
	if (child1 == 0)
	{
		close(pipefd[0]);
		bytes_written = write(pipefd[1], buf_write, strlen(buf_write));
		if (bytes_written == -1)
		{
			perror("WRITE ERROR");
			close(pipefd[1]);
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	if (child2 == 0)
	{
		close(pipefd[1]);
		bytes_read = read(pipefd[0], buf_read, sizeof(buf_read) - 1);
		if (bytes_read == -1)
		{
			perror("READ ERROR");
			close(pipefd[0]);
			exit(EXIT_FAILURE);
		}
		buf_read[bytes_read] = '\0'; // Null-terminate the string
		printf("Child2 received: %s\n", buf_read);
		close(pipefd[0]);
		exit(EXIT_SUCCESS);
	}
}



// takes a int to define what argv[n] we want to execute a comand from.
void	exec_cmd(int n)
{
	char	*path;
	int		i;
	int		len;
	char	*cmd;

	path = "/bin/";
	cmd = *argv[n];
	i = 0;
	len = ft_strlen(path);
	while (i <= len)
		path[len++] = cmd[i++];
	path[len] = '\0';
	if (access(path, X_OK) == -1)
		return (perror("ACCESS FAILED"), 1);
	if (execve(path, cmd, NULL) == -1)
		return (perror("EXEC FAILED"), 1);
	unlink(path);
}

// takes a int to define what argv[n] we want to write in.
int	write_file(int n)
{
	int	fd;

	fd = open(ft_atoi(*argv[n]), O_WDONLY);
	if (fd == -1)
		return (perror("OPEN (WRITE) FAILURE"), 1);
	return (fd);
}

// takes a int to define what argv[n] we want to read from.
int read_file(int n)
{
	int	fd;

	fd = open(ft_atoi(*argv[n]), O_RDONLY);
	if (fd == -1)
		return (perror("OPEN (READ) FAILURE"), 1);
	return (fd);
}


