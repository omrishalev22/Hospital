#ifndef __ARTICLE_H
#define __ARTICLE_H

#include "../date.h"

class Article
{
private:

    char * name;
    char * magazine;
    Date releaseDate;

public:
    Article(char * name, char * magazine, Date releaseDate);

    // Getters
    char * getName();
    char * getMagazineName();
    Date getReleaseDate();
};

#endif // __ARTICLE_H