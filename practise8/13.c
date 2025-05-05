#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define FILE_NAME "test_file.txt"
#define FILE_SIZE 1024 * 1024 * 10 

void write_using_write() {
	clock_t start = clock();
    int fd = open(FILE_NAME,
     O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); 
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char data[FILE_SIZE];
    memset(data, 'A', FILE_SIZE); 

    write(fd, data, FILE_SIZE);
    clock_t end = clock();

    printf("write() took %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    close(fd);
}

void write_using_mmap() {
	clock_t start = clock();
    int fd = open(FILE_NAME,
     O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);  
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
	
    if (ftruncate(fd, FILE_SIZE) == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }
    

    char *data = mmap(NULL, FILE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    memset(data, 'A', FILE_SIZE);

    msync(data, FILE_SIZE, MS_SYNC);
    clock_t end = clock();

    printf("mmap() took %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    close(fd);
}

int main() {
    write_using_write();
    write_using_mmap();

    return 0;
}
