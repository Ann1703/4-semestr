#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <clocale>

using namespace std;


struct point {
    int x, y;           
    string label;       
    string description;


    point(int x = 0, int y = 0, const string& label = "", const string& desc = "")
        : x(x), y(y), label(label), description(desc) {}
};

// Перегрузка оператора сложения для point
point operator+(const point& a, const point& b) {
    return point(a.x + b.x,
        a.y + b.y,
        a.label + b.label,
        a.description + b.description);
}

// Перегрузка оператора вывода для записи в файл
ostream& operator<<(ostream& os, const point& p) {
    os << p.x << " " << p.y << " " << p.label << " " << p.description;
    return os;
}

// Перегрузка оператора ввода для чтения из файла
istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y >> p.label >> p.description;
    return is;
}

void print_file_content(const string& filename) {
    ifstream file(filename);
    string line;
    cout << "\nСодержимое файла " << filename << ":\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Функция для генерации тестовых файлов
void generate_test_files() {
    ofstream f1("name1");
    ofstream f2("name2");

   
    f1 << "1 2 ТочкаА Описание1\n";
    f1 << "3 4 ТочкаБ Описание2\n";
    f1 << "5 6 ТочкаВ Описание3\n";

    f2 << "10 20 Метка1 ОписаниеА\n";
    f2 << "30 40 Метка2 ОписаниеБ\n";
    f2 << "50 60 Метка3 ОписаниеВ\n";

    f1.close();
    f2.close();
}

int main() {
    
    setlocale(LC_ALL, "Russian");

    
    ifstream test1("name1"), test2("name2");
    if (!test1 || !test2) {
        cout << "Тестовые файлы не найдены. Создаю новые..." << endl;
        generate_test_files();
        cout << "Тестовые файлы успешно созданы." << endl;
    }
    test1.close(); test2.close();

    
    cout << "\nИСХОДНЫЕ ДАННЫЕ:";
    print_file_content("name1");
    print_file_content("name2");

    vector<point> V1, V2;
    point p;

    
    cout << "\nЧтение данных из файлов..." << endl;
    ifstream fin1("name1");
    while (fin1 >> p) {
        V1.push_back(p);
    }
    fin1.close();

    ifstream fin2("name2");
    while (fin2 >> p) {
        V2.push_back(p);
    }
    fin2.close();

    
    if (V1.size() != V2.size()) {
        cerr << "Ошибка: файлы содержат разное количество элементов!" << endl;
        return 1;
    }

   
    cout << "\nВыполняю операцию сложения..." << endl;
    transform(V1.begin(), V1.end(), V2.begin(), V1.begin(), plus<point>());

    
    cout << "Записываю результат в файл name1..." << endl;
    ofstream fout("name1");
    for (const auto& pt : V1) {
        fout << pt << endl;
    }
    fout.close();

    cout << "\nРЕЗУЛЬТАТ ОБРАБОТКИ:";
    print_file_content("name1");

    cout << "\nОперация успешно завершена." << endl;
    cout << "Нажмите Enter для выхода...";
    cin.get();

    return 0;
}