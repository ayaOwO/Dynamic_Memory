#include <stdio.h>
#include "ArrayList.h"

int main(void) {
	ArrayList* list = createArrayList(2);
	int lastCapacity = list->capacity;

	for (int i = 0; i < 100; i++) {
		if (list->capacity > lastCapacity) {
			lastCapacity = list->capacity;
			printf("New capacity %d\n", lastCapacity);
		}

		addValue(list, i + 3);
	}

	printArrayList(list);

	printf("\n");

	for (int i = 0; i < 100; i++) {
		if (list->capacity < lastCapacity) {
			lastCapacity = list->capacity;
			printf("New capacity %d\n", lastCapacity);
		}

		int value;

		if (getValue(list, i, &value)) {
			printf("removed value %d\n", value);
		} else {
			printf("Index out of range index:%d|size:%d\n", i, list->size);
		}

		removeValue(list, i);
	}

	printArrayList(list);

	return 0;
}