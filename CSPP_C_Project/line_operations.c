#define _CRT_SECURE_NO_WARNINGS
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
		return;
	}
	fputs(text, filePtr);
    fputc('\n', filePtr);
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

    char message[256];
    int nLines = countLines(fileName);
    sprintf(message, "Deleted a line from %s successfully, it now has %d lines.", fileName, nLines);
    appendLine("changelog.txt", message);
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

    char message[256];
    int nLines = countLines(fileName);
    sprintf(message, "Inserted a line into %s successfully, it now has %d lines.", fileName, nLines);
    appendLine("changelog.txt", message);
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

    char message[256];
    int nLines = countLines(fileName);
    sprintf(message, "Deleted a line from %s successfully, it had %d lines.", fileName, nLines);
    appendLine("changelog.txt", message);
}

