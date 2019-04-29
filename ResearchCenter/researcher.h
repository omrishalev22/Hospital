#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "article.h"
#include "../person.h"

class Researcher : public Person
{
private:
    Article ** articles;
    int indexArticles;
    int sizeArticles;

public:
    Researcher(int id, char * name);
    Article ** getArticles();
    void show();

    // Setters
    bool addNewArticle(Article* article);
    ~Researcher();
};

#endif // __RESEARCHER_H