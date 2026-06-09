/******************************************************************************
 * @file executor_debug.c
 * @brief Funkcje debugujące executor.
 ******************************************************************************/

#include <stdio.h>

#include "parser.h"

/**
 * @brief Wyświetla polecenie przed wykonaniem.
 *
 * @param cmd Polecenie do wykonania.
 */
void print_execution(t_command *cmd)
{
    int i;

    printf("[EXEC] ");

    i = 0;

    while (cmd->argv && cmd->argv[i])
    {
        printf("%s ", cmd->argv[i]);
        i++;
    }

    printf("\n");
}
