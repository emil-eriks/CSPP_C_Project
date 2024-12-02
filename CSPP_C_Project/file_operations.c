#define _CRT_SECURE_NO_WARNINGS
#include "global.h"
#include "line_operations.h"
#include "general_operations.h"

// used documentation: https://www.w3schools.com/c/c_files.php (for creating file), https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/ (for copying file)
// https://www.geeksforgeeks.org/c-program-delete-file/ for delete function, https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/ showFile function


FILE* openFile(const char* fileName) // same as create file just doesnt create it if it doesnt exists
{
	FILE* filePtr = NULL;
	if (fileName == NULL)
	{
		perror("No file name has been provided.\n");
		return NULL;
	}
	filePtr = fopen(fileName, "r");
	if (filePtr == NULL)
	{
		return NULL;
	}
	return filePtr;
}

FILE* createFile(const char* fileName)
{
    if (fileName == NULL)
    {
        perror("No file name has been given.\n");
        return NULL;
    }
    FILE* filePtr = openFile(fileName);
    if (filePtr != NULL)
    {
        fclose(filePtr);
        return NULL;
    }
    filePtr = fopen(fileName, "w");
    if (filePtr == NULL)
    {
        perror("Error creating file\n");
        return NULL;
    }

    char message[256];
    sprintf(message, "%s has been created successfully, 0 lines. ", fileName);
    appendLine("changelog.txt", message);

    return filePtr;
}

void copyFile(const char* copyingFrom, const char* copyingTo)
{
    FILE* copyingFromFile = openFile(copyingFrom);
    if (copyingFromFile == NULL)
    {
        perror("Failed to open the source file.\n");
        return;
    }
    FILE* copyingToFile = createFile(copyingTo);
    if (copyingToFile == NULL)
    {
        perror("Failed to create the destination file.\n");
        fclose(copyingFromFile); // Close the source file
        return;
    }
    int c; 
    while ((c = fgetc(copyingFromFile)) != EOF)
    {
        if (fputc(c, copyingToFile) == EOF)
        {
            perror("Error writing to destination file");
            break;
        }
    }

    fclose(copyingFromFile);
    fclose(copyingToFile);

    char message[256];
    int nLines = countLines(copyingFrom);
    sprintf(message, "File copied from %s to %s successfully, both files have %d lines.", copyingFrom, copyingTo, nLines);
    appendLine("changelog.txt", message);
}

void deleteFile(const char* fileName)
{
    if (remove(fileName) == 0) {
        printf("File '%s' deleted successfully\n", fileName);  // Correct message
    }
    else {
        perror("Unable to delete the file");
        return;  // Ensure proper early exit if delete fails
    }

    char message[256];
    int nLines = countLines(fileName);
    sprintf(message, "Deleted %s successfully, it had %d lines.", fileName, nLines);
    appendLine("changelog.txt", message);
}

void showFile(const char* fileName) {
    FILE* filePtr = openFile(fileName);
    if (filePtr == NULL) {
        perror("Error opening file to display content");
        return;
    }
    char ch;
    while ((ch = fgetc(filePtr)) != EOF) {
        putchar(ch);  // Use putchar instead of printf for single characters
    }
    fclose(filePtr);

    char message[256];
    int nLines = countLines(fileName);
    sprintf(message, "Showed %s in console, it had %d lines.", fileName, nLines);
    appendLine("changelog.txt", message);
}

