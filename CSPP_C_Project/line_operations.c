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

