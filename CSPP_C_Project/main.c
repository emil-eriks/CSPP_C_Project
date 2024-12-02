
#define _CRT_SECURE_NO_WARNINGS
#include "global.h"
#include "file_operations.h"
#include "line_operations.h"
#include "general_operations.h"

int main()
{
    FILE* changelog = createFile("changelog.txt"); // creating changelog so the functions can append to that changelog
    int choice;
    char fileName[256];
    char lineContent[256];
    int lineNumber;
    while (1)
    {
        // Display menu
        printf("\nFile Operations Menu:\n");
        printf("1. Create a file\n");
        printf("2. Copy a file\n");
        printf("3. Delete a file\n");
        printf("4. Show file content\n");
        printf("5. Append a line to a file\n");
        printf("6. Insert a line into a file\n");
        printf("7. Delete a line from a file\n");
        printf("8. Show a specific line from a file\n");
        printf("9. Count lines in a file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Create file
            printf("Enter the file name to create: ");
            scanf("%s", fileName);
            if (createFile(fileName)) {
                printf("File '%s' created successfully.\n", fileName);
            }
            break;

        case 2: // Copy file
        {
            char destinationFile[256];
            printf("Enter the source file name: ");
            scanf("%s", fileName);
            printf("Enter the destination file name: ");
            scanf("%s", destinationFile);
            copyFile(fileName, destinationFile);
        }
        break;

        case 3: // Delete file
            printf("Enter the file name to delete: ");
            scanf("%s", fileName);
            deleteFile(fileName);
            break;

        case 4: // Show file content
            printf("Enter the file name to display: ");
            scanf("%s", fileName);
            showFile(fileName);
            break;

        case 5: // Append a line
            printf("Enter the file name to append to: ");
            scanf("%s", fileName);
            printf("Enter the line to append: ");
            getchar();
            fgets(lineContent, sizeof(lineContent), stdin);
            lineContent[strcspn(lineContent, "\n")] = 0;
            appendLine(fileName, lineContent);
            break;

        case 6: // Insert a line
            printf("Enter the file name: ");
            scanf("%s", fileName);
            printf("Enter the line number to insert at: ");
            scanf("%d", &lineNumber);
            printf("Enter the line content: ");
            getchar();
            fgets(lineContent, sizeof(lineContent), stdin);
            lineContent[strcspn(lineContent, "\n")] = 0;
            insertLine(fileName, lineNumber, lineContent);
            break;

        case 7: // Delete a specific line
            printf("Enter the file name: ");
            scanf("%s", fileName);
            printf("Enter the line number to delete: ");
            scanf("%d", &lineNumber);
            deleteLine(fileName, lineNumber);
            break;

        case 8: // Show a specific line
            printf("Enter the file name: ");
            scanf("%s", fileName);
            printf("Enter the line number to display: ");
            scanf("%d", &lineNumber);
            showLine(fileName, lineNumber);
            break;

        case 9: // Count lines
            printf("Enter the file name: ");
            scanf("%s", fileName);
            int lineCount = countLines(fileName);
            printf("The file '%s' has %d lines.\n", fileName, lineCount);
            break;

        case 0: // Exit
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}