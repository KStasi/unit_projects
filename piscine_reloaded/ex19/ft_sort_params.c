/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:32:58 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/23 17:14:51 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

int			ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (++i < ft_strlen(src))
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int			ft_strcmp(char *s1, char *s2)
{
	char *ps1;
	char *ps2;

	ps1 = s1;
	ps2 = s2;
	while (*ps1 == *ps2 && *ps1 && *ps2)
	{
		ps1++;
		ps2++;
	}
	if (*(ps1) == '\0' && *(ps2) == '\0')
		return (0);
	return (*ps1 - *ps2);
}

void		ft_sort(char tab[][1000], int size)
{
	int		i;
	int		j;
	char	tmp[1000];

	i = size - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				ft_strcpy(tmp, tab[j]);
				ft_strcpy(tab[j], tab[j + 1]);
				ft_strcpy(tab[j + 1], tmp);
			}
			j++;
		}
		i--;
	}
}

int			main(int args, char **argv)
{
	char	strings[args - 1][1000];
	int		i;
	int		j;

	i = 1;
	while (i < args)
	{
		ft_strcpy(strings[i - 1], argv[i]);
		i++;
	}
	ft_sort(strings, args - 1);
	i = 0;
	while (i < args - 1)
	{
		j = 0;
		while (strings[i][j] != '\0')
			ft_putchar(strings[i][j++]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
