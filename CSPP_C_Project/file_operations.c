#define _CRT_SECURE_NO_WARNINGS
#include "global.h"

// used documentation: https://www.w3schools.com/c/c_files.php (for creating file), https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/ (for copying file)
// https://www.geeksforgeeks.org/c-program-delete-file/ for delete function


FILE* openFile(const char* fileName) // same as create file just doesnt create it if it doesnt exists
{
	FILE* filePtr = NULL;
	if (fileName == NULL)
	{
		printf("No file name has been provided.\n");
		return NULL;
	}
	filePtr = fopen(fileName, "r");
	if (filePtr == NULL)
	{
		printf("File doesn't exist.\n");
		return NULL;
	}
	return filePtr;
}

FILE* createFile(const char* fileName)
{
    if (fileName == NULL)
    {
        printf("No file name has been given.\n");
        return NULL;
    }
    FILE* filePtr = openFile(fileName);
    if (filePtr != NULL)
    {
        printf("File already exists.\n");
        fclose(filePtr);
        return NULL;
    }
    filePtr = fopen(fileName, "w");
    if (filePtr == NULL)
    {
        perror("Error creating file\n");
        return NULL;
    }
    printf("File created successfully.\n");
    return filePtr;
}

void copyFile(const char* copyingFrom, const char* copyingTo)
{
    FILE* copyingFromFile = openFile(copyingFrom);
    if (copyingFromFile == NULL)
    {
        printf("Failed to open the source file.\n");
        return;
    }
    FILE* copyingToFile = createFile(copyingTo);
    if (copyingToFile == NULL)
    {
        printf("Failed to create the destination file.\n");
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

    printf("File copy operation completed successfully.\n");
}

void deleteFile(const char* fileName)
{
    if (remove(fileName) == 0)
        printf("Deleted successfully");
    else
        printf("Unable to delete the file");
}

