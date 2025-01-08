/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuro <afuro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:19:41 by afuro             #+#    #+#             */
/*   Updated: 2025/01/08 16:05:04 by afuro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	char		*line;
	int			endline;
	ssize_t		bytesread;

	if (!str)
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (jeyfree(&str), NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || fd == -1 || BUFFER_SIZE == 0)
		return (jeyfree(&str), jeyfree(&buffer), NULL);
	while (1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == 0 && bytesread == -1)
			return (jeyfree(&str), jeyfree(&buffer), NULL);
		endline = bufftostr(buffer, &str);
		if (endline == 1)
		{
			line = justoneline(str);
			return (jeyfree(&buffer), line);
		}
	}
}

int	bufftostr(char *buffer, char **str)
{
	*str = ft_strjoin(*str, buffer);
	buffer[0] = '\0';
	if (checkendchar(*str) == 1)
		return (1);
	return (0);
}

char	*justoneline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		line[i] = '\0';
	else if (str[i] == '\n')
		line[i] = '\n';
	keeptherest(str);
	return (line);
}

void	keeptherest(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	i++;
	while (str[i] != '\0')
	{
		str[j] = str[i];
		j++;
		i++;
	}
	str[j] = '\0';
}


int main()
{
    int fd;
    char *line;

    fd = open("coc9.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        jeyfree(&line);
    }

    close(fd);
    return (0);
}