#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*output;

	fd = open("foo_f.txt", O_RDONLY);

	while((output = get_next_line(fd)))
	{
		printf("%s", output);
		free(output);
	}
	if (!output)
		printf("NULL\n");
	close(fd);
	// char buffer[BUFFER_SIZE];
	// int bytes_read = read(fd, buffer, BUFFER_SIZE);
	// printf("Bytes read: %d\n", bytes_read);
	// printf("Contentes buffer: %s\n", buffer);
	return (0);
}