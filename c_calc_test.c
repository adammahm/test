#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 128

char* run_calculator(char cmd[256]) {   

    char buf[BUFSIZE];
    FILE *fp;

    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }

    while (fgets(buf, BUFSIZE, fp) != NULL) {
        pclose(fp);
		return buf;
    }
}
 
void main()
{
	if(atoi(run_calculator("python /home/calculator-master/1_nothing.py \"5 3 + 12 * 3 /\"")) == 32)
		printf("Result: True");
	else
		printf("Result: False");
}