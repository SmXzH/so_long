/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhakypo <szhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:44:48 by sam               #+#    #+#             */
/*   Updated: 2022/05/25 22:17:25 by szhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 100

void	*ft_mcpy(void *dest, const void *src, int n);
char	*ft_sjoin(char *s1, char *s2);
char	*ft_sdup(const char *str);
int		ft_slen(const char *p);
char	*line_num(const char *s);
char	*get_next_line(int fd);

#endif