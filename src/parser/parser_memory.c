#include <stdlib.h>

#include "parser.h"

/**
 * @brief Zwalnia pamięć listy poleceń.
 *
 * @param commands Lista poleceń.
 */
void free_commands(t_command *commands)
{
    t_command *next;
    int i;

    while (commands)
    {
        next = commands->next;

        i = 0;
        while (commands->argv && commands->argv[i])
        {
            free(commands->argv[i]);
            i++;
        }

        free(commands->argv);
        free(commands);

        commands = next;
    }
}
