/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmgba <thmgba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:06 by thmgba            #+#    #+#             */
/*   Updated: 2024/12/13 21:50:46 by thmgba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char static	*str = NULL;
	char		*buffer;
	char		*dest;
	int			bytes_read;

	if (!str)
		str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!str)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 && ft_strlen(str) == 0)
		{
			free(str);
			return (NULL);
		}
		if (check_char(buffer) == 1 && str[0] == '\0')
			ft_strmove(buffer, str);
		else if (check_char(buffer) == 1 && str[0] != '\0')
		{
			dest = justoneline(str);
			break ;
		}
		str = ft_strjoin(str, buffer);
	}
	return (dest);
}

void ft_strmove(char *src, char *dest)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	i = 0;
	while (src[i])
	{
		src[i] = '\0';
		i++;
	}
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

    // while ((str = get_next_line(fd)) != NULL)
    // {
    //     printf("%s", str);
    //     free(str);
    //
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

// char *str = "";

// printf("%s\n", str);