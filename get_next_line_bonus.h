/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:19:48 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/06 17:57:02 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif
#ifndef FD_MAX
# define FD_MAX 4096
#endif
# include <unistd.h>
# include <stdlib.h>

int		ft_strcpy(char *str, char *s, int start);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*get_substring(char const *s, int b, int end, int remains);
int		idx_line_break(char *str);
void	update_end(int *end, int b, char const *s);

#endif