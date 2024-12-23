#include "global.h"
#include "file_operations.h"

// for the count line function,https://www.geeksforgeeks.org/c-program-count-number-lines-file/


int countLines(const char* fileName){
	int count = 0;
	char c;

	FILE* file = openFile(fileName);
	for (c = getc(file); c != EOF; c = getc(file))
		if (c == '\n') // Increment count if this character is newline
			count = count + 1;
	fclose(file);
	return count;
}

