/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcampos- <lcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:19:33 by lcampos-          #+#    #+#             */
/*   Updated: 2023/05/15 15:52:05 by lcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*together;

	i = 0;
	together = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!together)
		return (NULL);
	while (*s1 != '\0')
		together[i++] = *s1++;
	while (*s2 != '\0' && *s2 != '\n')
		together[i++] = *s2++;
	together[i] = '\0';
	return (together);
}

int	ft_clean_buffer(char *buffer)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (buffer)
	{
		if (buffer[i] != '\n' && buffer[i])
		{	
			buffer[i] = '\0';
			i++;  
		}
		if (buffer[i] == '\n')
			flag = 1;
	}
	return (flag);
}
