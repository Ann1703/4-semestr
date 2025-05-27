#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct point {
    int x, y;
    string s;
};

// Оператор ввода для point
istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y >> p.s;
    return is;
}

// Оператор вывода для point
ostream& operator<<(ostream& os, const point& p) {
    os << p.x << " " << p.y << " " << p.s;
    return os;
}

// Оператор сложения для point
point operator+(const point& a, const point& b) {
    point result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.s = a.s + b.s;
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Имена файлов
    const string name1 = "name1.txt";
    const string name2 = "name2.txt";

    // Чтение данных из файлов в векторы V1 и V2
    vector<point> V1, V2;
    point p;

    // Открытие первого файла
    ifstream file1(name1);
    if (!file1.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << name1 << endl;
        return 1;
    }

    while (file1 >> p) {
        V1.push_back(p);
    }
    file1.close();

    // Открытие второго файла
    ifstream file2(name2);
    if (!file2.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << name2 << endl;
        return 1;
    }

    while (file2 >> p) {
        V2.push_back(p);
    }
    file2.close();

    // Проверка, что файлы содержат одинаковое количество элементов
    if (V1.size() != V2.size()) {
        cerr << "Ошибка: файлы содержат разное количество элементов!" << endl;
        return 1;
    }

    // Сложение элементов V1 и V2 с использованием transform
    transform(V1.begin(), V1.end(), V2.begin(), V1.begin(), plus<point>());

    // Запись результата обратно в name1
    ofstream outFile(name1);
    if (!outFile.is_open()) {
        cerr << "Ошибка: не удалось открыть файл " << name1 << " для записи" << endl;
        return 1;
    }

    for (const auto& pt : V1) {
        outFile << pt << endl;
    }
    outFile.close();

    cout << "Операция выполнена успешно. Результат записан в " << name1 << endl;
    return 0;
}