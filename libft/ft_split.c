/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:26:46 by gansard           #+#    #+#             */
/*   Updated: 2023/02/08 12:25:46 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	if (!*str)
		return (0);
	if (str[0] != c)
		count_words++;
	if (str[0] != '\0')
		i++;
	while (str[i])
	{
		if ((str[i - 1] == c)
			&& (str[i] != c))
			count_words++;
		i++;
	}
	return (count_words);
}

char	*create_word(const char *str, char **tab, char c, int index)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	word = malloc(sizeof(char) * i + 1);
	if (!word)
	{
		while (index >= 0)
			free(tab[index--]);
		return (NULL);
	}
	word[i] = '\0';
	j = 0;
	while (j < i)
	{
		word[j] = str[j];
		j++;
	}
	return (word);
}

char	**ft_malloc_split(char **split, const char *s, char c)
{
	int		nb_words;

	nb_words = count_words(s, c);
	if (!nb_words)
	{
		split = malloc(sizeof(char *));
		if (!split)
			return (NULL);
		split[0] = NULL;
		return (split);
	}
	split = malloc(sizeof(char *) * (nb_words + 1));
	if (!split)
		return (NULL);
	return (split);
}

char	**ft_create_split(char **split, const char *s, char c, int i)
{
	int		j;

	j = -1;
	while (s[++j])
	{
		if (j == 0)
		{
			if (s[j] != c)
			{
				split[i] = create_word(&s[j], split, c, i);
				if (!split[i])
					return (free(split), NULL);
				i++;
			}
		}
		else if (s[j] != c && (s[j - 1] == c))
		{
			split[i] = create_word(&s[j], split, c, i);
			if (!split[i])
				return (free(split), NULL);
			i++;
		}
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	split = ft_malloc_split(split, s, c);
	if (!split)
		return (NULL);
	split = ft_create_split(split, s, c, i);
	return (split);
}
