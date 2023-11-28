/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:01:28 by vdecleir          #+#    #+#             */
/*   Updated: 2023/11/28 17:06:02 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# elif BUFFER_SIZE > 100000 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char			*get_next_line(int fd);
char			*ft_strjoin(char *s1, char *s2, int i, int j);
unsigned int	ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char *s, unsigned int start);
void			*ft_calloc(size_t nmemb, size_t size);

#endif
