#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "article.h"

class Researcher
{
private:

    char * name;
    int id;
    Article ** articles;
    int indexArticles;
    int sizeArticles;

public:
    Researcher(char * name, int id);

    // Getters
    char* getName();
    int getId();
    Article ** getArticles();
    Article* getNewArticle();
    void show();

    // Setters
    bool addNewArticle(Article* article);
    ~Researcher();
};

#endif // __RESEARCHER_H