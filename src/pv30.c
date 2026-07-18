#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define UTIME_2030 1893456000 // UNIX TIMESTAMP FOR 1ST OF JAN 2030 00:00


int main(int argc, char* argv[]) {
	time_t tm = time(NULL);
	if (argc > 1) {
		if (argv[1][0] == '-' && &argv[1][1] != NULL) {
			switch (argv[1][1]) {
				case 'h':
					printf("SAMPLE HELP TEXT\n");
					return 0;
					break;
				case 'a':
					double tmr = difftime(tm, (time_t)UTIME_2030);
					printf("days remaining to January 1st 2030 00:00 : %d\n", abs((int)(tmr/86400)));
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
