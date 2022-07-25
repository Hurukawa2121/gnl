/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:31:41 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/25 20:08:42 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_left_str(char *left)
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
	str = malloc(sizeof(char) * (ft_strlen(left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left[i]) // && left[i] != '\n' いらないの？
	{
		str[j] = left[i + j];
		j++;
	}
	str[j] = '\0';
	free(left);
	return (str);
}

char	*ft_get_line(char *left)
{
	int		i;
	char	*str;

	if (!*left)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
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

char	*ft_read_to_left_str(int fd, char *left)
{
	int		rd_bytes;
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left, '\n') && rd_bytes)
	{
		rd_bytes = read(fd, tmp, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[rd_bytes] = '\0';
		left = ft_strjoin(left, tmp);
		if (!left)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
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