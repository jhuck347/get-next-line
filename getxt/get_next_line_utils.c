/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhuck <jhuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:47:58 by jhuck             #+#    #+#             */
/*   Updated: 2024/03/13 17:49:47 by jhuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	subs_len;

	subs_len = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		subs = malloc(sizeof(char) * (1));
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (subs == NULL)
		return (NULL);
	while (start < ft_strlen(s) && subs_len < len && s[start])
		subs[subs_len++] = s[start++];
	subs[subs_len] = '\0';
	return (subs);
}
