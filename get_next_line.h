/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afuro <afuro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:03:28 by thmgba            #+#    #+#             */
/*   Updated: 2025/01/08 16:00:58 by afuro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	jeyfree(char **ptr);
void	*ft_calloc( size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		bufftostr(char *buffer, char **str);
char	*justoneline(char *str);
void	keeptherest(char *str);
void	ft_strcpy(char *s1, char *s2);
int		checkendchar(char	*str);

#endif