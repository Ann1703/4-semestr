#include <iostream>
#include <iterator>   
#include <algorithm>   
#include <cctype>      

int main() {
    // ��������� ������� ��������, �������� ������� �� ������������ �����
    std::istream_iterator<char> input_it(std::cin);
    // ��������� �������� �������� ��� �������� ������
    std::istream_iterator<char> end_it;

    // ��������� �������� ��������, ������������ ������� � ����������� �����
    std::ostream_iterator<char> output_it(std::cout);

    // ���������� �������� replace_copy_if ��� ����������� �������� � ������� ���� �� '_'
    std::replace_copy_if(
        input_it,      
        end_it,        
        output_it,     
        [](char c) {  
            return std::isdigit(c);
        },
        '_'            
    );

    return 0;
}