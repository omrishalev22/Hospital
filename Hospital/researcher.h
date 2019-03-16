#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "article.h"

class Researcher
{
private:

    char * name;
    int id;
    Article articles[20]; // TODO dynamic

public:

    Researcher(char * name, int id);

    // Getters
    char* getName();
    int getId();
    Article[] getArticles();

    // Setters
    bool addArticle(Article article);
};

#endif // __RESEARCHER_H