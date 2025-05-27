#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Point {
private:
    int x, y;
    string s;

public:
   Point() : x(0), y(0), s("") {}

    // Методы доступа
    int getX() const { return x; }
    int getY() const { return y; }
    string getS() const { return s; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setS(const string& s) { this->s = s; }

    // Оператор ввода
    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y >> p.s;
        return is;
    }

    // Оператор вывода
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << p.x << " " << p.y << " " << p.s;
        return os;
    }

    // Оператор сложения
    Point operator+(const Point& other) const {
        Point result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        result.s = this->s + other.s;
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    // Имена файлов
    const string name1 = "name1.txt";
    const string name2 = "name2.txt";

    // Чтение данных из файлов в векторы V1 и V2
    vector<Point> V1, V2;
    Point p;

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
    transform(V1.begin(), V1.end(), V2.begin(), V1.begin(), plus<Point>());

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