/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:01:19 by vdecleir          #+#    #+#             */
/*   Updated: 2023/11/29 18:16:07 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_null(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

static char	*leftover(char	*stock)
{
	unsigned int	i;

	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		stock = ft_substr(stock, i + 1);
	else
		stock[0] = '\0';
	return (stock);
}

static char	*clean_stock(char *stock, unsigned int i)
{
	char			*next_line;

	if (!stock)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
		i++;
	if (stock[i] == '\n')
		i++;
	next_line = malloc(sizeof(char) * (i + 1));
	if (!next_line)
		return (NULL);
	i = 0;
	while (stock[i] != '\n' && stock[i])
	{
		next_line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		next_line[i] = '\n';
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

static char	*add_stock(int fd, char *stock, int char_read)
{
	char	*buf;

	if (!stock)
		stock = ft_calloc(1, 1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buf)
		return (free_null(stock));
	while (char_read > 0)
	{
		if (ft_strchr(stock, '\n') != 0)
			break ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free_null(stock);
			free_null(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		stock = ft_strjoin(stock, buf, 0, 0);
	}
	free_null(buf);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE >= INT32_MAX)
		return (NULL);
	stock = add_stock(fd, stock, 1);
	if (!stock || stock[0] == '\0')
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	next_line = clean_stock(stock, 0);
	if (!next_line)
	{
		free(stock);
		stock = NULL;
	}
	stock = leftover(stock);
	return (next_line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd = open("hello.txt", O_RDONLY);
// 	char	*str;
// 	str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// }