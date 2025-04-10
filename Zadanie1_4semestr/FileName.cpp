#include <iostream>
#include <iterator>   
#include <algorithm>   
#include <cctype>      

int main() {
    // ќбъ€вл€ем входной итератор, читающий символы из стандартного ввода
    std::istream_iterator<char> input_it(std::cin);
    // ќбъ€вл€ем конечный итератор дл€ входного потока
    std::istream_iterator<char> end_it;

    // ќбъ€вл€ем выходной итератор, записывающий символы в стандартный вывод
    std::ostream_iterator<char> output_it(std::cout);

    // »спользуем алгоритм replace_copy_if дл€ копировани€ символов с заменой цифр на '_'
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