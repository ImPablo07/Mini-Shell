#include <stdio.h>

#include "parser.h"

void print_commands(t_command *commands)
{
    int i;

    while (commands)
    {
        printf("COMMAND:\n");

        i = 0;

        while (commands->argv[i])
        {
            printf("  argv[%d] = %s\n",
                   i,
                   commands->argv[i]);

            i++;
        }

        commands = commands->next;
    }
}
