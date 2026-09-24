/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:52:32 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:53:27 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(const int n)
{
	int	count;
	int	num;

	num = n;
	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static void	fill_result(char *result, long num, int result_len, int neg_sign)
{
	while (result_len >= 0)
	{
		if (result_len == 0 && neg_sign == -1)
			result[result_len] = '-';
		else
		{
			result[result_len] = num % 10 + '0';
			num = num / 10;
		}
		result_len--;
	}
}

char	*ft_itoa(int n)
{
	int		result_len;
	char	*result;
	long	num;
	int		neg_sign;

	neg_sign = 1;
	if (n < 0)
		neg_sign = -1;
	num = neg_sign * (long) n;
	result_len = count_digits(n);
	result = malloc(result_len + 1);
	if (!result)
		return (NULL);
	result[result_len] = '\0';
	result_len--;
	fill_result(result, num, result_len, neg_sign);
	return (result);
}
/* int main (void)
{
	int		num;
	char	*str;

	num = -1234567890;
	str = ft_itoa(num);
	printf("%s\n", str);
} */
