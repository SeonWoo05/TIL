#include <stdio.h>

void showData(char* data[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", data[i]);
    }
    printf("\n");
}

void swapStrings(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

char** sortData(char* arr[], int n) {
	char* temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                swapStrings(&arr[j], &arr[j + 1]);
            }
        }
    }
    return arr;
}

void freeMemory(char** p, int n) {
    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
}

char** insertData(char* data[], int size, const char* value) {
    char** result = (char**)malloc((size + 1) * sizeof(char*));

    int pos = 0;
    while (pos < size && strcmp(value, data[pos]) > 0) {
        pos++;
    }

    for (int i = 0; i < pos; i++) {
        result[i] = strdup(data[i]);
    }

    result[pos] = strdup(value);

    for (int i = pos; i < size; i++) {
        result[i + 1] = strdup(data[i]);
    }

    return result;
}

int main() {
    char* data[] = {"pear", "jujube", "melon", "persimmon", "avocado", "grape", "blueberry"};
    int size = 7;
    
    char newData[10];
    int newSize = size;
	char** result = NULL;

	sortData(data, size);

	for (int i = 0; i < 3; i++) {
        scanf("%s", newData);
        if (result != NULL) {
            char** temp = insertData(result, newSize, newData);
            freeMemory(result, newSize);
            result = temp;
            newSize++;
        } else {
            result = insertData(data, newSize, newData);
            newSize++;
        }
    }

	showData(result, newSize);
    
    freeMemory(result, newSize);
    
    return 0;
}
