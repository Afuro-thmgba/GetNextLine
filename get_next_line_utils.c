/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuro <afuro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:09:05 by thmgba            #+#    #+#             */
/*   Updated: 2025/01/08 13:04:22 by afuro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
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
	dest = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
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
	s2[0] = '\0';
	ft_free(s1, NULL);
	return (dest);
}

void	*ft_calloc( size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	array = malloc(size * nmemb);
	if (!array)
		return (NULL);
	while (i < nmemb)
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}

void	ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
}

int	checkendchar(char	*str)
{
	int	i;
	int	bool;

	i = 0;
	bool = 0;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == '\n')
			bool++;
		if (str[i] != '\n' && str[i + 1] == '\0')
			bool++;
	}
	return (bool);
}
