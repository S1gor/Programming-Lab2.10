#include<iostream>

//ЗАДАНИЕ:
//1.Определить, сколько раз в тексте встречается заданная буква.
//10.Выяснить, верно ли, что каждое слово, не являющее палиндромом, имеет четную длину.
//19.Даны два слова.Найти только те символы слов, которые встречаются в обоих словах только один раз.

int askUserNumberTask()
{
	int choice;
	do {
		printf("Введите номер задания (1, 10, 19):\nВыбор:"); scanf_s("%d%*c", &choice);
	} while (choice != 1 && choice != 10 && choice != 19);
	return choice;
}

char choiceLetter()
{
	char let;
	printf("Введите букву:\n");
	scanf_s("%c", &let);
	return let;
}
void letterMet(char* str, char let)
{
	int counter = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == let)
			counter++;
	printf("Буква '%c' встретилась %d раз(а).", let, counter);
}

void recurringSymbol(char* wrd1, char* wrd2, char* c)
{
	for (int i = 0; wrd1[i] != '\0'; i++)
	{
		int counter = 0;
		for (int j = 0; wrd1[j] != '\0'; j++)
			if (wrd1[i] == wrd1[j])
				counter++;
		if (counter == 1)
		{
			int counter2 = 0;
			for (int k = 0; wrd2[k] != '\0'; k++)
				if (wrd1[i] == wrd2[k])
				{
					counter2++;
					c[i] = wrd1[i];
				}
			if (counter2 == 1)
				printf("%c\n", c[i]);
		}
	}
}

bool chekPalindrom(char* mas)
{
	int len = strlen(mas);
	for (int i = 0; i < len / 2; i++)
		if (mas[i] != mas[len - i - 1])
			return false;
	return true;
}

int main()
{
	system("chcp 1251"); system("cls");

	switch (askUserNumberTask())
	{
	case 1:
	{
		char str[256];
		printf("Введите строку:\n"); gets_s(str);
		char let = choiceLetter();

		letterMet(str, let);
		break;
	}
	case 10:
	{
		char str[256];
		printf("Введите строку:\n"); gets_s(str);

		char mas[20];

		for (int i = 0; i < strlen(str); i++)
		{
			mas[i] = str[i];
				
		}
		if (chekPalindrom(mas))
			printf("Палиндром\n");
		else
			printf("Не палиндром\n");
		break;
	}
	case 19:
	{
		char wrd1[17], wrd2[17], c[17];
		printf("Введите первое слово: "); gets_s(wrd1);
		printf("Введите второе слово: "); gets_s(wrd2);

		recurringSymbol(wrd1, wrd2, c);
		break;
	}
	}

	return 0;
}