#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold the result of the operation
typedef struct {
    void *ptr;
    int status; // 0 for success, -1 for failure
    char message[100]; // Detailed message
} QzkadResult;

QzkadResult qzkad_v1(int operation, void *ptr, size_t num, size_t size) {
    QzkadResult result;
    result.ptr = ptr;
    result.status = 0; // Assume success by default
    strcpy(result.message, "Operation successful");

    switch (operation) {
        case 1: // malloc
            result.ptr = malloc(size);
            if (result.ptr == NULL) {
                result.status = -1;
                strcpy(result.message, "Memory allocation failed with malloc.");
            } else {
                strcpy(result.message, "Memory allocated using malloc.");
            }
            break;

        case 2: // calloc
            result.ptr = calloc(num, size);
            if (result.ptr == NULL) {
                result.status = -1;
                strcpy(result.message, "Memory allocation failed with calloc.");
            } else {
                strcpy(result.message, "Memory allocated using calloc.");
            }
            break;

        case 3: // realloc
            if (result.ptr == NULL) {
                result.ptr = malloc(size);
                if (result.ptr == NULL) {
                    result.status = -1;
                    strcpy(result.message, "Memory allocation failed with realloc (initial malloc).");
                } else {
                    strcpy(result.message, "Memory allocated using realloc (initial malloc).");
                }
            } else {
                void *new_ptr = realloc(result.ptr, size);
                if (new_ptr == NULL) {
                    result.status = -1;
                    strcpy(result.message, "Memory reallocation failed with realloc.");
                } else {
                    result.ptr = new_ptr;
                    strcpy(result.message, "Memory reallocated using realloc.");
                }
            }
            break;

        case 4: // free
            if (result.ptr != NULL) {
                free(result.ptr);
                result.ptr = NULL;
                strcpy(result.message, "Memory deallocated using free.");
            } else {
                result.status = -1;
                strcpy(result.message, "Attempted to free a NULL pointer.");
            }
            break;

        default:
            result.status = -1;
            strcpy(result.message, "Invalid operation number. Use 1 for malloc, 2 for calloc, 3 for realloc, or 4 for free.");
            break;
    }

    return result;
}
