int		ft_strcdup(char *buf, char **line, char c, int sizen )
{
	int i;

	if (!(*line = (char*)malloc((size + 1) * sizeof(*buf))))
		return (0);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		*(line)[i])= buf[i];
	}
	line[i] = '\n'
}
