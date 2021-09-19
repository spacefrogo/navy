/*
** EPITECH PROJECT, 2019
** mm
** File description:
** mm
*/

#include <string.h>
#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int global = 0;

void	handle_sig(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;
    kill(info->si_pid, SIGUSR1);
    global = 1;
}

void	handle_sig2(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)context;
    (void)info;
    global = 1;
}

char *my_itoa(int nb)
{
    int len = 0;
    char *str;
    int tmp = nb;

    while (tmp > 0) {
        tmp /= 10;
            len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10  + '0';
        nb /= 10;
    }
    return (str);
}

void	my_putchar(char c)
{
    write(1, &c, 1);
}

void	my_bzero(char *str, int nb)
{
    int	i = 0;

    while (i < nb) {
        str[i] = '\0';
        i++;
    }
}

int	my_strlen(char *str)
{
    int	i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

int	my_putstr(char *str)
{
    int	i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}

int	my_put_nbr(int nb)
{
    int	i = 0;

    if (nb >= 0) {
        if (nb >= 10) {
            i = (nb % 10);
            nb = (nb - i) / 10;
            my_put_nbr(nb);
            my_putchar(48 + i);
        }
        else {
            my_putchar(48 + nb % 10);
        }
    }
    return (0);
}

void	play(void)
{
    struct	sigaction	act;
    
    act.sa_sigaction = &handle_sig;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &act, NULL);
    while (!global);
}

void	wait1(char **av)
{
    my_putstr("my pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n");
    play();
    my_putchar('\n');
    my_putstr("enemy connected");
    my_putchar('\n');
    //get_map(av, map);
    //get_enemymap(map);
    my_putchar('\n');
    my_putstr("attack: ");
}

void	connect(char **av)
{
    int	pid;

    my_putstr("my pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    pid = atoi(av[1]);
    kill(pid, SIGUSR1);
    // play_enemy();
    my_putstr("successfully connected");
    my_putchar('\n');
    // get_map2(av, map);
    //get_enemymap(map);
    my_putstr("\nwaiting for enemy's attack...\n");
}

int	main(int ac, char **av)
{    
    wait1(av);
    if (ac == 3)
        connect(av);
}
