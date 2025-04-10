#include <iostream>
#include <iterator>   
#include <algorithm>   
#include <cctype>      

int main() {
    // Объявляем входной итератор, читающий символы из стандартного ввода
    std::istream_iterator<char> input_it(std::cin);
    // Объявляем конечный итератор для входного потока
    std::istream_iterator<char> end_it;

    // Объявляем выходной итератор, записывающий символы в стандартный вывод
    std::ostream_iterator<char> output_it(std::cout);

    // Используем алгоритм replace_copy_if для копирования символов с заменой цифр на '_'
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