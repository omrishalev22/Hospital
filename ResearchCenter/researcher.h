#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "article.h"
#include "../person.h"
#include "../Staff/Type/doctor.h"

class Researcher : public Person
{
private:
    Article ** articles;
    int indexArticles;
    int sizeArticles;
	bool isDoctor;

public:
    Researcher(int id, char * name);
	Researcher(const Doctor& doctor);
    Article ** getArticles();
    void show();
	bool operator>(const Researcher& other);
	bool getIsDoctor();

    // Setters
    bool addNewArticle(Article* article);
    ~Researcher();
};

#endif // __RESEARCHER_H