/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:51:34 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/11/08 23:51:34 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Returns a line read from the fd
//fd      --> File descriptor
//return  --> Success (line read)
//return  --> Faillure (NULL)

char	*ft_join_free(char *buffer, char *tmp_buffer)
{
	char	*new_buffer;

	new_buffer = ft_strjoin(buffer, tmp_buffer);
	if (!new_buffer)
		return (free(tmp_buffer), free(buffer), NULL);
	free(buffer);
	return (new_buffer);
}

char	*ft_read_file(int fd, char	*buffer)
{
	char	*tmp_buffer;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp_buffer, BUFFER_SIZE * sizeof(char));
		if (bytes_read == -1)
			return (free(tmp_buffer), free(buffer), NULL);
		tmp_buffer[bytes_read] = '\0';
		buffer = ft_join_free(buffer, tmp_buffer);
		if (ft_strchr(tmp_buffer, '\n'))
			break ;
	}
	return (free(tmp_buffer), buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	len = ft_strlen_until(buffer, '\n');
	line = ft_calloc(len + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = ft_strlen_until(buffer, '\n');
	if (!buffer[i])
		return (free(buffer), NULL);
	line = ft_calloc((ft_strlen_until(buffer, '\0') - i + 1), sizeof(char));
	i += 1;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	return (free(buffer), line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_next_line(buffer);
	if (buffer && !*buffer) 
	{
        free(buffer);
        buffer = NULL;
	}
	return (line);
}
