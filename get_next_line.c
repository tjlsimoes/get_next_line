/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:02:48 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/29 13:54:21 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*buffer;
	int			i;

	if (fd < 0)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE))
		mem = ft_strjoin(mem, buffer);
	i = idx_line_break(mem);
	buffer = (char *)malloc(i + 2);
	if (i >= 0)
	{
		buffer[i + 1] = NULL;
		while (i)
		{
			buffer[i] = mem[i];
			i--;
			free(mem);
			return (buffer);
		}
	}
	else
		get_next_line(fd);
}
