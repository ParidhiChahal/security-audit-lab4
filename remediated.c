#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

#define MAX_BUFFER_SIZE 1024

int process_data(size_t input_count, const char *input_data) {
    // 1. Safe Arithmetic Check for Integer Overflow
    if (input_count > SIZE_MAX / sizeof(char)) {
        fprintf(stderr, "Error: Integer overflow detected in size calculation.\n");
        return -1;
    }
    
    size_t total_size = input_count * sizeof(char);
    if (total_size > MAX_BUFFER_SIZE) {
        fprintf(stderr, "Error: Requested size exceeds maximum buffer limit.\n");
        return -1;
    }

    // 2. Checked Allocation (Null check)
    char *buffer = (char *)malloc(total_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed (Out of Memory).\n");
        return -1;
    }

    // 3. Correct Initialization
    memset(buffer, 0, total_size);

    // Safe copy preventing buffer overflow
    if (input_data != NULL) {
        memcpy(buffer, input_data, total_size - 1);
        buffer[total_size - 1] = '\0';
    }

    // Process data...
    printf("Processed successfully: %s\n", buffer);

    // 4. Single and Correct Free
    free(buffer);
    buffer = NULL; // Prevent use-after-free

    return 0;
}

int main(void) {
    const char *test_input = "Hello, Secure World!";
    process_data(strlen(test_input) + 1, test_input);
    return 0;
}
