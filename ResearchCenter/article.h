#ifndef __ARTICLE_H
#define __ARTICLE_H

#include "../entity.h"
#include "../Shared/date.h"
#include <iostream>
#include <string>
using namespace std;

class Article : public Entity
{
private:
    std::string name;
    std::string magazine;
    Date releaseDate;

public:
    Article(const string& name, const string& magazine, Date &releaseDate);
	Article(ifstream& inFile);
	void save(ofstream& outFile) const;

    // Getters
    const string& getName();
    const string& getMagazineName();
    Date getReleaseDate();
	friend ostream& operator<<(ostream& os, const Article& obj);
};

#endif // __ARTICLE_H