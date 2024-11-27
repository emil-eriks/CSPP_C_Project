#include "global.h"
#include "line_operations.h"
#include "file_operations.h"


// https://www.tutorialspoint.com/c_standard_library/c_function_fputs.htm for appendLine


void appendLine(const char* fileName, const char* text)
{
	FILE* filePtr = fopen(fileName, "a"); //
	if (filePtr == NULL)
	{
		printf("File doesn't exist.\n");
		return NULL;
	}
	fputs(text, filePtr);
	fclose(filePtr);
}

void deleteLine(const char* fileName, int lineToDelete) {
    FILE* file = openFile(fileName);
    FILE* tempFile = createFile("temp.txt");

    if (!file || !tempFile) {
        printf("Error opening the files");
        return;
    }

    char buffer[1024];
    int currentLine = 1;

    while (fgets(buffer, sizeof(buffer), file)) { //this reads each line by line into buffer
        if (currentLine != lineToDelete) {
            fputs(buffer, tempFile); //puts the buffer into the temp file
        }
        currentLine++; //incrementing the line
    }

    fclose(file);
    fclose(tempFile);

    remove(fileName);
    rename("temp.txt", fileName);
}

void insertLine(const char* fileName, int lineToInsert, const char* insertText) {
    FILE* file = openFile(fileName);
    FILE* tempFile = createFile("temp.txt");

    if (!file || !tempFile) {
        printf("Error opening the files");
        return;
    }

    char buffer[1024];
    int currentLine = 1;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (currentLine == lineToInsert) {
            fputs(insertText, tempFile);
            fputs("\n", tempFile);
        }
        fputs(buffer, tempFile);
        currentLine++;
    }

    fclose(file);
    fclose(tempFile);

    remove(fileName);
    rename("temp.txt", fileName);
}

void showLine(const char* fileName, int lineToShow) {
    FILE* file = openFile(fileName);
    char buffer[1024];
    int currentLine = 1;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (currentLine == lineToShow) {
            printf("%s", buffer);
            break;
        }
        currentLine++;
    }
    fclose(file);
    if (currentLine < lineToShow) {
        printf("Line %d does not exist in the file.\n", lineToShow);
    }
}

