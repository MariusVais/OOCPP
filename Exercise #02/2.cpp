// Brief: Exercise #02 https://ibb.co/3dkS22g
// Author: Marius Vaišvila (marius.vaisvila@mif.stud.vu.lt)
// Date: 2021
// Bugs: no known bugs
// Note: there is no data validation

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>

#define DEFAULT_NAME "-"
#define DEFAULT_AUTHOR "-"
#define DEFAULT_YEAR 0
#define DEFAULT_VERSION "-"
#define DEFAULT_TYPE "-"

#define _1GL "First-generation programming language (1GL)"
#define _2GL "Second-generation programming language (2GL)"
#define _3GL "Third-generation programming language (3GL)"
#define _4GL "Fourth-generation programming language (4GL)"
#define _5GL "Fifth-generation programming language (5GL)"

using namespace std;

class ProgrammingLanguage
{
    private:
        string name;
        vector<string> authors;
        unsigned int release_year;
        string current_version;
        string type;
        int count_age();

    public:
        ProgrammingLanguage();
        ProgrammingLanguage(const string name, const string author, 
                            const unsigned int release_year, const string version,
                            const string type);
        ~ProgrammingLanguage();
        void set_name(const string name);
        void add_author(const string author);
        void remove_author(unsigned int i);
        void edit_author(unsigned int i, const string author);
        void set_release_year(const unsigned int release_year);
        void set_version(const string version);
        void set_type(const string type);
        int get_age();
        string toString();
};

ProgrammingLanguage::ProgrammingLanguage()
{
    set_name(DEFAULT_NAME);
    add_author(DEFAULT_AUTHOR);
    set_release_year(DEFAULT_YEAR);
    set_version(DEFAULT_VERSION);
    set_type(DEFAULT_TYPE);
}

ProgrammingLanguage::ProgrammingLanguage(const string name, const string author, 
                                         const unsigned int release_year, 
                                         const string version, const string type)
{
    set_name(name);
    add_author(author);
    set_release_year(release_year);
    set_version(version);
    set_type(type);
}

ProgrammingLanguage::~ProgrammingLanguage()
{
}

void ProgrammingLanguage::set_name(const string name)
{
    this->name = name;
}

void ProgrammingLanguage::add_author(const string author)
{
    if ((!authors.empty()) && (authors[0] == DEFAULT_AUTHOR))
    {
        remove_author(0);
    }
    authors.push_back(author);
}

void ProgrammingLanguage::remove_author(unsigned int i)
{
    authors.erase(authors.begin() + i);
}

void ProgrammingLanguage::edit_author(unsigned int i, const string author)
{
    authors[i] = author;
}

void ProgrammingLanguage::set_release_year(const unsigned int release_year)
{
    this->release_year = release_year;
}

void ProgrammingLanguage::set_version(const string version)
{
    this->current_version = version;
}

void ProgrammingLanguage::set_type(const string type)
{
    this->type = type;
}

int ProgrammingLanguage::get_age()
{
    return (this->name == DEFAULT_NAME) ? (0) : (count_age());
}

int ProgrammingLanguage::count_age()
{
    time_t wall_time = time(NULL);
    struct tm *local_time = localtime(&wall_time);
    unsigned int current_year = local_time->tm_year + 1900;
    return current_year - this->release_year; 
}

string ProgrammingLanguage::toString()
{
    stringstream ss;
    ss << "Name: " << this->name << ", authors: ";
    for (int i = 0; i < authors.size(); ++i)
    {
        ss << authors[i] << ", ";
    }
    ss << "first appeared in " << this->release_year << ", age: "
       << get_age() << ", current version: " << this->current_version
       << ", type: " << this->type << '.';
    return ss.str();
}

int main()
{
    // Stack memory
    ProgrammingLanguage lang1;

    // default values
    cout << lang1.toString() << endl;

    lang1.set_name("C++");
    lang1.add_author("Bjarne Stroustrup");
    lang1.set_release_year(1985);
    lang1.set_version("C++20");
    lang1.set_type(_3GL);

    cout << lang1.toString() << endl;

    // Stack memory
    ProgrammingLanguage lang2("C", "Dennis Ritchie", 1972, "C17", _3GL);

    cout << lang2.toString() << endl;

    // Stack memory
    ProgrammingLanguage lang_arr[5];

    for (int i = 0; i < 5; ++i)
    {
        cout << lang_arr[i].toString() << endl;
    }

    // Heap memory
    ProgrammingLanguage *lang3 = new ProgrammingLanguage();

    cout << lang3->toString() << endl;

    lang3->set_name("Python");
    lang3->add_author("Guido van Rossum");
    lang3->set_release_year(1991);
    lang3->set_version("3.9.2");
    lang3->set_type(_4GL);

    cout << lang3->toString() << endl;

    delete lang3;

    // Heap memory
    ProgrammingLanguage *lang4 = new ProgrammingLanguage("JavaScript",
                                                        "Brendan Eich",
                                                        1995,
                                                        "ECMAScript 2020",
                                                        _3GL);

    cout << lang4->toString() << endl;

    delete lang4;

    // Heap memory
    ProgrammingLanguage *lang_arr2 = new ProgrammingLanguage[5];

    for (int i = 0; i < 5; ++i)
    {
        cout << (lang_arr2 + i)->toString() << endl;
    }

    delete[] lang_arr2;

    return 0;
}
