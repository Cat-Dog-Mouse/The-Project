#include <stdio.h>

int main(int argc, char const *argv[])
{
    char buf[100] = {0};

    fgets(buf, 100, stdin);

    printf("%s", buf);

    return 0;
}
