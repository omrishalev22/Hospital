#include "researcher.h"

Researcher::Researcher(char *name, int id) {
    this->name = new char[strlen(name) + 1];
    this->name = strcpy(this->name, name);
    this->id = id;
}

char* Researcher::getName() {
    return this->name;
}

int Researcher::getId() {
    return this->id;
}

Article ** Researcher::getArticles() {
    return this->articles;
}

bool Researcher::addArticle(Article *article) {
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
}