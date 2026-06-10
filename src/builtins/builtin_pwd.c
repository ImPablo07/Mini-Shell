#include <stdio.h>
#include <unistd.h>

#include "builtins.h"

int builtin_pwd(void)
{
    char cwd[4096];

    if (getcwd(cwd, sizeof(cwd)))
    {
        printf("%s\n", cwd);
        return (0);
    }

    return (1);
}
