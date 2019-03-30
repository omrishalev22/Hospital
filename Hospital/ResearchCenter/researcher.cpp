#include <cstring>
#include "researcher.h"
#include <iostream>
#include "../Shared/consts.h"

using namespace std;

Researcher::Researcher(char *name, int id)
{
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this->id = id;
    this->articles = new Article*[AMOUNT_OF_STARTED_ITEMS];
    this->indexArticles = 0;
    this->sizeArticles = AMOUNT_OF_STARTED_ITEMS;
}

char* Researcher::getName()
{
    return this->name;
}

int Researcher::getId()
{
    return this->id;
}

Article ** Researcher::getArticles()
{
    return this->articles;
}

void Researcher::show()
{
    cout << "[Researcher]" << endl;
    cout << "    Name: " << this->name << endl;
    cout << "    ID: " << this->id << endl;
    cout << "    Number of articles: " << this->indexArticles << endl;
}

bool Researcher::addNewArticle(Article *article,char * researcherName)
{
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
    cout << "Successfully added a new article by " << researcherName << " under magazine " <<
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
