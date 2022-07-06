#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

#define SUCCESS 1
#define FAILURE 0

ArrayList* createArrayList(int capacity) {
	ArrayList* arrayList = (ArrayList*)malloc(sizeof(ArrayList));

	if (arrayList != NULL) {
		arrayList->resizedFactor = 2;
		arrayList->capacity = getClosestPower(arrayList->resizedFactor, capacity);
		arrayList->size = 0;
		arrayList->data = (int*)malloc(capacity * sizeof(int));
	}

	return arrayList;
}

int getClosestPower(int n, int wantedValue) {
	int powerOf = n;
	
	while (n < wantedValue) {
		n *= powerOf;
	}

	return n;
}

int getValue(ArrayList* arrayList, int index, int* value) {
	int isIndexInRange;

	if (index < arrayList->size) {
		*value = arrayList->data[index];
		isIndexInRange = SUCCESS;
	} else {
		isIndexInRange = FAILURE;
	}

	return isIndexInRange;
}

int addValue(ArrayList* arrayList, int value) {

	if (arrayList->size >= arrayList->capacity) {
		if (!resizeArray(arrayList, arrayList->capacity * arrayList->resizedFactor)) {
			return FAILURE;
		}
	}

	arrayList->data[arrayList->size] = value;
	arrayList->size++;

	return SUCCESS;
}

int resizeArray(ArrayList* arrayList, int newSize) {
	if (newSize >= arrayList->size) {
		arrayList->capacity = newSize;
		int* biggerArray = (int*)realloc(arrayList->data, arrayList->capacity * sizeof(int));

		if (biggerArray != NULL) {
			arrayList->data = biggerArray;
			return SUCCESS;
		}
	}

	return FAILURE;
}

int removeValue(ArrayList* arrayList, int index) {
	if (index < arrayList->size) {
		for (int i = index; i < arrayList->size - 1; i++) {
			arrayList->data[i] = arrayList->data[i + 1];
		}

		arrayList->size--;

		if (arrayList->size * arrayList->resizedFactor < arrayList->capacity) {
			resizeArray(arrayList, arrayList->capacity / arrayList->resizedFactor);
		}

		return SUCCESS;
	}

	return FAILURE;
}

ArrayList* cloneArrayList(ArrayList* src) {
	ArrayList* dst = (ArrayList*)malloc(sizeof(ArrayList));

	if (dst != NULL) {
		int* data = (int*)malloc(src->capacity * sizeof(int));

		if (data != NULL) {
			for (int i = 0; i < src->size; i++) {
				dst->data[i] = src->data[i];
			}

			dst->size = src->size;
			dst->capacity = src->capacity;
			dst->resizedFactor = src->resizedFactor;

			return dst;
		}
	}

	return NULL;
}

void printArrayList(ArrayList* arrayList) {
	int i;

	for (i = 0; i < arrayList->size - 1; i++) {
		printf("%d, ", arrayList->data[i]);
	}

	printf("%d", arrayList->data[i]);
}

void freeArrayList(ArrayList* arrayList) {
	if (arrayList->data != NULL) {
		free(arrayList->data);
	}
}

