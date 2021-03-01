#ifndef PROGRAMMINGLANGUAGE_H
#define PROGRAMMINGLANGUAGE_H

using std::string;
using std::vector;

namespace ProgrammingLanguage
{
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
}

#endif /* PROGRAMMINGLANGUAGE_H */