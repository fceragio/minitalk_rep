/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:07:57 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 17:38:19 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	welcoming(int pid)
{
	char	*str_pid;

	str_pid = pid_convert_str(pid);
	if (str_pid == NULL)
	{
		perror("malloc failed convering the server PID\n");
		exit(1);
	}
	put_string("The PID of this server is: ");
	put_string(str_pid);
	put_string("\n\n");
	free(str_pid);
}

void	siga_error(void)
{
	perror("sigaction returned an error\n");
	exit(1);
}

void	handler(int signal_id, siginfo_t *info, void *more_info)
{
	static char	c = 0b00000000;
	static int	bit_num = 0;

	(void)more_info;
	if (signal_id == SIGUSR1)
		c |= (0b10000000 >> bit_num);
	bit_num++;
	if (bit_num == CHAR_BIT)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		c = 0b00000000;
		bit_num = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	welcoming(pid);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		siga_error();
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		siga_error();
	while (1)
		pause();
}
