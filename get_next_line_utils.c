/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:32:58 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/25 20:26:44 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strncpy(char *s, const char *t, size_t n)
{
	size_t	i;

	i = 0;
	while (t[i] && i < n)
	{
		s[i] = t[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
static char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ans;

	i = 0;
	while (s[i])
		i++;
	ans = malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (NULL);
	ft_strncpy(ans, s, i + 1);
	return (ans);
}
size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	char *ans;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ans = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ans)
		return (NULL);
	i = -1;
	while (s1[++i])
		ans[i] = s1[i];
	j = -1;
	while (s2[++j])
		ans[i + j] = s2[j];
	ans[i + j] = '\0';
	return (ans);
}

/*
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(const char *left_str, const char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
*/