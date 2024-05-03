/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:05:57 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/03 10:19:40 by tjorge-l         ###   ########.fr       */
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

int	ft_strcpy(char *str, char *s, int start)
{
	int		i;

	i = start;
	if (s)
	{
		while (s[i - start] != '\0')
		{
			str[i] = s[i - start];
			i++;
		}
	}
	return (i);
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
	i = ft_strcpy(str, (char *)s1, i);
	i = ft_strcpy(str, (char *)s2, s1_len);
	str[i] = '\0';
	return (str);
}
