/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:19:37 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/07/13 12:19:37 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils/ft_utils.h"

void	signal_receiver(int sig)
{
	static int	i;

	i++;
	if (sig == SIGUSR2)
	{
		if (i == 1)
			ft_printf("What a nice char!\n", i);
		else if (i == 2)
			ft_printf("Is this also one of yours? Thanks!\n", i);
		else if (i == 3)
			ft_printf("Oh right there's a secret somewhere, find it!\n", i);
		else if (i == 7)
			ft_printf("Once upon a time there were 7 warriors of light\n", i);
		else if (i == 13)
			ft_printf("And there were also 13 darknesses\n", i);
		else
			ft_printf("These chars are raining like moneys". i);
	}
}

void	to_binary(int pid, char **argv)
{
	int				j;
	unsigned int	i;
	unsigned int	bit_max;

	j = 0;
	bit_max = 1 << (sizeof(char) * 8 - 1);
	while (argv[j])
	{
		i = 0;
		while (i < (sizeof(char) * 9))
		{
			if (argv[j] & bit_max)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			argv[j] = argv[j] << 1;
			i++;
			usleep(137);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, signal_receiver);
	signal(SIGUSR2, signal_receiver);
	if (argc != 3)
	{
		ft_printf("You must insert 3 parameters!\n", 1);
		return (1);
	}
	to_binary(ft_atoi(argv[1]), argv[2]);
	return (0);
}
