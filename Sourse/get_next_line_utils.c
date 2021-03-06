/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:44:08 by sam               #+#    #+#             */
/*   Updated: 2022/05/25 22:02:40 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// конкатенация двух строк

char	*ft_sjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buff;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buff = malloc(ft_slen((char *)s1) + ft_slen((char *)s2) + 2);
	if (!buff)
		return (0);
	j = 0;
	i = 0;
	while (s1[j])
		buff[i++] = s1[j++];
	j = 0;
	while (s2[j])
		buff[i++] = s2[j++];
	buff[i] = '\0';
	free(s1);
	return (buff);
}

// Длинна строки

int	ft_slen(const char *p)
{
	int	i;

	i = 0;
	while (p[i])
		i++;
	return (i);
}

// дублирование строки

char	*ft_sdup(const char *str)
{
	int		n;
	char	*res;

	n = (int)(ft_slen(str) + 1);
	res = NULL;
	res = (char *)malloc(n);
	if (res == NULL)
		return (0);
	ft_mcpy(res, str, n);
	return (res);
}

// Копирование n-символов из src в dest

void	*ft_mcpy(void *dest, const void *src, int n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;
	int				i;

	if (!dest && !src)
		return (0);
	new_dest = dest;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*new_dest++ = *new_src++;
	return (dest);
}

// Подсчёт количества символов строки

char	*line_num(const char *s)
{
	int	g;

	g = 0;
	if (!s)
		return (0);
	while (s[g] != '\n')
	{
		if (!s[g])
			return (0);
		++g;
	}
	return ((char *)&s[g]);
}
