#include <cstring>
#include "researcher.h"
#include <iostream>
#include "../Shared/consts.h"

using namespace std;

Researcher::Researcher(int id, char *name) : Person(id, name)
{
	this->isDoctor = false;
}

Researcher::Researcher(const Doctor & doctor): Person(doctor)
{
	this->isDoctor = true;
}

Array<Article*> Researcher::getArticles()
{
    return this->articles;
}

void Researcher::show()
{
	this->Person::show();
    cout << "    Number of articles: " << this->articles.getSize() << endl;
}

bool Researcher::addNewArticle(Article *article)
{
    if (article == nullptr)
        return false;

    this->articles += article;
    cout << "Successfully added a new article by " << this->getName() << " under magazine " <<
    article->getMagazineName() << endl;
    return true;
}

bool Researcher::operator>( Researcher& other)
{
	return this->articles.getSize() > other.articles.getSize();
}

bool Researcher::getIsDoctor()
{
	return this->isDoctor;
}
