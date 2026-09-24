/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:54:05 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:54:28 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (ft_putnbr_fd(-n, fd));
	}
	if (n >= 0 && n <= 9)
		return (ft_putchar_fd(n + '0', fd));
	ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}
/* int	main(void)
{
	ft_putnbr_fd(INT_MIN, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	// ft_putnbr_fd(-1234567890, 1);
} */
/* 
int	main(void)
{
	ft_putnbr_fd(12345, 1);
} */
