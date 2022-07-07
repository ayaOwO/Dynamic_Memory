#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void addString(char*** stringArray, int size, char* toAdd, int toAddSize);
char** split(const char* str, int* outputCount);
void compareBoth(const char* a, const char* b);
void reverseString(char* arr, int size);
void reverseUserInput();
int stringCompare(const char* a, const char* b);

int main(void) {
	compareBoth("a", "b");
	compareBoth("b", "a");
	
	compareBoth("aa", "a");
	compareBoth("a", "aa");

	compareBoth("a", "ba");
	compareBoth("ba", "a");

	char* text = "This is a very long text which is split to 12 parts";
	int outputCount;
	char** ans = split(text, &outputCount);

	for (int i = 0; i < outputCount; i++) {
		puts(ans[i]);
	}

	printf("Part count: %d", outputCount);

	return 0;
}

void compareBoth(const char* a, const char* b) {
	if (strcmp(a, b) == stringCompare(a, b)) {
		printf("Works");
	} else {
		printf("failed");
	}

	printf("\n");
}

void reverseUserInput() {
	char buffer[BUFFER_SIZE];
	printf("Enter your name: ");
	fgets(buffer, BUFFER_SIZE, stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	reverseString(buffer, strlen(buffer));
	puts(buffer);
}

void reverseString(char* arr, int size) {
	char holder;
	int center = (size) / 2;

	for (int i = 0; i < center; i++) {
		holder = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = holder;
	}
}

int stringCompare(const char* a, const char* b) {
	int length;
	int aLength = strlen(a);
	int bLength = strlen(b);

	if (aLength < bLength) {
		length = aLength;
	} else {
		length = bLength;
	}
	
	for (int i = 0; i < length; i++) {
		if (a[i] != b[i]) {
			if (a[i] > b[i]) {
				return 1;
			} else {
				return -1;
			}
		}
	}

	if (aLength == bLength) {
		return 0;
	}
	else if (aLength > bLength)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

char** split(const char* str, int* outputCount) {
	*outputCount = 0;
	int partitionSize = 0;
	char** splittedString = (char**)malloc(sizeof(char*));
	int i;
	
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			char* splitStringStart = str + i - partitionSize + 1;
			addString(&splittedString, *outputCount, splitStringStart, partitionSize);

			partitionSize = 0;
			(*outputCount)++;
		}

		partitionSize++;
	}
	
	int splitStringStart = str + i - partitionSize + 1;
	addString(&splittedString, *outputCount, splitStringStart, partitionSize);
	(*outputCount)++;

	return splittedString;
}


void addString(char*** stringArray, int size, char* toAdd, int toAddSize) {
	*stringArray = (char**)realloc(*stringArray, (size + 1) * sizeof(char*));
	(*stringArray)[size] = (char*)malloc((toAddSize + 1) * sizeof(char));

	for (int j = 0; j < toAddSize; j++) {
		(*stringArray)[size][j] = toAdd[j];
	}

	(*stringArray)[size][toAddSize] = '\0';
}