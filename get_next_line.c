/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:31:41 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/26 11:32:30 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_left(char *left)
{
	int		i;
	int		j;
	char	*new_left;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	new_left = malloc(sizeof(char) * (ft_strlen(left) - i + 1));
	if (!new_left)
		return (NULL);
	i++;
	j = 0;
	while (left[i])
		new_left[j++] = left[i++];
	new_left[j] = '\0';
	free(left);
	return (new_left);
}

char	*ft_save(char *left)
{
	int		i;
	char	*save;

	if (!left[0])
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	save = malloc(sizeof(char) * (i + 2));
	if (!save)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		save[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		save[i] = left[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*ft_read(int fd, char *left)
{
	char	*tmp;
	int		rd_size;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	rd_size = 1;
	while (!ft_strchr(left, '\n') && rd_size)
	{
		rd_size = read(fd, tmp, BUFFER_SIZE);
		if (rd_size == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[rd_size] = '\0';
		left = ft_strjoin(left, tmp);
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
	left = ft_read(fd, left);
	if (!left)
		return (NULL);
	ans = ft_save(left);
	left = ft_left(left);
	/*if (!left)
		return (NULL);*/
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
char	*get_next_line(int fd)
{
	char		*ans;
	static char	*left_str[256];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str[fd] = ft_read(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	ans = ft_save(left_str[fd]);
	left_str[fd] = ft_left(left_str[fd]);
	return (ans);
}
*/
