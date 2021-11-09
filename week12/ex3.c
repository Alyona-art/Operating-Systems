#include<linux/input.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>

int main() {
	char *device = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	int fd = open(device, O_RDONLY);
	if(fd<0) {
		return EXIT_FAILURE;
	}
	else {
		bool A = false;
		bool C = false;
		bool E = false;
		bool P = false;
		bool O = false;
		bool S = false;
		
		printf("Available shortcuts:\n");
		printf("p + e   -   I passed the Exam!\n");
		printf("c + a + p   -   Get some cappuccino!\n");
		printf("o + s + a   -   Get A for OS corse!\n");
		
		while(true) {
			struct input_event evt;
			ssize_t b = read(fd, &evt, sizeof(evt));
			if(evt.type == 1) {
				if(evt.value == 1) {
					if(evt.code == 30)
						A = true;
					if(evt.code == 46)
						C = true;
					if(evt.code == 18)
						E = true;
					if(evt.code == 25)
						P = true;
					if(evt.code == 24)
						O = true;
					if(evt.code == 31)
						S = true;
				}
				else if(evt.value == 0) {
					if(evt.code == 30)
						A = false;
					if(evt.code == 46)
						C = false;
					if(evt.code == 18)
						E = false;
					if(evt.code == 25)
						P = false;
					if(evt.code == 24)
						O = false;
					if(evt.code == 31)
						S = false;
				}
				if(P && E)
					printf("\nI passed the Exam!\n");
				if(C && A && P)
					printf("\nGet some cappuccino!\n");
				if(O && S && A)
					printf("\nGet A for OS corse!\n");
			}
		}
	}
	return 0;
}
