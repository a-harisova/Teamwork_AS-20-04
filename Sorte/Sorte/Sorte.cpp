// Sorte.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector <int> CreateMassive(int n)
{
	vector <int> mas;
	mas.reserve(n);
	for (int i = 0; i < n - 1; i++)
	{
		if (i % 2 == 0)
			mas.push_back(i + 2);
		else
			mas.push_back(i);
	}

	return mas;
}

int main()
{
	vector <int> mas/*, result_of_sort*/;
	//mas = CreateMassive(100);
	/////*for (int i = 0; i < 100; i++)
	////	cout << mas[i] << " ";*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
