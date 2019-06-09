#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "article.h"
#include "../person.h"
#include "../Staff/Type/doctor.h"
#include "../Shared/Array.h"
#include <string>
#include <ostream>

class Researcher : public Person
{
private:
	Array<Article*> articles;
	bool isDoctor;

public:
    Researcher(int id, const string& name);
	Researcher(const Doctor& doctor);
	Researcher(ifstream& inFile);
	void save(ofstream& outFile) const;

	Array<Article*> getArticles();
    void show();
	bool operator>(Researcher& other);
	bool getIsDoctor();

    // Setters
    bool addNewArticle(Article* article);
};

#endif // __RESEARCHER_H