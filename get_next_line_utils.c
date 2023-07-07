/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcampos- <lcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:19:33 by lcampos-          #+#    #+#             */
/*   Updated: 2023/05/25 14:56:55 by lcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*together;

	i = 0;
	j = 0;
	together = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!together)
		return (NULL);
	while (line && line[j])
		together[i++] = line[j++];
	j = 0;
	while (buffer && buffer[j])
	{
		together[i++] = buffer[j];
		if (buffer[j++] == '\n')
			break ;
	}
	together[i] = '\0';
	free(line);
	return (together);
}

void	ft_update_buffer(char *buffer, int *flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (buffer[i] == '\n')
		*flag = 1;
	while (buffer[i] && buffer[i] != '\n')
	{
		if (buffer[i + 1] == '\n')
			*flag = 1;
		i++;
	}
	i++;
	while (i < BUFFER_SIZE)
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = 0;
		j++;
	}
}
