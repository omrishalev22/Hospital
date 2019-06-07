#include <cstring>
#include "article.h"

Article::Article(const string& name, const string& magazine, Date &releaseDate)
{
	this->name = name;
	this->magazine = magazine;
    this->releaseDate = Date(releaseDate);
}

const string& Article::getName()
{
    return this->name;
}

const string& Article::getMagazineName()
{
    return this->magazine;
}

Date Article::getReleaseDate()
{
    return this->releaseDate;
}

ostream& operator<<(ostream& os, const Article& obj)
{
	os << "Article '" << obj.name << "' in Magazine '" << obj.magazine << "'";
	return os;
}