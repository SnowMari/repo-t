#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>

#define SIZECHAR 50

enum menu {EXIT, ADD_STUDENT, PRINT_STUDENT,
		   PRINT_ALL_STUDENT, WRITE_INTO_FILE,
		   CLEAR_FILE};

struct StudentBaseDate 
{
    int id; 
	char group[SIZECHAR];
	char surname[SIZECHAR];
    char name[SIZECHAR];
	char CreditСard[SIZECHAR];
	double stipend;
	double SumStipend;
	double MTotalCash;
	double STotalCash;
	// указатель на след элемент списка
    StudentBaseDate* next; 
};

void _tmain()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");

	system("pause");
}



