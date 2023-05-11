/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:03:41 by dayou             #+#    #+#             */
/*   Updated: 2023/05/11 22:15:38 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	idx;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	idx = 0;
	i = 0;
	if (size < dest_len)
		return (src_len + size);
	while (dest[i])
		i++;
	while (src[idx] && i + 1 < size)
	{
		dest[i] = src[idx];
		i++;
		idx++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	size;
	char	*new_s;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = 0;
	size = (s1_len + s2_len);
	new_s = (char *)malloc(sizeof(char) * size + 1);
	if (new_s == NULL)
		return (NULL);
	ft_strlcpy(new_s, s1, s1_len + 1);
	new_s[s1_len] = '\0';
	ft_strlcat(new_s, s2, s1_len + s2_len + 1);
	return (new_s);
}

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (s1[0] == '\0')
		return (s1_is_null());
	size = ft_strlen(s1);
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[size] = '\0';
	return (new_str);
}

