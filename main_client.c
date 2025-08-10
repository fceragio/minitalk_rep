/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:20:37 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 17:17:53 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_by_char(int pid, char c)
{
	int	bit_num;

	bit_num = 0;
	while (bit_num < CHAR_BIT)
	{
		if (c & 0b10000000 >> bit_num)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_num++;
		usleep(100);
	}
}

void	success(int sig_success)
{
	if (sig_success == SIGUSR2)
	{
		put_string("Server confirmed receiving the message\n");
		exit(0);
	}
}

int	main(int argc, char**argv)
{
	int	server_pid;
	int	i;

	signal(SIGUSR2, success);
	if (argc == 3)
	{
		server_pid = pid_convert_int(argv[1]);
		if (server_pid != NOT_PID)
		{
			i = 0;
			while (argv[2][i])
				char_by_char(server_pid, argv[2][i++]);
			char_by_char(server_pid, '\0');
			usleep(500);
		}
		else
			put_string("Invalid PID\n");
	}
	else
		put_string("Invalid number of arguments\n");
	return (1);
}
