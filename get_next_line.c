/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:31:41 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/25 18:20:40 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	if (!*left_str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i]) // && left_str[i] != '\n' いらないの？
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

static char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*tmp;
	int		rd_bytes;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes)
	{
		rd_bytes = read(fd, tmp, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, tmp);
	}
	free(tmp);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*ans;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	ans = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
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