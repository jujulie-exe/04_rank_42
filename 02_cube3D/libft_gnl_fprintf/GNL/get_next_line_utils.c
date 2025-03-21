/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:46:31 by jfranco           #+#    #+#             */
/*   Updated: 2025/02/25 16:26:46 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	y;

	len = 0;
	y = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (dstsize > 0)
	{
		while (src[y] != '\0' && y < dstsize - 1)
		{
			dst[y] = src[y];
			y++;
		}
		dst[y] = '\0';
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dst;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		return (ft_strdup(""));
	if (start < i)
		j = i - start;
	if (j > len)
		j = len;
	dst = (char *) malloc((j + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s + start, j + 1);
	return (dst);
}
