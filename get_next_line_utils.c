/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:05:57 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/30 13:31:29 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	idx_line_break(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += 1;
		i += 1;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	int		i;

	s1_len = ft_strlen(s1);
	str = (char *)malloc(s1_len + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[i - s1_len] != '\0')
		{
			str[i] = s2[i - s1_len];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

void	putline_fd(char *s, int fd)
{
	int	i;

	if (!s)
		write(fd, "(null)", 6);
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		if (s[i] == '\n')
			return ;
		i++;
	}
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i += 1;
	}
	return (str);
}

char	*get_substring(char const *s, int b, int end)
{
	int		i;
	char	*substring;

	if (!s)
		return (NULL);
	if (end == -1)
	{
		end = b;
		while (s[end])
			end++;
	}
	substring = (char *)malloc((end - b) + 1);
	if (!substring)
		return (NULL);
	i = 0;
	while (b + i < end && s[b + i])
	{
		substring[i] = s[b + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}