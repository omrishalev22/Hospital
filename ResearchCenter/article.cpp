#include <cstring>
#include "article.h"

Article::Article(char *name, char *magazine, Date &releaseDate)
{
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);

    this->magazine = new char[strlen(magazine) + 1];
    this->magazine = strcpy(this->magazine, magazine);

    this->releaseDate = Date(releaseDate);
}

char* Article::getName()
{
    return this->name;
}

char* Article::getMagazineName()
{
    return this->magazine;
}

Date Article::getReleaseDate()
{
    return this->releaseDate;
}