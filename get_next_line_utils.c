/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonor <leonor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:19:33 by lcampos-          #+#    #+#             */
/*   Updated: 2023/07/31 00:31:43 by leonor           ###   ########.fr       */
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

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*together;

	i = 0;
	j = 0;
	together = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!together)
		return (NULL);
	while (str1 && str1[j])
		together[i++] = str1[j++];
	j = 0;
	while (str2 && str2[j])
	{
		together[i++] = str2[j];
		if (str2[j++] == '\n')
			break ;
	}
	together[i] = '\0';
	free(str1);
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
		buffer[j++] = 0;
}
