/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:20:02 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/06 17:57:07 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void *free_null_rt(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*str_with_lb_eof(int fd, char *str)
{
	char	*buffer;
	int		chars_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	chars_read = 5;
	while (idx_line_break(str) == -1 && chars_read)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (!chars_read)
			break ;
		if (chars_read < 0)
			return (free_null_rt(buffer));
		buffer[chars_read] = '\0';
		if (!str)
			str = ft_strjoin(NULL, buffer);
		else
			str = ft_strjoin(str, buffer);
		if (!str)
			return (free_null_rt(buffer));
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*mem[FD_MAX];
	char		*remains;
	char		*str_til_lb_eof;

	if (fd < 0 || BUFFER_SIZE < 1 )
		return (NULL);
	mem[fd - 3] = str_with_lb_eof(fd, mem[fd - 3]);
	if (!mem[fd - 3])
		return (NULL);
	remains = get_substring(mem[fd - 3], idx_line_break(mem[fd - 3]) + 1, -1, 1);
	str_til_lb_eof = get_substring(mem[fd - 3], 0, idx_line_break(mem[fd - 3]), 0);
	free(mem[fd - 3]);
	mem[fd - 3] = remains;
	return (str_til_lb_eof);
}
