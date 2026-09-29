/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 21:29:47 by sywee             #+#    #+#             */
/*   Updated: 2026/09/29 17:55:15 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_char(int pid, int character)
{
    int bits;
    
    bits = 7;
    while (bits >= 0)
    {
        if ((character >> bits) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(1000);
        bits--;
    }
}

void    send_msg(int pid, char *message)
{
    // int character;
    int i;
    
    i = 0;
    while (message[i] != '\0')
    {
        // character = message[i];
        send_char(pid, message[i]);
        i++;
    }
    send_char(pid, '\0');
}

int main(int ac, char *av[])
{
    int     pid;
    
    if (ac != 3)
        return (1);
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        return (1);
    send_msg(pid, av[2]);
}