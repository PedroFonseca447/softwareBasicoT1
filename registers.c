#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>

#define FILE_PATH "registers.bin"
#define FILE_SIZE 1024  // Same size as used in the first program

// Function to open or create the file and map it into memory
char* registers_map(const char* file_path, int file_size, int* fd) {
    *fd = open(file_path, O_RDWR | O_CREAT, 0666);
    if (*fd == -1) {
        perror("Error opening or creating file");
        return NULL;
    }

    // Ensure the file is of the correct size
    if (ftruncate(*fd, file_size) == -1) {
        perror("Error setting file size");
        close(*fd);
        return NULL;
    }

    // Map the file into memory
    char *map = mmap(0, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, *fd, 0);
    if (map == MAP_FAILED) {
        perror("Error mapping file");
        close(*fd);
        return NULL;
    }

    return map;
}

// Function to release mapped memory and file descriptor
int registers_release(void* map, int file_size, int fd) {
    if (munmap(map, file_size) == -1) {
        perror("Error unmapping the file");
        close(fd);
        return -1;
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        return -1;
    }

    return 0;
}

void print_binary(unsigned short value) {
    // Comece a partir do bit mais significativo
    for (int i = 15; i >= 0; i--) {
        // Verifique se o bit na posição 'i' está definido
        if (value & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }

        // Adicione espaços para melhor visualização
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int fd;
    // Open the file and map it into memory
    char* map = registers_map(FILE_PATH, FILE_SIZE, &fd);
    if (map == NULL) {
        return EXIT_FAILURE;
    }

    unsigned short *base_address = (unsigned short *)map;
    unsigned short *r0 = base_address + 0x00;
    unsigned short *r1 = base_address + 0x01;
       unsigned short *r2 = base_address + 0x00;
    unsigned short *r3 = base_address + 0x01;
       unsigned short *r4 = base_address + 0x00;
    unsigned short *r5 = base_address + 0x01;
       unsigned short *r6 = base_address + 0x00;
    unsigned short *r7 = base_address + 0x01;
       unsigned short *r8 = base_address + 0x00;
    unsigned short *r9 = base_address + 0x01;
       unsigned short *r10 = base_address + 0x00;
    unsigned short *r11 = base_address + 0x01;
       unsigned short *r12 = base_address + 0x00;
    unsigned short *r13 = base_address + 0x01;
       unsigned short *r14 = base_address + 0x00;
    unsigned short *r15 = base_address + 0x01;
    printf("Initial value of R0: 0x%02x\n", *r0);
    printf("Initial value of R1: 0x%02x\n", *r1);

    // Write a new value to R0
    *r0 = *r0 | 0x00;

    // Release resources
    if (registers_release(map, FILE_SIZE, fd) == -1) {
        return EXIT_FAILURE;
    }
     printf("Valor de R0 em binário: ");
    print_binary(r0);

    return EXIT_SUCCESS;
}