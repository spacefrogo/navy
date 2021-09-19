/*
** EPITECH PROJECT, 2019
** lib2
** File description:
** second functions from CPOOL needed for navy
*/

#include "include/my.h"

int	my_getnbr(char *str)
{
    int i;
    int sign;
    int result;
    int a = my_strlen(str);

    sign = 1;
    result = 0;
    for (i = 0; i < a; i++) {
        if (str[i] == '-')
            sign = sign * (-1);
        else if (str[i] >= '0' && str[i] <= '9')
            result = (result * 10) + (str[i] - '0');
        else
            return (84);
    }
    return (result * sign);
}

int     my_str_isnum(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return (1);
    if (str[0] == '-')
        i++;
    while (str[i]) {
        if (str[i] > '9' || str[i] < '0')
            return (0);
        i++;
    }
    return (1);
}

int	my_strcmp(char const *s1, char const *s2)
{
    while (*s2) {
        if (*s1 == *s2)
            return my_strcmp((s1 + 1), (s2 + 1));
        else
            return *s1 - *s2;
    }
    return 0;
}
