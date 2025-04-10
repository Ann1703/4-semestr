#include <iostream>
#include <deque>
#include <list>
#include <iterator> // для std::prev

int main() {
    // Инициализация дека D (пример)
    std::deque<int> D = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // Инициализация списка L (пример)
    std::list<int> L = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    // Проверка, что в каждом контейнере не менее 5 элементов
    if (D.size() < 5 || L.size() < 5) {
        std::cerr << "Ошибка: в контейнерах должно быть не менее 5 элементов!" << std::endl;
        return 1;
    }

    // Находим итератор на пятый с конца элемент списка L
    auto fifth_from_end = std::prev(L.end(), 5);

    // Создаем временный контейнер с последними 5 элементами дека D в обратном порядке
    std::deque<int> reversed_last_five(D.rbegin(), D.rbegin() + 5);

    // Вставляем элементы перед пятым с конца элементом списка L
    L.insert(fifth_from_end, reversed_last_five.begin(), reversed_last_five.end());

    // Выводим результат для проверки
    std::cout << "Result:" << std::endl;
    for (int num : L) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}