/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:40:30 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:53:05 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && count > ULLONG_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/* #include <stdio.h>
int main (void)
{
	size_t count;
	size_t size;
	void *ptr;

	ptr = ft_calloc(5, sizeof(int));
	for (int i = 0; i < 5; i++) {
		printf("%d\n", ((int *)ptr)[i]);
	}
} */
