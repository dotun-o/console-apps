/*
 TEXT FILE MAKER v0.1.0
 Ⓒ2018 Dotun Ogunsakin
 ------------------------------
 Creates a ~1KB text file with unique file names (using epoch time)
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024

FILE* fPtr;

int main(int argv, char* argc[]) {
    // Setup variable to hold user input 
    char input[MAX_FILE_SIZE];
    
    // Get user input
    printf("Type the text (max: 1023 characters) you wish to save to file (press ENTER when done):\n");
    fgets(input, MAX_FILE_SIZE, stdin);
    
    // Current time will be appended to file name, for unique files each time
    time_t currentTime = time(NULL);
    
    // Set up file name
    char fileName[32];
    sprintf(fileName, "file_%li.txt", (long)currentTime);
    
    // Write user input to file
    fPtr = fopen(fileName, "w");
    fprintf(fPtr, "%s", input);
    fclose(fPtr);
    
    printf("Text saved to file.\n");
    
    return 0;
}
