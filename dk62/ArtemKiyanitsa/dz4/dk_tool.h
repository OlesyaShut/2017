#ifndef dk_tool_h
#define dk_tool_h
#include <stdio.h>

typedef struct tagKoleso
{
	char *pokrishka;
	char disk[10];
}Koleso;

typedef struct tagCar
{
	Koleso *KolvoKoles;
	int max;
	int curent;
}Car;

void AddKoleso (Car *PointerCar,char *InputPokrishka,char InputDisk[10]);
void DeleteKoleso (Car *PointerCar);
void DeleteCar(Car *PointerCar);
void writeString(FILE *aFile, char *aKey, char *aString);
void writeKoleso(FILE *aFile, Koleso *aKoleso);
void writeCar(FILE *aFile, Car *PCar);
void bubbleSortCars(Car *PointerCar, int aSize);
#endif
