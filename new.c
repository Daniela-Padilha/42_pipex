
//info     --> Execute a comand
//cmd      --> Comand to be executed
//env      --> 
//path     --> Path to the command
//cmd_args --> Array of the args of the command

void	exec_cmd(char *cmd, char **env)
{
	char	*path;
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	path = get_path();
	if (execve(path, cmd_args, env) == -1)
	{
		perror("ERROR: command not found. Execution failed");
		exit(0);
	}
}


//info       --> Create child routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], o read e o write
//env        --> 

void	child(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open_file(av[1], O);
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	exec_cmd(av[2], env);
}

//info       --> Create parent routine
//av         --> Arg that indicates the file to open
//pipe_fd    --> Pipe fd[2], o read e o write
//env        --> 

void	parent(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	exec_cmd(av[3], env);
}



