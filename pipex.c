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
	char	*input;

	if (argc != 5)
		return (perror("WRONG NUMBER OF ARGS"), 1);
	fd1 = open(*argv[1], O_RDONLY);
	fd2 = open(*argv[4], O_WRONLY);
	if (fd == -1 || fd2 == -1)
		return (perror("OPEN FAILURE"), 1);
	exec_cmd(*argv[2]);
	input = read_file(fd1);
	write_file(fd2);

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

int	pipeline(void)
{
	pid_t	child1;
	pid_t	child2;
	int		pipefd[2];
	char 	*buf; ,

	pipefd = create_pipe(void);
	child1 = create_child(void);
	child2 = create_child(void);
	if (child1 == 0)
	{
		close(pipefd[0]);
		write(pipefd[1], &buf, ft_strlen(buf));
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}

	
	if (child2 == 0)
	{
		close(pipefd[1]);
		read(pipefd[0], &buf, ft_strlen(buf));
		close(pipefd[0]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	exec_cmd(char	*cmd)
{
	char	*path;
	int		i;
	int		len;

	path = "/bin/";
	cmd = argv[2];
	i = 0;
	len = ft_strlen(path);
	while (i <= len)
		path[len++] = cmd[i++];
	cmd[i] = '\0';
	if (access(path, X_OK) == -1)
		return (perror("ACCESS FAILED"), 1);
	if (execve(path, cmd, NULL) == -1)
		return (perror("EXEC FAILED"), 1);
	unlink(path);
}

void	write_file(int fd)
{
	fd = open(*argv[4], O_WRONLY);
	if (fd == -1)
		return (perror("OPEN FAILURE"), 1);
}

char	*read_file(int fd)
{
	char	*buf;

	buf = get_next_line(fd);
	while (buf != NULL)
	{
		ft_printf("%s", buf);
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	return (buf);
}

