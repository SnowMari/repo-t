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
	char Credit�ard[SIZECHAR];
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

	int Menu();
	int CmdMenu;
	std::cout << "|===========================================|" 
	<< std::endl;
	std::cout << "| Программа по практике			    |" 
	<< std::endl;
	std::cout << "| Тема: \"Электронная ведомость.\"	    |"
	<< std::endl;
	std::cout << "| Вспомогательное приложение	            |" 
	<< std::endl;
	std::cout << "| для подсчёта стипендии студентов.         |" 
	<< std::endl;
	std::cout << "| Выполнили студенты группы ИВТ-101         |"
	<< std::endl;
	std::cout << "| Шитый А.Д."" Авдеенко Е.Е."
	" Кондратенко М.В. ""|"
	<< std::endl;
	std::cout<< "|===========================================|";


	system("pause");
}


int Menu()
{
	unsigned int NumberCmdMenu;
	
		for(;;)
		{
			std::cout << std::endl;
			std::cout 
			<< "|===========================================|" 
			<< std::endl;
			std::cout 
			<< "|                   Меню                    |" 
			<< std::endl;
			std::cout 
			<< "|0 - завершить работу                       |" 
			<< std::endl;
			std::cout 
			<< "|1 - Добавить студента			    |" 
			<< std::endl;
			std::cout 
			<< "|2 - Вывести информацию об студенте         |" 
			<< std::endl;
			std::cout 
			<< "|3 - Вывести всех студентов                 |" 
			<< std::endl;
			std::cout 
			<< "|4 - Cохранить, записав в файл              |" 
			<< std::endl;
			std::cout 
			<< "|5 - Очистить текстовый файл                |" 
			<< std::endl;
			std::cout 
			<< "|===========================================|" 
			<< std::endl;
			std::cout << "Ввод: ";
			NumberCmdMenu = _getch() - '0';
		if(NumberCmdMenu < EXIT ||
		   NumberCmdMenu > CLEAR_FILE)
		{
			std::cout<< "Ошибка - такой команды нет" 
			<< std::endl;
			continue;
		}
		else
		{
			std::cout <<"Номер команды меню: ";
			std::cout << NumberCmdMenu <<std::endl;
			return NumberCmdMenu;
		}
	return NumberCmdMenu;
	}
}



