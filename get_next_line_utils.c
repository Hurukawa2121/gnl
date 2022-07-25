/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:32:58 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/25 20:49:30 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}
static void	ft_strcpy(char *s, const char *t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		s[i] = t[i];
		i++;
	}
	s[i] = '\0';
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
	ft_strcpy(ans, s);
	return (ans);
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