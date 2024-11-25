#define _CRT_SECURE_NO_WARNINGS
#include "global.h"

// used documentation: https://www.w3schools.com/c/c_files.php

FILE* createFile(const char* fileName)
{
	FILE* filePtr = NULL;
	if (fileName == NULL)
	{
		printf("No file name has been given.");
		return NULL;
	}
	filePtr = fopen(filePath, "w");
	if (filePtr == NULL)
	{
		printf("File pointer is null");
		return NULL;
	}
	return filePtr;
}

