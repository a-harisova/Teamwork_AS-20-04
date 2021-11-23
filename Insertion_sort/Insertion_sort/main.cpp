//
//  main.cpp
//  Insertion_sort
//
//  Created by Vlada Vlada on 23.11.2021.
//

#include <iostream>

using namespace std;

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T x;
    while ((std::cin >> x).fail() || x < min || x > max)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Enter number (" << min << "-" << max <<") again:";
    }
    return x;
    
}

int i, j, key = 0, temp = 0;
void InsertionSort(int *mas, int n) //сортировка вставками
{
    for (i = 0; i < n - 1; i++)
    {
        key = i + 1; // наш указатель переводим на второй элемент (индексация массива начинается с 0)
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
    cout << endl << "Отсортированный массив массив: ";
    for (i = 0; i < n; i++) // вывод массива
        cout << mas[i] << " ";
}


int main()
{
    setlocale(LC_ALL, "Rus");
        
    cout << "Количество элементов в массиве: " << "";
    int n = GetCorrectNumber(1, 100);
        int *mas = new int[n];
        for (i = 0; i < n; i++) //ввод исходного массива
        {
            cout << i + 1 << " " << "элемент:" << " ";
            cin >> mas[i];
        }
        InsertionSort(mas, n); //вызов функции
        cout << endl;
   
    return 0;
}
