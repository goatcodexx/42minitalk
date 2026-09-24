/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:24 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:54:15 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_dest < ptr_src)
	{
		i = 0;
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			ptr_dest[i - 1] = ptr_src[i - 1];
			i--;
		}
	}
	return (dest);
}
/* #include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

int	main(void)
{
	char	str[20] = "HelloWorld";

	printf("Before memmove: %s\n", str);
	// Move first 5 characters 2 positions forward (overlap!)
	ft_memmove(str + 2, str, 5);
	printf("After memmove:  %s\n", str);
	return (0);
} */
