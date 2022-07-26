/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:31:41 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/26 10:00:50 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *left)
{
	int		i;
	char	*str;

	i = 0;
	if (!left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		str[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		str[i] = left[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_new_left_str(char *left)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left[i])
		str[j++] = left[i++];
	str[j] = '\0';
	free(left);
	return (str);
}

static char	*ft_read_to_left_str(int fd, char *left)
{
	char	*buf;
	int		rd_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left, '\n') && !rd_bytes)
	{
		rd_bytes = read(fd, buf, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd_bytes] = '\0';
		left = ft_strjoin(left, buf);
		if (!left)
		{
			free (left);
			return (NULL);
		}
	}
	free(buf);
	return (left);
}

char	*get_next_line(int fd)
{
	char		*ans;
	static char	*left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = ft_read_to_left_str(fd, left);
	if (!left)
		return (NULL);
	ans = ft_get_line(left);
	left = ft_new_left_str(left);
	return (ans);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int fd;
	char **a;

	a = malloc(sizeof(char *) * 3);
	fd = open("./testfile", O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	for (int i = 0; i < 3; i++)
	{
		a[i] = get_next_line(fd);
		printf("%s\n", a[i]);
		free(a[i]);
	}
	if (close(fd))
		return (1);
	free(a);
	return (0);
}
*/