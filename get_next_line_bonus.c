/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonor <leonor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:25:45 by leonor            #+#    #+#             */
/*   Updated: 2023/07/31 00:32:12 by leonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			flag;

	i = -1;
	flag = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0) 
	{
		while (buffer[fd][++i])
			buffer[fd][i] = 0;
		return (NULL);
	}
	while (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buffer[fd]);
		ft_update_buffer(buffer[fd], &flag);
		if (flag)
			break ;
	}
	return (line);
}
