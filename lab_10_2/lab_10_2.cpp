#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int checkTXT();


int main()
{
	cout << "Words with same first and last letter: " << checkTXT() << endl;
}


int checkTXT() 
{ 
	ifstream fin("t.txt"); // відкрили файл для зчитування
	char s[100]; // прочитаний рядок
	char* w; // виокремлене з рядка слово
	int k = 0; // кількість слів
	while (fin.getline(s, sizeof(s))) // поки можна прочитати рядок
	{
		w = strtok(s, " .,:;!?-'"); // початок циклу виокремлення слів
		while (w != NULL) // поки можна виокремити слово
		{
			int d = strlen(w);
			if (w[0] == w[d-1])	{
				k++;
			}
			w = strtok(NULL, " .,:;!?-'"); // виокремлюємо наступне слово
		}
	}
	fin.close();
	return k;
}
