/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:45:08 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/06 11:35:36 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	update_end(int *end, int b, char const *s)
{
	*end = b;
	while (s[*end])
		*end = *end + 1;
}

char	*get_substring(char const *s, int b, int end, int remains)
{
	int		i;
	char	*substring;

	if (!s || (b == 0 && remains))
		return (NULL);
	if (end == -1)
		update_end(&end, b, s);
	substring = (char *)malloc((end - b) + 2);
	if (!substring)
		return (NULL);
	i = 0;
	while (b + i <= end && s[b + i])
	{
		substring[i] = s[b + i];
		i++;
	}
	substring[i] = '\0';
	if (substring[0] == '\0')
	{
		free(substring);
		return (NULL);
	}
	return (substring);
}

char	*str_with_lb_eof(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	int		chars_read;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
		buffer[i++] = '\0';
	chars_read = 5;
	while (idx_line_break(str) == -1 && chars_read)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (!chars_read)
			break ;
		if (chars_read < 0)
			return (NULL);
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

	// Buffer over INT_MAX
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	mem = str_with_lb_eof(fd, mem);
	if (!mem)
		return (NULL);
	remains = get_substring(mem, idx_line_break(mem) + 1, -1, 1);
	str_til_lb_eof = get_substring(mem, 0, idx_line_break(mem), 0);
	free(mem);
	mem = remains;
	return (str_til_lb_eof);
}
