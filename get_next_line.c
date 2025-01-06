/* ************************************************************************** */
/*                                                                            ²
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuro <afuro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:02:06 by thmgba            #+#    #+#             */
/*   Updated: 2025/01/06 15:05:29 by afuro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *str = NULL;
	char		*buffer;
	char		line;
	ssize_t		bytesread;

	if (!str)
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
}

ft_free(void *str)
{
	if (str)
	{
		free(str);
		str = NULL;
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