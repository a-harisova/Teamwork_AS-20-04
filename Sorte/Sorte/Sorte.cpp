// Sorte.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <chrono>
#include <algorithm>

using namespace std;

int* CreateMassive(int n)
{
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			mas[i] = i + 2;
		else
			mas[i] = i;
	}

	return mas;
}

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration < double, std::ratio <1> >;

	std::chrono::time_point <clock_t> start;

public:
	Timer() : start(clock_t::now())
	{
	}

	void reset()
	{
		start = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast <second_t> (clock_t::now() - start).count();
	}
};

//Владислава Калюта
void InsertionSort(int* mas, int n) //сортировка вставками
{
	int i, j, key = 0, temp = 0;
	for (i = 0; i < n - 1; i++)
	{
		key = i; // наш указатель переводим на второй элемент (индексация массива начинается с 0) P.s. Изменила key = i + 1 на i, т.к. массив заполнялся со второго элемента (Адиля)
		temp = mas[key]; //temp - элемент, который мы будем "вставлять"
		for (j = i + 1; j > 0; j--)
		{
			if (temp < mas[j - 1]) // если тот элемент, который мы хотим переставить, меньше элемента, расположенного слева от него, то
			{
				mas[j] = mas[j - 1]; // элемент слева от temp сдвинули вправо
				key = j - 1; // указатель обнуляем, вследствие чего цикл прервётся
			}

		}
		mas[key] = temp; // temp сдвинули влево
	}
}

//Илья Лазарев
void ShellSort(int* mass, int n)
{
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2)
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mass[j - step])
					mass[j] = mass[j - step];
				else
					break;
			}
			mass[j] = tmp;
		}
}

//Софья Кузьмина
int GetMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

void CountingSort(int arr[], int size, int div)
{
	const int max = 10;
	int* output = new int[size];
	int count[max];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	// Calculate count of elements
	for (int i = 0; i < size; i++)
		count[(arr[i] / div) % 10]++;

	// Calculate cumulative count
	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	// Place the elements in sorted order
	for (int i = size - 1; i >= 0; i--) {
		output[count[(arr[i] / div) % 10] - 1] = arr[i];
		count[(arr[i] / div) % 10]--;
	}

	for (int i = 0; i < size; i++)
		arr[i] = output[i];
}
void RadixSort(int arr[], int size) {
	int m = GetMax(arr, size);
	for (int div = 1; m / div > 0; div *= 10)
	{
		CountingSort(arr, size, div);
	}
}

int main()
{
	Timer t;
	setlocale(LC_ALL, "Rus");
	set <int> number { 100, 10000, 200000 };
	for (auto n : number)
	{
		cout << "Размер вектора: " << n << endl;
		/*int* mas = CreateMassive(n);*/
		/*cout << "Сортируемый массив:" << endl;
		for (int i = 0; i < n - 1; i++)
			cout << mas[i] << " ";
		cout << endl;*/
		InsertionSort(CreateMassive(n), n);
		cout << "Сортировка вставками - затраченное время: " << t.elapsed() << endl;
		ShellSort(CreateMassive(n), n);
		cout << "Сортировка Шелла - затраченное время: " << t.elapsed() << endl;
		RadixSort(CreateMassive(n), n);
		cout << "Поразрядная сортировка - затраченное время: " << t.elapsed() << endl;
		/*cout << "Отсортированный массив: " << endl;*/
		/*for (int i = 0; i < n - 1; i++)
			cout << mas[i] << " ";
		cout << endl;*/
	}
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
