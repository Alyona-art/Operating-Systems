#include <stdio.h>
#include <dirent.h>

int main() {
	DIR *dir = opendir("/");
	if (dir == NULL) return -1;
	struct dirent *file;
	while ((file = readdir(dir)) != NULL) {
		if (file->d_type == DT_REG || file->d_type == DT_DIR)
			printf("%s\n", file->d_name);
	}
	closedir(dir);
	return 0;
}
