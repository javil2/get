/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javlopez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:31:11 by javlopez          #+#    #+#             */
/*   Updated: 2022/10/02 14:36:14 by javlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* modify ft_strjoin () and ft_substr() with free()                           */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*fd_file[4096];
	ssize_t		t_bytes;	

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	if (!fd_file[fd])
	{
		fd_file[fd] = malloc (1 * sizeof(char));
		fd_file[fd][0] = '\0';
	}
	t_bytes = ft_read_file (fd_file, fd);
	if ((t_bytes < 1) && (ft_strlen (fd_file[fd]) == 0))
	{
		free (fd_file[fd]);
		fd_file[fd] = NULL;
		return (NULL);
	}
	else
		return (ft_cut_line (fd_file, fd));
}

ssize_t	ft_read_file(char **fd_file, int fd)
{
	ssize_t	n_bytes;
	char	*buffer;

	if (ft_strchr(fd_file[fd], '\n'))
		n_bytes = 0;
	else
	{
		buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		n_bytes = read(fd, buffer, BUFFER_SIZE);
		while (n_bytes > 0)
		{
			buffer[n_bytes] = '\0';
			fd_file[fd] = ft_strjoin(fd_file[fd], buffer);
			if (ft_strchr(fd_file[fd], '\n'))
				break ;
			else
				n_bytes = read(fd, buffer, BUFFER_SIZE);
		}
		free (buffer);
	}
	return (n_bytes);
}

char	*ft_cut_line(char **fd_file, int fd)
{
	char		*line;
	ssize_t		t_line;
	ssize_t		t_bytes;

	t_line = 0;
	t_bytes = ft_strlen (fd_file[fd]);
	while (fd_file[fd][t_line] != '\n' && t_line < t_bytes)
		t_line++;
	line = malloc ((t_line + 1) * sizeof(char));
	line[t_line + 1] = '\0';
	ft_memcpy(line, fd_file[fd], t_line + 1);
	t_bytes = t_bytes - t_line;
	if (t_bytes == 0)
	{
		free (fd_file[fd]);
		fd_file[fd] = NULL;
	}
	else
		fd_file[fd] = ft_substr(fd_file[fd], t_line + 1, t_bytes);
	return (line);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || *s == '\0')
	{
		sub = malloc (1 * sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	free (s);
	return (sub);
}
