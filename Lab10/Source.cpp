#include<iostream>

//�������:
//1.����������, ������� ��� � ������ ����������� �������� �����.
//10.��������, ����� ��, ��� ������ �����, �� �������� �����������, ����� ������ �����.
//19.���� ��� �����.����� ������ �� ������� ����, ������� ����������� � ����� ������ ������ ���� ���.

int askUserNumberTask()
{
	int choise;
	do {
		printf("������� ����� ������� (1, 10, 19):\n�����:"); scanf_s("%d", &choise);
	} while (choise != 1 && choise != 10 && choise != 19);
	return choise;
}

char* choiseLetter()
{
	char let[1];
	printf("������� �����:\n");
	scanf_s("%c", &let[0]);
	return let;
}

int main()
{
	system("chcp 1251"); system("cls");

	#pragma region 1 �������
	char str[256];
	printf("������� ������:\n"); gets_s(str);
	char *let = choiseLetter();

	int counter = 0;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == *let)
			counter++;
	printf("����� '%c' ����������� %d ���(�).", *let, counter);
	#pragma endregion

	#pragma region 10 �������
	//char str[256];
	//printf("������� �����:\n"); gets_s(str);

	//char mas[50];
	//for (int i = 0; str[i] != '\0'; i++)
	//{
	//	if (str[i] == ' ')
	//	{
	//		mas[i] = str[i];
	//		int len = strlen(mas);
	//		for (int j = i; j <len/2; j++)
	//		{
	//			if (len % 2 == 0)
	//			{
	//				if (mas[j] != mas[len - j - 1])// ���������
	//					printf("��");
	//			}
	//			else
	//				printf("���");
	//		}
	//	}
	//}
	#pragma endregion

	#pragma region 19 �������
	char wrd1[17], wrd2[17], c[17];

	printf("������� ������ �����: ");gets_s(wrd1);
	printf("������� ������ �����: ");gets_s(wrd2);

	for (int i = 0; wrd1[i] != '\0'; i++)
	{
		int counter = 0;
		for (int j = 0; wrd2[j] != '\0'; j++)
			if (wrd1[i] == wrd2[j])
			{
				counter++;
				c[i] = wrd1[i];
			}
		if (counter == 1)
			printf("%c\n", c[i]);
	}
	#pragma endregion

	return 0;
}