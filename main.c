#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include "get_next_line.h"

// Bonus:

// Single file descriptor

int	main(void)
{
	int		fd;
	char	*output;
	int		i;

	fd = open("foo_i.txt", O_RDONLY);
	i = 0;
	// while((output = get_next_line(fd)))
	// {
	// 	printf("%s", output);
	// 	free(output);
	// 	output = NULL;
	// 	i++;
	// }
	while (i < 6)
	{
		output = get_next_line(fd);
		if (output)
		{
			printf("%s", output);
			free(output);
		}
		if (!output)
			printf("NULL\n");
		i++;
	}
	// output = get_next_line(fd);
	// if (output)
	// {
	// 	printf("%s", output);
	// 	free(output);
	// }
	// if (!output)
	// 	printf("NULL\n");
	close(fd);
	// char buffer[BUFFER_SIZE];
	// int bytes_read = read(fd, buffer, BUFFER_SIZE);
	// printf("Bytes read: %d\n", bytes_read);
	// printf("Contentes buffer: %s\n", buffer);
	return (0);
}

// Multi file descriptors

// int	main(void)
// {
// 	int		fd_a;
// 	int		fd_b;
// 	char	*output;
// 	// int		i;

// 	fd_a = open("foo_i.txt", O_RDONLY);
// 	fd_b = open("foo_g.txt", O_RDONLY);


// 	output = get_next_line(fd_a);
// 	if (output)
// 	{
// 		printf("%s", output);
// 		free(output);
// 	}
// 	if (!output)
// 		printf("NULL\n");
// 	output = get_next_line(fd_b);
// 	if (output)
// 	{
// 		printf("%s", output);
// 		free(output);
// 	}
// 	if (!output)
// 		printf("NULL\n");
// 	output = get_next_line(fd_a);
// 	if (output)
// 	{
// 		printf("%s", output);
// 		free(output);
// 	}
// 	if (!output)
// 		printf("NULL\n");
// 	// i = 0;
// 	// while (i < 6)
// 	// {
// 	// 	output = get_next_line(fd);
// 	// 	if (output)
// 	// 	{
// 	// 		printf("%s", output);
// 	// 		free(output);
// 	// 	}
// 	// 	if (!output)
// 	// 		printf("NULL\n");
// 	// 	i++;
// 	// }
// 	// output = get_next_line(fd);
// 	close(fd_a);
// 	close(fd_b);
// 	return (0);
// }


// Mandatory:

// int	main(void)
// {
// 	int		fd;
// 	char	*output;
// 	int		i;

// 	fd = open("foo_i.txt", O_RDONLY);
// 	i = 0;
// 	// while((output = get_next_line(fd)))
// 	// {
// 	// 	printf("%s", output);
// 	// 	free(output);
// 	// 	output = NULL;
// 	// 	i++;
// 	// }
// 	while (i < 6)
// 	{
// 		output = get_next_line(fd);
// 		if (output)
// 		{
// 			printf("%s", output);
// 			free(output);
// 		}
// 		if (!output)
// 			printf("NULL\n");
// 		i++;
// 	}
// 	output = get_next_line(fd);
// 	// if (output)
// 	// {
// 	// 	printf("%s", output);
// 	// 	free(output);
// 	// }
// 	// if (!output)
// 	// 	printf("NULL\n");
// 	close(fd);
// 	// char buffer[BUFFER_SIZE];
// 	// int bytes_read = read(fd, buffer, BUFFER_SIZE);
// 	// printf("Bytes read: %d\n", bytes_read);
// 	// printf("Contentes buffer: %s\n", buffer);
// 	return (0);
// }