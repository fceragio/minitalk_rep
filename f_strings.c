/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:26:02 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 17:47:52 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_string(char *str)
{
	if (str)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
}

int	pid_convert_int(char *str)
{
	long int	pid;

	pid = 0;
	if (!str)
		return (NOT_PID);
	while (*str)
	{
		if ((*str) < '0' || (*str) > '9')
			return (NOT_PID);
		pid = pid * 10 + ((*str) - '0');
		if (pid > INT_MAX)
			return (NOT_PID);
		str++;
	}
	return ((int)pid);
}

int	num_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*pid_convert_str(int pid)
{
	char	*str_pid;
	int		len;

	len = num_len(pid);
	str_pid = malloc(sizeof(char) * (len + 1));
	if (str_pid == NULL)
		return (NULL);
	str_pid[len] = '\0';
	len--;
	while (len >= 0)
	{
		str_pid[len] = (pid % 10) + '0';
		pid = pid / 10;
		len--;
	}
	return (str_pid);
}
