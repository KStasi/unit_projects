/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akondaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:29:19 by akondaur          #+#    #+#             */
/*   Updated: 2018/10/22 19:32:16 by akondaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	if (!*str)
		return ;
	ft_putchar(*str);
	ft_putstr(++str);
}

int		main(int args, char **argv)
{
	int i;

	i = 0;
	while (++i < args)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}
