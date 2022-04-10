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

int strLen(char* str)
{
	int counter = 0;
	for (int i = 0; str[i] != '\0'; i++)
		counter++;
	return counter;
}

char choiceLetter()
{
	char let;
	printf("Введите букву:\n");
	scanf_s("%c", &let);
	return let;
}
char registrReplacement(char letter)
{
	if (letter >= 'А' && letter <= 'Я')
		return letter + ('а' - 'А');
	else
		return letter - ('а' - 'А');
}
void letterMet(char* str, char letter,char letter2)
{
	int counter = 0;
	int len = strLen(str) + 1;

	for (int i = 0; i < len; i++)
		if (str[i] == letter || str[i] == letter2)
			counter++;
	printf("Буква '%c(%c)' встретилась %d раз(а).", letter, letter2, counter);
}

bool chekPalindrom(char* mas)
{
	int len = strlen(mas);
	char let;
	for (int i = 0; i < len / 2; i++)
	{
		let = registrReplacement(mas[i]);
		if (mas[i] != mas[len - i - 1] && let != mas[len - i - 1])
			return false;
	}
	return true;
}
void findLenAndPalindrom(char* str)
{
	printf("\n");
	int len = strLen(str) + 1;
	char mas[20] = { 0 };

	int n = 0;
	bool flag = true;
	for (int i = 0; i < len; i++)
	{
		mas[n] = str[i];
		if (str[i] == ' ' || str[i] == '\0')
		{
			mas[n] = '\0';
			if (chekPalindrom(mas))
				printf("%s - Палиндром\n", mas);
			else
			{
				printf("%s(%d) - Не палиндром\n", mas, strLen(mas));
				if (strLen(mas) % 2 != 0)
				{
					flag = false;
					printf("Не каждое слово, не являющаяся палиндромом, имеет чётную длину.\n");
					break;
				}
			}
			for (int j = 0; j < n; j++)
				mas[j] = ' ';
			n = 0;
			continue;
		}
		n++;
	}
	if (flag)
		printf("Каждое слово, не являющаяся палиндромом, имеет чётную длину.\n");
}

void recurringSymbol(char* wrd1, char* wrd2, char* c)
{
	char wrd1_2;
	for (int i = 0; wrd1[i] != '\0'; i++)
	{
		wrd1_2 = registrReplacement(wrd1[i]);
		int counter = 0;
		for (int j = 0; wrd1[j] != '\0'; j++)
			if (wrd1[i] == wrd1[j] || wrd1_2 == wrd1[j])
				counter++;
		if (counter == 1)
		{
			int counter2 = 0;
			for (int k = 0; wrd2[k] != '\0'; k++)
				if (wrd1[i] == wrd2[k] || wrd1_2 == wrd2[k])
				{
					counter2++;
					c[i] = wrd1[i];
				}
			if (counter2 == 1)
				printf("%c\n", c[i]);
		}
	}
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
		char letter = choiceLetter();
		char letter2 = registrReplacement(letter);

		letterMet(str, letter, letter2);
		break;
	}
	case 10:
	{
		char str[256];
		printf("Введите строку:\n"); gets_s(str);

		findLenAndPalindrom(str);
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