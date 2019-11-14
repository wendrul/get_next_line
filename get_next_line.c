#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*aux_string;

	if (!(*line = (char*)malloc(1 * sizeof(char))))
		return (-1);
	(*line)[0] = '\0';
	if ()
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (bytes_read < 0)
			return (-1);
		buf[bytes_read] = '\0';
		if ((endl = indexof('\n', buff) != -1))
		{
			aux = *line;
			if (!(*line = ft_strjoin_size(*line, buf, endl + 1)))
				return (-1);
			free(aux);
			return (1);
		}
		else
		{
			aux = *line;
			if (!(*line = ft_strjoin_size(*line, buf, bytes_read)))
				return (-1);
			free(aux);
		}
	}
	return (0);
}
