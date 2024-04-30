#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*output;

	fd = open("foo.txt", O_RDWR);
	output = get_next_line(fd);
	if (!output)
		printf("NULL\n");
	else
	{
		printf("%s\n", output);
		free(output);
	}
	close(fd);
	// char buffer[BUFFER_SIZE];
	// int bytes_read = read(fd, buffer, BUFFER_SIZE);
	// printf("Bytes read: %d\n", bytes_read);
	// printf("Contentes buffer: %s\n", buffer);
	return (0);
}