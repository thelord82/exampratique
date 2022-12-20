#include <stdio.h>
#include <stdlib.h>

//static int ft_strlen(char *str)
//{
//    int i = 0;
//    while (str[i])
//        i++;
//    return (i);
//}
char *ft_strrev(char *str)
{
    int i = 0;
    char tmp;

    //i = ft_strlen(str) - 1;
    while (str[i])
        i++;
    i--;
    int j = -1;
    while (++j < i / 2)
    {
        tmp = str[j];
        str[j] = str[i - j];
        str[i - j] = tmp;
    }
    return (str);
}

int main(int argc, char **argv)
{
    char *str = malloc(sizeof(char) * 18);
    int i = 0;
    if (argc == 2)
    {
    while (argv[1][i])
    {
        str[i] = argv[1][i];
        i++;

    }
    }
    printf("Resultat = %s\n", ft_strrev(str));
}