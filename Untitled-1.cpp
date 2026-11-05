#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h> // Для настройки кодировки

using namespace std;

// Функция быстрой сортировки (QuickSort)
void quickSort(vector<string>& arr, int left, int right) {
    int i = left, j = right;
    string pivot = arr[(left + right) / 2];

    // Разделение массива
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивная сортировка частей
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main() {
    // Настройка кодировки для русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== ПРОГРАММА СОРТИРОВКИ (ДОЧЕРНИЙ ПРОЦЕСС) ===" << endl;
    
    int n;
    cout << "Введите количество строк: ";
    cin >> n;
    cin.ignore(); // Убираем символ Enter из буфера

    vector<string> arr(n);
    cout << "Введите " << n << " строк:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Строка " << i + 1 << ": ";
        getline(cin, arr[i]);
    }

    cout << "\nВыполняется быстрая сортировка..." << endl;
    quickSort(arr, 0, n - 1);

    cout << "\n--- ОТСОРТИРОВАННЫЙ МАССИВ ---" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". " << arr[i] << endl;
    }

    cout << "\nНажмите Enter, чтобы завершить работу...";
    cin.get();
    return 0;


