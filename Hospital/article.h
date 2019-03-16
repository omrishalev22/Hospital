#ifndef __ARTICLE_H
#define __ARTICLE_H

class Article
{
private:

    char * name;
    char * magazine;
    int releaseYear, releaseMonth, releaseDay;

public:

    Article(char * name, char * magazine, int releaseYear, int releaseMonth, int releaseDay);

    // Getters
    char * getName();
    char * getMagazineName();
    char * getReleaseDate();
};

#endif // __ARTICLE_H