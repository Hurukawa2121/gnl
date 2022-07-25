/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:32:58 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/25 20:16:36 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *s, const char *t, size_t n)
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
char	*ft_strdup(const char *s)
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

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
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

char	*ft_new_left_str(char *left_str)
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
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}