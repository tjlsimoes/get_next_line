/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:02:48 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/30 10:24:53 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem;
	int			read_output;
	char		*buffer;
	int			i;
	char		*end_string;

	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	read_output = read(fd, buffer, BUFFER_SIZE);
	if (read_output > 0)
	{
		mem = ft_strjoin(mem, buffer);
		if (!mem)
			return (NULL);
	}
	else if (read_output < 0)
		return (NULL);
	i = idx_line_break(mem);
	if (i >= 0)
	{
		end_string = (char *)malloc(i + 2);
		if (!end_string)
			return (NULL);
		end_string[i + 1] = '\0';
		while (i >= 0)
		{
			end_string[i] = mem[i];
			i--;
		}
		free(buffer);
		free(mem);
		return (end_string);
	}
	else
	{
		free(buffer);
		return (get_next_line(fd));
	}
}

// char	*get_next_line(int fd)
// {
// 	static char	*mem;
// 	int			read_output;
// 	char		buffer[BUFFER_SIZE];
// 	int			i;
// 	char		*end_string;

// 	if (fd < 0)
// 		return (NULL);
	
// 	read_output = read(fd, buffer, BUFFER_SIZE);
// 	if (read_output > 0)
// 	{
// 		mem = ft_strjoin(mem, buffer);
// 		if (!mem)
// 			return (NULL);
// 	}
// 	else if (read_output < 0)
// 		return (NULL);
// 	i = idx_line_break(mem);
// 	if (i >= 0)
// 	{
// 		end_string = (char *)malloc(i + 2);
// 		if (!end_string)
// 			return (NULL);
// 		end_string[i + 1] = '\0';
// 		while (i >= 0)
// 		{
// 			end_string[i] = mem[i];
// 			i--;
// 		}
// 		free(mem);
// 		return (end_string);
// 	}
// 	else
// 	{
// 		return (get_next_line(fd));
// 	}
// }

// char	*get_next_line(int fd)
// {
// 	static char	*mem;
// 	char		*buffer;
// 	int			i;

// 	buffer = (char *)malloc(BUFFER_SIZE);
// 	if (fd < 0)
// 		return (NULL);
// 	if (read(fd, buffer, BUFFER_SIZE))
// 		mem = ft_strjoin(mem, buffer);
// 	i = idx_line_break(mem);
// 	free(buffer);
// 	buffer = (char *)malloc(i + 2);
// 	if (i >= 0)
// 	{
// 		buffer[i + 1] = '\0';
// 		while (i)
// 		{
// 			buffer[i] = mem[i];
// 			i--;
// 		}
// 		free(mem);
// 		return (buffer);
// 	}
// 	else
// 		return (get_next_line(fd));
// }
