#include <iostream>
#include <deque>
#include <list>
#include <iterator> // ��� std::prev

int main() {
    // ������������� ���� D (������)
    std::deque<int> D = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    // ������������� ������ L (������)
    std::list<int> L = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

    // ��������, ��� � ������ ���������� �� ����� 5 ���������
    if (D.size() < 5 || L.size() < 5) {
        std::cerr << "������: � ����������� ������ ���� �� ����� 5 ���������!" << std::endl;
        return 1;
    }

    // ������� �������� �� ����� � ����� ������� ������ L
    auto fifth_from_end = std::prev(L.end(), 5);

    // ������� ��������� ��������� � ���������� 5 ���������� ���� D � �������� �������
    std::deque<int> reversed_last_five(D.rbegin(), D.rbegin() + 5);

    // ��������� �������� ����� ����� � ����� ��������� ������ L
    L.insert(fifth_from_end, reversed_last_five.begin(), reversed_last_five.end());

    // ������� ��������� ��� ��������
    std::cout << "Result:" << std::endl;
    for (int num : L) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}