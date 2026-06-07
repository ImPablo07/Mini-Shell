/******************************************************************************
 * @file ft_strlen.c
 * @brief Implementacja funkcji ft_strlen.
 ******************************************************************************/

#include "utils.h"

/**
 * @brief Oblicza długość łańcucha znaków.
 *
 * @param s Łańcuch znaków.
 * @return Liczba znaków bez znaku '\0'.
 */
size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;

    while (s && s[i])
        i++;

    return (i);
}
