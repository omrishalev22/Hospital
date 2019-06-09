#include <cstring>
#include "article.h"

Article::Article(const string& name, const string& magazine, Date &releaseDate)
{
	this->name = name;
	this->magazine = magazine;
    this->releaseDate = Date(releaseDate);
}

Article::Article(ifstream& inFile)
{
	inFile.read((char *)&name, sizeof(name));
	inFile.read((char *)&magazine, sizeof(magazine));
	releaseDate = Date::loadDate(inFile);
}

void Article::save(ofstream& outFile) const
{
	outFile.write(name.c_str(), sizeof(char) * name.size());
	outFile.write(magazine.c_str(), sizeof(char) * magazine.size());
	releaseDate.save(outFile);
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