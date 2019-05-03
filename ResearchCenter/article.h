#ifndef __ARTICLE_H
#define __ARTICLE_H

#include "../Shared/date.h"
#include <iostream>

using namespace std;

class Article
{
private:
    char * name;
    char * magazine;
    Date releaseDate;

public:
    Article(char * name, char * magazine, Date &releaseDate);

    // Getters
    char * getName();
    char * getMagazineName();
    Date getReleaseDate();
	friend ostream& operator<<(ostream& os, const Article& obj);
};

#endif // __ARTICLE_H