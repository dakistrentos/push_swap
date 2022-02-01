/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/02 18:20:11 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/09/30 09:59:02 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static char	*prepare_previous_string(char *buf, char *line)
{
	int		i;

	if (!buf[0])
	{
		line = (char *)malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
		return (line);
	}
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, &buf[0], i + 1);
	return (line);
}

static char	*finalize_line_prepare_buf(char *temp, char *buf, char *line)
{
	char	*final_line;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	final_line = (char *)malloc(i + 1);
	if (!final_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(final_line, line, i + 1);
	if (line)
		free(line);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	i++;
	ft_strlcpy(&buf[0], &temp[i], (BUFFER_SIZE - i) + 1);
	return (final_line);
}

static char	*realloc_and_copy_line(char *line, char *temp, size_t buf_size)
{
	char	*new_line;
	size_t	line_len;
	size_t	new_line_len;
	int		i;

	if (!temp)
		return (line);
	i = 0;
	line_len = ft_strlen(line);
	new_line_len = line_len + buf_size;
	new_line = (char *)malloc(new_line_len);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(new_line, line, line_len + 1);
	while (new_line[i])
		i++;
	ft_strlcpy(&new_line[i], &temp[0], BUFFER_SIZE + 1);
	if (line)
		free(line);
	return (new_line);
}

static int	g_n_l_return(int fd, char **line, char *buf)
{
	char	temp[BUFFER_SIZE + 1];
	ssize_t	result;

	result = 1;
	ft_bzero(&buf[0], BUFFER_SIZE + 1);
	while (result > 0)
	{
		result = read(fd, temp, BUFFER_SIZE);
		if (result < 0)
			return (result);
		temp[result] = '\0';
		*line = realloc_and_copy_line(*line, &temp[0], BUFFER_SIZE + 1);
		if (!*line)
			return (-1);
		if (ft_strchr(&temp[0], '\n'))
			break ;
	}
	*line = finalize_line_prepare_buf(&temp[0], &buf[0], *line);
	if (!*line)
		return (-1);
	if (result == 0)
		return (result);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	i = 0;
	if ((buf[0] && ft_strchr(&buf[0], '\n') != NULL))
	{
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		*line = (char *)malloc(i + 1);
		if (!*line)
			return (-1);
		ft_strlcpy(*line, &buf[0], i + 1);
		ft_memcpy(&buf[0], &buf[i + 1], BUFFER_SIZE - i);
		return (1);
	}
	*line = prepare_previous_string(&buf[0], *line);
	if (!*line)
		return (-1);
	return (g_n_l_return(fd, line, &buf[0]));
}
