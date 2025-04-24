#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    
    vector<int> V = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

   
    multiset<int> ms(V.begin(), V.end()); // Вспомогательное мультимножество для сортировки и подсчёта

   
    auto it = ms.begin(); // Итератор для прохода по мультимножеству

    while (it != ms.end()) {
       
        auto upper = ms.upper_bound(*it); // Находим первый элемент, который больше текущего

       
        int count = distance(it, upper); // Вычисляем количество повторений текущего элемента

        
        cout << *it << ":" << count << " ";// Выводим элемент и количество его повторений

       
        it = upper; // Перемещаем итератор на следующий уникальный элемент
    }

    cout << endl;
    return 0;
}