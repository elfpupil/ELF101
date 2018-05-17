#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>


void ehdr_parser(void *);


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

	size_t target_size = lseek(target_fd, 0, SEEK_END);

	if (target_size < 0)
	{
		perror("lseek failed!");
		close(target_fd);
		exit(EXIT_FAILURE);
	} 

	// mapping the file into memory
	void *target_ptr = mmap(0, target_size, PROT_READ | PROT_WRITE_MAP_PRIVATE, target_sd, 0);

	if (target_ptr < 0)
	{
		perror("mmap failed!");
		close(target_fd);
		exit(EXIT_FAILURE)
	}

	ehdr_parser(target_ptr);
}


/* ELF header parser */
void ehdr_parser(void *target_ptr)
{

	Elf64_Ehdr *Elf64_ptr = NULL;

	Elf64_ptr = (Elf64_Ehdr *)target_ptr;
	

	printf("=============================== EHDR ===============================\n");
	printf("e_ident: %s\n", Elf64_ptr->e_ident);
	printf("e_type: %p\n", (void)Elf64_ptr->e_machine);
	printf("e_shoff: %ld\n", (unsigned long)Elf64_ptr->e_shoff);
    	printf("e_ehsize: %d\n", Elf64_ptr->e_ehsize & 0xffff);
    	printf("sizeof(Elf64_Ehdr): %d\n", sizeof(Elf64_Ehdr));
    	printf("e_phentsize: %d\n", Elf64_ptr->e_phentsize);
    	printf("e_phnum: %d\n", Elf64_ptr->e_phnum);
    	printf("e_shentsize: %d\n", Elf64_ptr->e_shentsize);
    	printf("e_shnum: %d\n", Elf64_ptr->e_shnum);
    	printf("e_shstrndx: %d\n", Elf64_ptr->e_shstrndx);
 	printf("=============================== EHDR ===============================\n");

}
