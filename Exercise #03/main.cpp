// Brief: Exercise #03 https://ibb.co/pb0MvhG
// Author: Marius Vaišvila (marius.vaisvila@mif.stud.vu.lt)
// Date: 2021
// Bugs: no known bugs
// Note: to build type "make 3" in terminal

#include <iostream>
#include "ProgrammingLanguage.h"

using std::cout;

int main()
{
    // Stack memory
    PL::ProgrammingLanguage lang1;

    // default values
    cout << lang1.toString() << '\n';

    lang1.set_name("C++");
    lang1.add_author("Bjarne Stroustrup");
    lang1.set_release_year(1985);
    lang1.set_version("C++20");
    lang1.set_type(_3GL);

    cout << lang1.toString() << '\n';

    // Stack memory
    PL::ProgrammingLanguage lang2("C", "Dennis Ritchie", 1972, "C17", _3GL);

    cout << lang2.toString() << '\n';

    // Stack memory
    PL::ProgrammingLanguage lang_arr[5];

    for (int i = 0; i < 5; ++i)
    {
        cout << lang_arr[i].toString() << '\n';
    }

    // Heap memory
    PL::ProgrammingLanguage *lang3 = new PL::ProgrammingLanguage();

    cout << lang3->toString() << '\n';

    lang3->set_name("Python");
    lang3->add_author("Guido van Rossum");
    lang3->set_release_year(1991);
    lang3->set_version("3.9.2");
    lang3->set_type(_4GL);

    cout << lang3->toString() << '\n';

    delete lang3;

    // Heap memory
    PL::ProgrammingLanguage *lang4 = new PL::ProgrammingLanguage("JavaScript",
                                                        "Brendan Eich",
                                                        1995,
                                                        "ECMAScript 2020",
                                                        _3GL);

    cout << lang4->toString() << '\n';

    delete lang4;

    // Heap memory
    PL::ProgrammingLanguage *lang_arr2 = new PL::ProgrammingLanguage[5];

    for (int i = 0; i < 5; ++i)
    {
        cout << (lang_arr2 + i)->toString() << '\n';
    }

    delete[] lang_arr2;
}