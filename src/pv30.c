#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define UTIME_2030 1893456001 // UNIX TIMESTAMP FOR 1ST OF JAN 2030 00:01


int main(int argc, char* argv[]) {
	time_t tm = time(NULL);
	if (argc > 1) {
		if (argv[1][0] == '-' && &argv[1][1] != NULL) {
			switch (argv[1][1]) {
				case 'h':
					printf("-h: displays help\n-a: displays days remaining to 1st of January 2030\n");
					return 0;
					break;
				case 'a':
					double tmr = difftime(tm, (time_t)UTIME_2030);
					if (tmr > 0) {
						printf("Good luck!, you are gonna need it a ton...\n");
						printf("%d days have passed after the start of 2030...\n", abs((int)(tmr/86400)));
					} else {
						printf("%d days remaining to January 1st 2030\n", abs((int)(tmr/86400)));
					}
					return 0;
					break;
				default:
					break;
			}
		}
	} 
	char* cdate = ctime(&tm);
	printf("%s\n", cdate);

	return 0;	

}
