#include <string>
#include <sstream>
#include "ProgrammingLanguage.h"

using std::string;

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
    // Does nothing
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