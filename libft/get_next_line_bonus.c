/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:49:36 by ddo-carm          #+#    #+#             */
/*   Updated: 2024/12/07 13:49:36 by ddo-carm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//info    --> Returns a line read from the fd
//fd      --> File descriptor
//return  --> Success (line read)
//return  --> Faillure (NULL)

char	*ft_join_free(char *text, char *buffer)
{
	char	*new_text;

	new_text = ft_strjoin(text, buffer);
	if (!new_text)
		return (free(buffer), free(text), NULL);
	free(text);
	return (new_text);
}

char	*ft_read_file(int fd, char	*text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(text), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE * sizeof(char));
		if (bytes_read == -1)
			return (free(buffer), free(text), NULL);
		buffer[bytes_read] = '\0';
		text = ft_join_free(text, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), text);
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
		line[i] = buffer [i];
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
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_extract_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	if (buffer && !*buffer) 
	{
        	free(buffer);
        	buffer = NULL;
	}
	return (line);
}
