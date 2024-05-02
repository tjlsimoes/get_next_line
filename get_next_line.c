/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:45:08 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/02 11:15:19 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_with_lb_eof(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		chars_read;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
	chars_read = 5;
	while(idx_line_break(str) == -1 && chars_read)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		buffer[chars_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}


char	*get_next_line(int fd)
{
	static char	*mem;
	char		*remains;
	char		*str_til_lb_eof;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	mem = str_with_lb_eof(fd, mem);
	if(!mem)
		return (NULL);
	remains = get_substring(mem, idx_line_break(mem) + 1, -1);
	str_til_lb_eof = get_substring(mem, 0, idx_line_break(mem));
	free(mem);
	mem = remains;
	return (str_til_lb_eof);
}