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
	char CreditCard[SIZECHAR];
	double stipend;
	double SumStipend;
	double MTotalCash;
	double STotalCash;
    StudentBaseDate* next; 
};

void ReadFromFile(StudentBaseDate* head);
void WriteIntoFile(StudentBaseDate* head);

void _tmain()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

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

	StudentBaseDate* head = new StudentBaseDate; 
    head->next = NULL;
    head->id = 0;
	ReadFromFile(head);

	do
	{
		CmdMenu = Menu();
		switch (CmdMenu)
		{
			case EXIT:
				return;
				break;
			case ADD_STUDENT: 
			{
				char MatHelp[5];
				char alltest[5];
				char SocialHelp[5];		
				char kursovay[5];
				char pract[5];
				char statiy[5]; 
				char SportAchiv[5];
				int PracticeWork;
				int CourseWork;
				int firstEx, secondEx, thirdEx, FourEx;
				StudentBaseDate* buffer = head; 

				while (buffer->next != NULL)
				{
					buffer = buffer->next;
				} 
				StudentBaseDate* NewElement =
				new StudentBaseDate; 
				NewElement->id = buffer->id + 1;
				buffer->next = NewElement;
				NewElement->next = NULL;

				std::cout << "Введите группу: ";
				std::cin >> NewElement->group;
				std::cout << "Введите фамилию: ";
				std::cin >> NewElement->surname;
				std::cout << "Введите имя: ";
				std::cin >> NewElement->name;
				std::cout 
				<< "Введите номер зачётной книжки: ";
				std::cin >> NewElement->CreditСard;
				std::cout 
				<< "Введите оценку за первый экзамен: ";
				std::cin >> firstEx;
				std::cout 
				<< "Введите оценку за второй экзамен: ";
				std::cin >> secondEx;
				std::cout 
				<< "Введите оценку за третий экзамен: ";
				std::cin >> thirdEx;
				std::cout 
				<< "Введите оценку за четвёртый экзамен: ";
				std::cin >> FourEx;
				std::cout 
				<< "Сдана ли курсовая " << std::endl;
				std::cout << "(Да или Нет?) ";
				std::cin >> kursovay;

				if(kursovay[0] == 'Д' && kursovay[1] == 'а')
				{
					std::cout << "Оценка за курсовую: ";
					std::cin >> CourseWork;
				}
				std::cout << "Сдана ли практика ";
				std::cout << "(Да или Нет)? ";
				std::cin >> pract;
				if(pract[0] == 'Д' && pract[1] == 'а')
				{
					std::cout << "Оценка за практику: ";
					std::cin >> PracticeWork;
				}
				std::cout << "Сданы ли все зачёты ";
				std::cout << "(Да или Нет)? ";
				std::cin >> alltest;
				if(alltest[0] == 'Д' && alltest[1] == 'а'
				   && pract[0] == 'Д' && pract[1] == 'а'
				   && kursovay[0] == 'Д' && 
				   kursovay[1] == 'а'&& firstEx > 3 &&
				   secondEx > 3 && thirdEx > 3 && FourEx > 3
				   && CourseWork > 3 && PracticeWork > 3 )
				{
					if((firstEx + secondEx + thirdEx + FourEx +
					CourseWork + PracticeWork) == 30)
					{


					}

					else if(24 < (firstEx + secondEx +
						thirdEx + FourEx + CourseWork
						+ PracticeWork) < 30)
					{


					}

					else if((firstEx + secondEx + thirdEx
					+ FourEx + CourseWork + PracticeWork) == 24)
					{


					}


				}
				else if((alltest[0] != 'Д' && alltest[1] != 'а')
					   || (pract[0] != 'Д' && pract[1] != 'а')
					   || (kursovay[0] != 'Д' 
					   && kursovay[1] != 'а') || firstEx < 4 ||
					   secondEx < 4 || thirdEx < 4 || FourEx < 4
					   || CourseWork < 4 || PracticeWork < 4)
				{
					NewElement->SumStipend = 0 ;
					NewElement->stipend = 0;
					std::cout<<"Есть ли социальная стипендия ";
					std::cout<< "(Да или Нет)?";
					std::cin >> SocialHelp;
					if(SocialHelp[0] == 'Д' &&
					   SocialHelp[1] == 'а')
					{
						NewElement->stipend += 3150;
						NewElement->stipend *=0.965;
						NewElement->SumStipend +=
						NewElement->stipend * 5;
					}
					std::cout << "Стипендия в месяц "
					" по результатам сессии: ";
					std::cout
					<< NewElement->stipend << std::endl;
					std::cout << "Стипендия за весь семестр"
					" по результатам сессии: ";
					std::cout
					<< NewElement->SumStipend<< std::endl;
				}



			}	
			break;


			case PRINT_ALL_STUDENT:
			{
				StudentBaseDate* buffer = head->next;  
				while (buffer->next != NULL)
				{
					std::cout << std::endl;
					std::cout << "id - " << buffer->id 
					<< std::endl;
					std::cout << "Группа: " << buffer->group 
					<< std::endl;
					std::cout << "Фамилия и имя студента: "
					<< buffer->surname 
					<< ' '<<buffer->name << std::endl;
					std::cout << "Номер зачётной книжки: " 
					<< buffer->CreditCard << std::endl;
					std::cout << "Стипендия в месяц: "
					<< buffer->stipend<<std::endl;
					std::cout << "Стипендия за семестр: "
					<< buffer->SumStipend<<std::endl;

					buffer = buffer->next;
				}
				std::cout << std::endl;
				std::cout << "id - " << buffer->id 
				<< std::endl;
				std::cout << "Группа: " << buffer->group 
				<< std::endl;
				std::cout << "Фамилия и имя студента: "
				<< buffer->surname 
				<< ' '<<buffer->name 
				<< std::endl;
				std::cout << "Номер зачётной книжки: " 
				<< buffer->CreditCard 
				<< std::endl;
				std::cout << "Стипендия в месяц: "
				<< buffer->stipend
				<<std::endl;
				std::cout << "Стипендия за семестр: "
				<< buffer->SumStipend
				<<std::endl;
			}
			break;

		}
	}while(true);
	system("pause");
}

void ReadFromFile(StudentBaseDate* head)
{
    StudentBaseDate* buffer;

    std::ifstream file;
    file.open("StudentBaseDate.txt"); 
    if (file.is_open())
    {
        buffer = head;
        while(!file.eof())
        {
			StudentBaseDate* NewElement = new StudentBaseDate; 
            file >> NewElement->group;
            file >> NewElement->surname;
			file >> NewElement->name;
			file >> NewElement->CreditCard;
			file >> NewElement->stipend;
			file >> NewElement->SumStipend;
            NewElement->id = buffer->id + 1;
			NewElement->next = NULL;
            buffer->next = NewElement;
            buffer = NewElement; 
        }
    }
    else
        return;
    file.close();
}

void WriteIntoFile(StudentBaseDate* head)
{
	
    std::ofstream file;
    file.open("StudentBaseDate.txt"); 
    if (file.is_open())
    {
		StudentBaseDate* buffer = head->next; 
        while (buffer->next != NULL)
        {
			file << buffer->group << ' ' <<
			buffer->surname << ' ' << buffer->name
							<< ' ' << buffer->CreditCard 
							<< ' ' << buffer->stipend << ' ' 
							<< buffer->SumStipend << '\n';
            buffer = buffer->next; 
        }
        file << buffer->group << ' ' << buffer->surname<<
			' ' << buffer->name<< ' ' << buffer->CreditCard<<
			' ' << buffer->stipend << ' ' << buffer->SumStipend;
    }
    else
        return;
    file.close();
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