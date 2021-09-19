/*
** EPITECH PROJECT, 2019
** open file
** File description:
** open
*/

#include "include/my.h"

char	*check_file(int fd)
{
    char	*buf = malloc(sizeof(char) * 50);

    read(fd, buf, 50);
    if (find_num_string(buf, ':') != 8)
        return NULL;
    if (find_num_string(buf, '\n') > 4)
        return NULL;
    if (my_strlen(buf) > 32)
        return NULL;
    if (check_coordinates(buf) == 0)
        return NULL;
    if (check_coordinates_2(buf) == 0)
        return NULL;
    return (buf);
}

int	letter_to_number(char a)
{
    if (a == 'A')
        return 2;
    if (a == 'B')
        return 4;
    if (a == 'C')
        return 6;
    if (a == 'D')
        return 8;
    if (a == 'E')
        return 10;
    if (a == 'F')
        return 12;
    if (a == 'G')
        return 14;
    if (a == 'H')
        return 16;
}

int	check_coordinates(char *buffer)
{
    char	**map = string_to_double_array(buffer);
    char	*beg = NULL;

    for (unsigned int i = 0; i < 4; i++) {
        beg = my_itoa(i + 2);
        if (map[i][0] != beg[0] || map[i][1] != ':' || map[i][4] != ':')
            return (0);
        if (map[i][2] < 'A' || map[i][2] > 'H'\
            || map[i][5] < 'A' || map[i][5] > 'H')
            return (0);
        if (map[i][3] < '1' || map[i][3] > '8'\
            || map[i][6] < '1' || map[i][6] > '8')
            return (0);
        if (map[i][2] != map[i][5] && map[i][3] != map[i][6])
            return (0);
    }
    return (1);
}

int	check_coordinates_2(char *buffer)
{
    char	**map = string_to_double_array(buffer);

    for (unsigned int i = 0; i < 4; i++) {
        int n1 = map[i][3] - '0';
        int n2 = map[i][6] - '0';
        int size = map[i][0] - '0';
        int let1 = letter_to_number(map[i][2]);
        int let2 = letter_to_number(map[i][5]);
        if ((n2 - n1 - size) != -1 && n1 != n2)
            return (0);
        if ((let2/2 - let1/2 - size) != -1 && let2 != let1)
            return (0);
    }
    return (1);
}

char	**string_to_double_array(char *buffer)
{
    char **map = mem_alloc_2d_array(5, 9);
    int i = 0;
    int n = 0;
    int m = 0;

    while (buffer[i] != '\0' && map[n] != NULL) {
        for (; buffer[i] == '\n'; i++)
            map[n][m] = '\0';
        for (; buffer[i] != '\n' && buffer[i] != '\0'; i++, m++)
            map[n][m] = buffer[i];
        m = 0;
        n++;
    }
    map[n + 1] = NULL;
    return (map);
}
