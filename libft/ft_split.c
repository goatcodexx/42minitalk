/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:51:58 by sywee             #+#    #+#             */
/*   Updated: 2025/12/21 21:54:35 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**free_split(char **res, int word_count)
{
	int	i;

	i = 0;
	while (i < word_count)
		free(res[i++]);
	free(res);
	return (NULL);
}

static char	**split_words(char **res, const char *s, char c)
{
	int	start_pos;
	int	word_len;
	int	word;

	start_pos = 0;
	word_len = 0;
	word = 0;
	while (s[start_pos] != '\0')
	{
		if (s[start_pos] == c)
			start_pos++;
		else
		{
			word_len = 0;
			while (s[start_pos + word_len] && s[start_pos + word_len] != c)
				word_len++;
			res[word] = ft_substr(s, start_pos, word_len);
			if (!res[word])
				return (free_split(res, word));
			word++;
			start_pos += word_len;
		}
	}
	res[word] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		count;
	char	**res;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = malloc((count + 1) * sizeof(*res));
	if (!res)
		return (NULL);
	return (split_words(res, s, c));
}
/* int main()
{
	char *s = "asdasd a sdasdaasdsasdd a    
	aasdas  sd  asdaqwe   asasda asdasd ";
	char **split = ft_split(s, ' ');
	printf("s: %s\n", s);
	for (int i = 0; split[i]; i++) 
	{
		printf("%i:\t[%s]\n", i, split[i]);
	}
} */