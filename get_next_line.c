/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuro <afuro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:19:41 by afuro             #+#    #+#             */
/*   Updated: 2025/01/08 12:23:25 by afuro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	char		line;
	int			endline;
	ssize_t		bytesread;

	if (!str)
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if ((!str || !buffer) || fd == -1)
		return (ft_free(str, buffer), NULL);
	while (1)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == 0)
			return (fr_free(str, buffer), NULL);
		endline = bufftostr(buffer, str);
		if (endline == 1)
		{
			line = justoneline(str);
			return (ft_free(str, buffer), line);
		}
	}
}

int	bufftostr(char *buffer, char *str)
{
	if (str[0] == '\0')
		ft_strcpy(buffer, str);
	else
	{
		str = ft_strjoin(str, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
		if (checkendchar(str) == 1)
			return (1);
	}
	return (0);
}

char	*justoneline(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] != '\0' & str[i] != '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' & str[i] != '\n')
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

void	*keeptherest(char *str)
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

void	ft_free(void *s1, void *s2)
{
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
}

/* int main(void)
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
		str = get_next_line(fd);
	}
    close(fd);
    return 0;
} */