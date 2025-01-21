/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmgba <thmgba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:06 by thmgba            #+#    #+#             */
/*   Updated: 2025/01/21 11:15:56 by thmgba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_free(char *file, char *buffer)
{
	char	*placeholder;

	placeholder = ft_strjoin(file, buffer);
	free(file);
	return (placeholder);
}

char	*ft_read_following(int fd, char *file)
{
	char	*buffer;
	int		bytes;

	if (!file)
		file = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(file), free(buffer), NULL);
		buffer[bytes] = 0;
		file = ft_join_free(file, buffer);
		if (ft_strchr(file, '\n'))
			break ;
	}
	free (buffer);
	if (bytes == 0 && file[0] == '\0')
		return (free(file), NULL);
	return (file);
}

char	*get_oline(char *file)
{
	int		i;
	char	*str;

	i = 0;
	if (!file)
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		str[i] = file[i];
		i++;
	}
	if (file[i] && file[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*old_line_remove(char *file)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(file) - i + 1), sizeof(*file));
	if (!str)
		return (NULL);
	while (file[++i])
		str[j++] = file[i];
	str[j] = '\0';
	free(file);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*file_displayed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = ft_read_following(fd, file);
	if (!file)
		return (NULL);
	file_displayed = get_oline(file);
	file = old_line_remove(file);
	return (file_displayed);
}

/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
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
        free(line);
    }
    close(fd);
    return (0);
}*/
