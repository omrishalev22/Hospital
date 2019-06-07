#ifndef __ARTICLE_H
#define __ARTICLE_H

#include "../Shared/date.h"
#include <iostream>
#include <string>
using namespace std;

class Article
{
private:
    std::string name;
    std::string magazine;
    Date releaseDate;

public:
    Article(const string& name, const string& magazine, Date &releaseDate);

    // Getters
    const string& getName();
    const string& getMagazineName();
    Date getReleaseDate();
	friend ostream& operator<<(ostream& os, const Article& obj);
};

#endif // __ARTICLE_H