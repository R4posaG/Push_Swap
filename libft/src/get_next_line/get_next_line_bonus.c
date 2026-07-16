#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*next_line;
	ssize_t		bytes_read;

	next_line = NULL;
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !has_newline(next_line))
	{
		if (buffer[fd][0] == '\0')
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read == -1)
				return (buffer[fd][0] = '\0', free(next_line), NULL);
			if (bytes_read == 0)
				break ;
			buffer[fd][bytes_read] = '\0';
		}
		next_line = ft_strjoin(next_line, buffer[fd]);
		if (!next_line)
			return (NULL);
		update_buffer(buffer[fd]);
	}
	return (next_line);
}
