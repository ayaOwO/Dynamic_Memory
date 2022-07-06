#include <stdio.h>
#include <stdlib.h>

#define FIBONACCI_START 1

int* createIndexArray(int n);
int* fibonacci(int maxNumber);
int* duplicateNumbers(const int* numbers, int length);
void swap(int* first, int* second);

int main(void) {
	int* arr = fibonacci(100);

	for (int i = 0; i < 12; i++) {
		printf("%d\n", arr[i]);
	}

	free(arr);

	return 0;
}

int* createIndexArray(int n) {
	int* arr = (int*)malloc(n * sizeof(int));

	if (arr != NULL) {
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
	}

	return arr;
}

int* duplicateNumbers(const int* numbers, int length)
{
	int* duplicateArray = (int*)malloc(length * sizeof(int));

	if (duplicateArray != NULL) {
		for (int i = 0; i < length; i++) {
			duplicateArray[i] = numbers[i];
		}
	}

	return duplicateArray;
}

int* fibonacci(int maxNumber) {
	int i = 0;
	int* arr = (int*)malloc(sizeof(int));
	int nextNumber = getFibonacci(i);

	while (nextNumber < maxNumber) {
		int* biggerArray = (int*)realloc(arr, (i + 1) * sizeof(int));

		if (biggerArray != NULL) {
			arr = biggerArray;
			arr[i] = nextNumber;
			i++;
			nextNumber = getFibonacci(i);
		} else {
			free(arr);
			return NULL;
		}
	}

	return arr;
}

int getFibonacci(int index) {
	int firstValue = FIBONACCI_START;
	int secondValue = 1;

	for (int i = 2; i < index; i++) {
		int nextValue = firstValue + secondValue;
		swap(&firstValue, &secondValue);
		firstValue = nextValue;
	}

	if (index == 0) {
		return FIBONACCI_START;
	}
	else if (index == 1) {
		return secondValue;
	}

	return firstValue;
}

void swap(int* first, int* second) {
	int holder = *first;
	*first = *second;
	*second = holder;
}

