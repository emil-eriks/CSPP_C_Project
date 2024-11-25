

#include "global.h"
#include "file_operations.h"
#include "line_operations.h"
#include "general_operations.h"

int main()
{
    printf("Hello, World!\n");
    //createFile(filePath);
    //copyFile(filePath, "C:\\Users\\Emil\\Desktop\\outputCSPP\\test2.txt");
    //deleteFile(filePath);
    //showFile(filePath);
    appendLine(filePath, "hello how are you");
    return 0;
}