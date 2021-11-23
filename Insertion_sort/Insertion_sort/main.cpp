//
//  main.cpp
//  Insertion_sort
//
//  Created by Vlada Vlada on 23.11.2021.
//

#include <iostream>

using namespace std;


int i, j, key = 0, temp = 0;
void InsertionSort(int *mas, int n) //сортировка вставками
{
    for (i = 0; i < n - 1; i++)
    {
        key = i + 1; // наш указатель переводим на первый элемент, так как в цикле мы идём от 0
        temp = mas[key]; //temp - это тот элемент, который мы будем пробовать "вставлять"
        for (j = i + 1; j > 0; j--)
        {
            if (temp < mas[j - 1]) // если тот элемент, который мы хотим переставить меньше элемента, расположенного слева от него, то
            {
                mas[j] = mas[j - 1]; // меняем их местами
                key = j - 1; // указатель сдвигаем, и он выйдет в отрицательный диапозон, вследствие чего цикл прервётся
            }
 
        }
        mas[key] = temp;
    }
    cout << endl << "Отсортированный массив массив: ";
    for (i = 0; i < n; i++) // вывод массива
        cout << mas[i] << " ";
}


int main()
{
    setlocale(LC_ALL, "Rus");
        
    cout << "Количество элементов в массиве: " << "";
    int n;
        cin >> n;
        int *mas = new int[n];
        for (i = 0; i < n; i++) //ввод исходного массива
        {
            cout << i + 1 << " " << "элемент:" << " ";
            cin >> mas[i];
        }
        InsertionSort(mas, n); //вызов функции
        cout << endl;
        //system("pause");
   
    return 0;
}
