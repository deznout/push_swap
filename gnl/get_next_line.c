/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kkk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:29:59 by hbrent            #+#    #+#             */
/*   Updated: 2021/09/13 21:30:10 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **line, char **result)
{
	char	*str;
	char	*ptr;

	ptr = ft_strchr(*result, '\n');
	if (ptr)
	{
		str = *result;
		*ptr++ = '\0';
		*line = ft_strdup(*result);
		if (!(*line))
			return (-1);
		*result = ft_strdup(ptr);
		if (!(*result))
			return (-1);
		free(str);
	}
	else
	{
		*line = ft_strdup(*result);
		if (!(*line))
			return (-1);
		free(*result);
		*result = NULL;
	}
	return (0);
}

static int	*is_empty(char **result, char *buffer)
{
	if (!(*result))
		*result = ft_strdup(buffer);
	else
		*result = ft_strjoin(*result, buffer);
	return (0);
}

static int	check_res(int fd, char **line, char *buffer, char **result)
{
	int	read_byte;

	read_byte = 1;
	while (read_byte > 0 && (!(ft_strchr(*result, '\n'))))
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
			return (-1);
		buffer[read_byte] = '\0';
		is_empty(result, buffer);
		if (!(*result))
			return (-1);
	}
	get_line(line, result);
	if (read_byte)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*result;
	char		*buffer;
	int			answ;

	if (!line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	answ = check_res(fd, line, buffer, &result);
	free(buffer);
	return (answ);
}
