#include <cstring>
#include "researcher.h"
#include <iostream>
#include "../Shared/consts.h"

using namespace std;

Researcher::Researcher(int id, char *name) : Person(id, name)
{
    this->articles = new Article*[AMOUNT_OF_STARTED_ITEMS];
    this->indexArticles = 0;
    this->sizeArticles = AMOUNT_OF_STARTED_ITEMS;
}

Article ** Researcher::getArticles()
{
    return this->articles;
}

void Researcher::show()
{
    cout << "[Researcher]" << endl;
	this->Person::show();
    cout << "    Number of articles: " << this->indexArticles << endl;
}

bool Researcher::addNewArticle(Article *article)
{
    if (article == nullptr)
        return false;

    if (this->indexArticles >= this->sizeArticles)
    {
        Article** tempArr = new Article*[this->sizeArticles * 2];
        for (int i = 0; i < this->indexArticles; i++)
            tempArr[i] = this->articles[i];

        delete [] this->articles;
        this->articles = tempArr;
        this->sizeArticles *= 2;
    }
    this->articles[this->indexArticles++] = article;
    cout << "Successfully added a new article by " << this->getName() << " under magazine " <<
    article->getMagazineName() << endl;
    return true;
}

Researcher::~Researcher()
{
    if (this->articles != nullptr) {
        for (int i = 0; i < this->indexArticles; i++)
            delete this->articles[i];
        delete[] this->articles;
    }
}
