#pragma once


typedef struct ArrayList {
	int capacity;
	int size;
	int* data;
	int resizedFactor;
} ArrayList;

ArrayList* cloneArrayList(ArrayList* src);
int removeValue(ArrayList* arrayList, int index);
int resizeArray(ArrayList* arrayList, int resizeFactor);
int addValue(ArrayList* arrayList, int value);
int getValue(ArrayList* arrayList, int index, int* value);
ArrayList* createArrayList(int capacity);
int getClosestPower(int n, int wantedValue);
void printArrayList(ArrayList* arrayList);
void freeArrayList(ArrayList* arrayList);

