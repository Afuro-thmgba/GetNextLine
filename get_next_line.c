/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmgba <thmgba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:06 by thmgba            #+#    #+#             */
/*   Updated: 2024/12/19 01:51:56 by thmgba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	char		*dest;
	int			bite_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(str), NULL);
	if (!str)
		str = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer && !str)
		return (ft_free(str), ft_free(buffer), NULL);
	while (1)
	{
		bite_read = read (fd, buffer, BUFFER_SIZE);
		if ((bite_read == 0 && ft_strlen(str) == 0) || bite_read == -1)
			return (ft_free(buffer), ft_free(str), NULL);
		if (str[0] == '\0')
			ft_buffertostr(str, buffer);
		if (checkchar(buffer) == 1 || bite_read == 0)
		{
			str = ft_strjoin(str, buffer);
			dest = ft_keeptherest(str);
			return (ft_free(buffer), dest);
		}
		str = ft_strjoin(str, buffer);
	}
}

void	ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void	ft_buffertostr(char *str, char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	buffer[0] = '\0';
}

char	*ft_keeptherest(char *str)
{
	char	*dest;
	size_t	i;
	size_t	j;

	dest = ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (!dest)
		return (ft_free(dest), NULL);
	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		dest[i++] = '\n';
	while (str[i])
		str[j++] = str[i++];
	str[j] = '\0';
	return (dest);
}

int	checkchar(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
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
