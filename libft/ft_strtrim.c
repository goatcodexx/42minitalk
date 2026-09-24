/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:08:25 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:55:52 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ispartof_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
// checks if the character is part of the set

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ispartof_set(s1[i], (char *)set))
		i++;
	while (j > i && ispartof_set(s1[j], (char *)set))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}

/* #include <stdio.h>

int main ()
{
	char *s1 = "zxyzxyzxyzyxyzxyzasdasdxxxxasdasdasdasdasdzxyzxyzyxyzxyzxy";
	char *set = "xyz";
	char *ans = ft_strtrim(s1, set);
	printf("%s\n", ans);
} */