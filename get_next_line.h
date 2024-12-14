/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmgba <thmgba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:03:28 by thmgba            #+#    #+#             */
/*   Updated: 2024/12/14 20:30:24 by thmgba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void 	ft_free(char *str);
void 	ft_buffertostr(char *str, char* buffer);
char 	*ft_keeptherest(char *str);
int		checkchar(char *buffer);
void	*ft_calloc( size_t nmemb, size_t size);

#endif