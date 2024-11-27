#pragma once

void appendLine(const char* fileName, const char* text);
void deleteLine(const char* fileName, int lineToDelete);
void insertLine(const char* fileName, int lineToInsert, const char* insertText);
void showLine(const char* fileName, int lineToShow);