/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:43:03 by sam               #+#    #+#             */
/*   Updated: 2022/05/30 19:36:32 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Удаляет лишнее

char	*cutting(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	buff = malloc (sizeof(char) * (ft_slen(str) - i + 1));
	if (!buff)
		return (0);
	j = 0;
	i++;
	while (str[i])
	{
		buff[j++] = str[i++];
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

// Возвращает строку + \0

char	*new_line(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

// Читает весь текст в static

static char	*reader(int fd, char *str)
{
	char	*buff;
	int		readed_bytes;

	readed_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!line_num(str) && readed_bytes != 0)
	{
		readed_bytes = read(fd, buff, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[readed_bytes] = '\0';
		str = ft_sjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = reader(fd, str);
	if (!str)
		return (NULL);
	buff = new_line(str);
	str = cutting(str);
	return (buff);
}
