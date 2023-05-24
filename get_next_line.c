/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcampos- <lcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:12:50 by lcampos-          #+#    #+#             */
/*   Updated: 2023/05/24 16:53:19 by lcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (buffer[i])
			buffer[i++] = 0;
		return (NULL);
	}
	while (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0))
	{
		line = ft_strjoin(line, buffer);
		if (ft_update_buffer(buffer))
			break ;
	}
	return (line);
}

// int main ()
// {
// 	int	fd;

//     fd = open("ola.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }