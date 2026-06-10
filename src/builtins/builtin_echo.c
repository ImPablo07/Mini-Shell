/******************************************************************************
 * @file builtin_echo.c
 * @author Paweł Czarny
 * @brief Implementacja polecenia echo.
 ******************************************************************************/

#include <stdio.h>

#include "builtins.h"

/**
 * @brief Wypisuje argumenty na standardowe wyjście.
 *
 * Implementacja podstawowej wersji polecenia echo.
 *
 * @param cmd Polecenie wraz z argumentami.
 *
 * @return Zawsze zwraca 0.
 */
int builtin_echo(t_command *cmd)
{
    int i;

    i = 1;

    while (cmd->argv[i])
    {
        printf("%s", cmd->argv[i]);

        if (cmd->argv[i + 1])
            printf(" ");

        i++;
    }

    printf("\n");

    return (0);
}
