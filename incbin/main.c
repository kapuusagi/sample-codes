#include <stdio.h>
#include "resource.h"

int 
main(int ac, char **av)
{
    int i;

    for (i = 0; i < MsgSize; i++) {
	printf("%02x ", Msg[i]);
    }
    fputc('\n', stdout);
    printf("%s\n", Msg);

    return 0;
}
