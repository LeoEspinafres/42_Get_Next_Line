/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcampos- <lcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:12:50 by lcampos-          #+#    #+#             */
/*   Updated: 2023/05/15 17:29:29 by lcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 500

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*together;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	together = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!together)
		return (NULL);
	if (s1)
	{
		while (s1[j] != '\0')
		{	
			together[j] = s1[j];
			j++;
		}
	}
	while (s2)
	{
		together[j++] = s2[i++];
		if (s2[i] == '\n')
			break ;
	}
	together[i] = '\0';
	free (s1);
	return (together);
}

int	ft_clean_buffer(char *buffer)
{
	int	i;
	int	j;
	int new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (buffer[i] != 0 && buffer[i] != '\n')
		buffer[i++] = '\0';
	if (buffer[i] == '\n')
	{
		new_line = 1;
		buffer[i++] = '\0';
		while (buffer[i] != 0)
		{
			buffer[j++] = buffer[i];
			buffer[i++] = '\0';
		}
	}
	return new_line;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	while (read(fd, buffer, BUFFER_SIZE) > 0 || buffer[0] != '\0')
	{
		line = ft_strjoin(line, buffer);
		if (ft_clean_buffer(buffer))
			break ;
	}
	return (line);
}

int	main(void)
{
	int fd = open("ola.txt", O_RDONLY);
	char *line;
	while (line = get_next_line(fd))
	{
		printf("%s", line);
	}
	close(fd);

	return (0);
}