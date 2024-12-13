/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmgba <thmgba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:09:05 by thmgba            #+#    #+#             */
/*   Updated: 2024/12/13 21:39:39 by thmgba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	y;
	char	*dest;

	i = 0;
	y = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		dest[i] = s2[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}

size_t	check_char(char *buffer)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char *justoneline(char *str)
{
	char *dest;
	size_t	i;
	size_t	j;
	
	dest = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\n';
	if (str[i] == '\n')
	{
		i++;
		while (str[i])
			str[j++] = str[i++];
	}
	str[j] = '\0';
	return (dest);
}






