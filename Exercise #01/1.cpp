/* 
 * This program finds names in word
 * list and prints them sorted.
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

void print_info();
void get_names(std::vector<std::string> &names);
bool is_name(std::string buff);
void print_results(std::vector<std::string> &names);

int main()
{
    std::vector<std::string> names;
    
    print_info();
    get_names(names);
    sort(names.begin(), names.end());
    print_results(names);

    return 0;
}

void print_info()
{
    std::cout << "This program finds names in word ";
    std::cout << "list and prints them sorted." << std::endl;
    std::cout << "If you want to stop entering words enter \"-\"." << std::endl;
    std::cout << "Enter words:" << std::endl; 
}

void get_names(std::vector<std::string> &names)
{
    while(1)
    {
        std::string buff;
        std::cin >> buff;

        if (buff == "-")
            break;

        if (is_name(buff))
            names.push_back(buff);
    }
}

bool is_name(std::string buff)
{
    if (!isupper(buff[0]))
        return 0;
            
    for (int i = 1; i < buff.length(); ++i)
        if (!islower(buff[i]))
            return 0;
    
    return 1;
}

void print_results(std::vector<std::string> &names)
{
    std::cout << std::endl;
    if (names.size() > 0)
        std::cout << "Sorted names:" << std::endl;
    else
        std::cout << "No names entered." << std::endl;

    for (int i = 0; i < names.size(); ++i)
    {
        std::cout << names[i] << " ";

        if ( ((i % 9 == 0) && (i)) || (i == names.size() - 1) )
            std::cout << std::endl;
    }
}