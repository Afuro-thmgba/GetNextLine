/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmgba <thmgba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:03:28 by thmgba            #+#    #+#             */
/*   Updated: 2025/01/21 11:08:47 by thmgba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

char		*ft_strjoin(const char *s1, const char *s2);
void		*ft_calloc(size_t nmemb, size_t size);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
void		ft_strdel(char **s);
void		ft_bzero(void *s, size_t len);

#endif