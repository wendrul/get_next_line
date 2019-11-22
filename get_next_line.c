/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:14:56 by ede-thom          #+#    #+#             */
/*   Updated: 2019/11/15 18:05:40 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char				buf[BUFFER_SIZE + 1];
	static t_buf_hist	hist = NULL;
	char				*last_buf;
	int					bytes_read;
	int					error_no;

	if(!(last_buf = get_last_from_fd(fd, &hist)))
		return (-1);
	if (!(*line = (char*)malloc(sizeof(char))))
		return (-1);
	(*line)[0] = '\0';
	if (ft_strjoin_endl(line, last_buf, &error_no))
		return (error_no);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (bytes_read == -1)
			return (-1);
		buf[BUFFER_SIZE] = '\0';
		ft_memmove(last_buf, buf, BUFFER_SIZE + 1);
		if (ft_strjoin_endl(line, last_buf, &error_no))
			return (error_no);
	}
	hist = remove_fd_from_hist(fd, hist);
	return (0);
}

int		ft_strjoin_endl(char **line, char *s2, int *error_no)
{
	int		s2_len;
	int		line_len;
	char 	*s1;
	char	*new;

	s1 = *line;
	s2_len = 0;
	line_len = 0;
	while (s1[line_len])
		line_len++;
	while (s2[s2_len] && s2[s2_len] != '\n')
		s2_len++;
	if (!(new = (char*)malloc(sizeof(*new) * (1 + line_len + s2_len))))
	{
		*error_no = -1;
		return (1);
	}
	ft_memmove(new, s1, line_len);
	ft_memmove(new + line_len, s2, s2_len);
	new[line_len + s2_len] = '\0';
	free(s1);
	*line = new;
	if (s2[s2_len] == '\n')
	{
		*error_no = 1;
		while (s2[s2_len] == '\n')
			s2_len++;
		ft_memmove(s2, s2 + s2_len, BUFFER_SIZE + 1 - s2_len); 
		return (1);
	}
	s2[0] = '\0';
	return (0);	
}
