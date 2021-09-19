/*
** EPITECH PROJECT, 2019
** atoi
** File description:
** atoi
*/

#include "include/my.h"

int	my_atoi(char *s)
{
    int sign = 1;
    int i = 0;
    int my_int = 0;
    while (s[i] == ' ')
        i++;
    if (s[i] == '+' || s[i] == '-')
        if (s[i++] == '-')
            sign = -1;
    while (s[i] <= '9' && s[i] >= '0') {
        my_int = my_int * 10 + s[i++] - '0';
    }
    return sign * my_int;
}
