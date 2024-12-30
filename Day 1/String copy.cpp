#include <stdio.h>
void stringCopy(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
int main() {
    char source[100], destination[100];
    printf("Enter the source string: ");
    fgets(source, sizeof(source), stdin);
    int len = 0;
    while (source[len] != '\0') {
        if (source[len] == '\n') {
            source[len] = '\0';
            break;
        }
        len++;
    }
    stringCopy(source, destination);
    printf("Source String: %s\n", source);
    printf("Copied String: %s\n", destination);
    return 0;
}
