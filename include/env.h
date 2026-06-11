#ifndef ENV_H
# define ENV_H

typedef struct s_env
{
    char            *key;
    char            *value;
    struct s_env    *next;
} t_env;

t_env  *env_init(char **envp);
void    env_destroy(t_env *env);

t_env   *env_find(t_env *env, const char *key);
char    *env_get(t_env *env, const char *key);

int     env_set(t_env **env,
                const char *key,
                const char *value);
int     env_unset(t_env **env,
                  const char *key);

#endif
