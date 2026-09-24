/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:36:18 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:55:39 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[i]);
	while (i > 0 && s[i] != (unsigned char) c)
	{
		i--;
	}
	if (s[i] == (unsigned char) c)
		return ((char *)&s[i]);
	return (NULL);
}
/* 
#include <stdio.h>
int main(void)
{
	char *s = "hello";

	char *rtn = ft_strrchr(s, 'h');
	printf("Return value: \n %s\n", rtn);
	return (1);
} */