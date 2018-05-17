#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <target ELF>\n", argv[0]);
		exit(EXIT_SUCCESS);
	}


	int target_fd = open(argv[1], O_RDONLY);

	if (target_fd < 0)
	{
		printf("Failed to open %s!\n", argv[1]);
		exit(EXIT_FAILURE);
	} 

	/* get file size with lseek */

	//size_t target_size = lseek(target_fd, 
}
