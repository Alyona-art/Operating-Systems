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
		while(true) {
			struct input_event evt;
			ssize_t b = read(fd, &evt, sizeof(evt));
			if(evt.type == 1) {
				if(evt.value == 1)
					printf("PRESSED %#06x (%d)\n",
					evt.code, evt.code);
				else if(evt.value == 0)
					printf("RELEASED %#06x (%d)\n",
					evt.code, evt.code);
				else
					printf("REPEATED %#06x (%d)\n",
					evt.code, evt.code);	
			}
		}
	}
	return 0;
}
