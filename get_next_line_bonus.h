/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfurukaw <sfurukaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:33:09 by sfurukaw          #+#    #+#             */
/*   Updated: 2022/07/25 18:21:40 by sfurukaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLB_H
# define GNLB_H

# include <stdlib.h>
# include <unistd.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *a);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif