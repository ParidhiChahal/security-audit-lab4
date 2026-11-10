#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defect 1: Unchecked malloc
void allocate_buffer(size_t size) {
    char *ptr = (char *)malloc(size); // No check if ptr is NULL
    strcpy(ptr, "Unchecked allocation test");
    printf("%s\n", ptr);
    free(ptr);
}

// Defect 2: Integer / Buffer Overflow
void process_size(int input_count) {
    int total_size = input_count * 100; // Potential integer overflow if input_count is large
    char *buf = (char *)malloc(total_size);
    char source[500] = "A massive string payload...";
    strcpy(buf, source); // Potential buffer overflow if total_size < strlen(source)
    free(buf);
}

// Defect 3: Use-After-Free
void free_resource(void) {
    char *data = (char *)malloc(50);
    strcpy(data, "Sensitive data");
    free(data);
    printf("Accessing after free: %s\n", data); // Use-after-free vulnerability
}

// Defect 4: Double Free
void cleanup(void) {
    char *ptr = (char *)malloc(30);
    free(ptr);
    free(ptr); // Double free vulnerability
}

// Defect 5: Uninitialized Memory Read
void parse_data(void) {
    int uninit_var;
    if (uninit_var == 10) { // Reading uninitialized variable
        printf("Matched\n");
    }
}

int main(void) {
    allocate_buffer(100);
    process_size(10);
    free_resource();
    cleanup();
    parse_data();
    return 0;
}
