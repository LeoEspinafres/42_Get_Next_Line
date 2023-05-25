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

int	ft_update_buffer(char *buffer)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (buffer[i])
	{
		if (flag)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			flag = 1;
		buffer[i] = '\0';
		i++;
	}
	return (flag);
}
