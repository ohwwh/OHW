#include <unistd.h>

int ft_strlen(char *s)
{
    int len;

    len = 0;
    while (s && s[len])
        len ++;
    return (len);
}

char *ft_strnchr(char *s, char c, int n)
{
    while (s && *s && n)
    {
        if (*s == c)
            return (s);
        s ++;
        n --;
    }
    if (!(*s) && !c)
        return (s);
    else
        return (0);
}

int main(int argc, char *argv[])
{
    int i;
    int l;

    if (argc != 3)
        return (0);
    i = 0;
    l = ft_strlen(argv[2]);
    while (argv[1][i])
    {
        if (ft_strnchr(argv[2], argv[1][i], l))
        {
            if (!ft_strnchr(argv[1], argv[1][i], i))
                write(1, &argv[1][i], 1);
            i ++;
        }
    }
}