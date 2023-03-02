
#include <stdio.h>

int main()
{
    char name[100];
    scanf("%s", name);
    char *new_name = (char *)malloc(sizeof(char) * (strlen(name) + 2));
    strcpy(new_name, "%");
    strcat(new_name, name);
    printf("%s", new_name);
    return 0;
}