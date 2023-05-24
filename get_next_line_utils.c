/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcampos- <lcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:19:33 by lcampos-          #+#    #+#             */
/*   Updated: 2023/05/24 16:59:41 by lcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

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
	together = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!together)
		return (NULL);
	while (s1 && s1[i])
		together[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
	{
		together[j] = s2[i++];
		if (together[j++] == '\n')
			break ;
	}
	together[i] = '\0';
	free(s1);
	return (together);
}

int	ft_update_buffer(char *buffer)
{
	int	j;
	int	i;
	int	flag;

	j = 0;
	i = 0;
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
