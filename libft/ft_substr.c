/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:22:21 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:57:28 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		str_len;
	size_t		substrlen;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	substrlen = str_len - start;
	if (substrlen > len)
		substrlen = len;
	str = malloc(substrlen + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, substrlen + 1);
	return (str);
}

/* int	main(void)
{
	char	*str;
	char	*substr;
	str = "Hello";

	substr = ft_substr(str, 0, -2);
	printf("%s\n", substr);
	free (substr);
} */
