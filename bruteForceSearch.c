//10. Implementation of Brute force String searching technique. 
#include <stdio.h>
#include <string.h>

void bruteForceSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;

        // Check for a match at the current position
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found, break out of the inner loop
            }
        }

        // If the inner loop completes without breaking, a match is found
        if (j == patternLength) {
            printf("Pattern found at position %d\n", i);
        }
    }
}

int main() {
    char text[1000];
    char pattern[100];

    printf("Enter the main text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove the newline character if present

    printf("Enter the pattern to search for: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove the newline character if present

    printf("\nSearching for pattern in the text...\n");

    bruteForceSearch(text, pattern);

    return 0;
}

