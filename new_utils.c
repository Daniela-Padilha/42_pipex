

//info           --> Open file with specific flags depending on the process 
//					 that we are in
//file           --> Str with the name of the file
//child_or_not   --> Checks if we are in the child process
//return         --> Fd of the file openned, or -1 if error

int	open_file(char *file, int child_or_not)
{
	int	fd;

	if (child_or_not == 0)
		fd = open(file, O_RDONLY, 0777);
	if (child_or_not > 0)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(0);
	return (fd);
}

//info       --> Get path for the cmd
//cmd        --> Comand to be executed
//env        --> 
//return     --> The path

char	*get_path(char *cmd, char **env)
{

}