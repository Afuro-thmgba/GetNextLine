/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmgba <thmgba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:06 by thmgba            #+#    #+#             */
/*   Updated: 2024/12/14 19:52:28 by thmgba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char static	*str = NULL;
	char		*buffer;
	char		*dest;
	int			bite_read;

	str = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!str)
		return (ft_free(str), NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (ft_free(str), NULL);
	while(1)
	{
		bite_read = read (fd, buffer, BUFFER_SIZE);
		buffer[bite_read] = '\0';
		if (bite_read == 0 && ft_strlen(str) == 0)
			return (ft_free(buffer), ft_free(str), NULL);
		if (str[0] == '\0')
			ft_buffertostr(str, buffer);
		if (checkchar(buffer) == 1)
		{
			dest = ft_keeptherest(str);
			return (dest);
		}
		if (buffer)
			str = ft_strjoin(str, buffer);
	}
	
}

void ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void ft_buffertostr(char *str, char* buffer)
{
	size_t	i;

	i = 0;

	while (buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
}

char *ft_keeptherest(char *str)
{
	char *dest;
	size_t	i;
	size_t	j;
	
	dest = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (ft_free(dest), NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' || str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\n';
	i++;
	while (str)
		str[j++] = str[i++];
	str[j] = '\0';
	return (dest);
}

int	checkchar(char *buffer)
{
	size_t i;

	i = 0;
	while(buffer)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return(1);
		i++;
	}
	return(0);
}

int main(void)
{
    int fd = open("coc9.txt", O_RDONLY);
    char *str;

    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
	}
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
    close(fd);
    return 0;
}
