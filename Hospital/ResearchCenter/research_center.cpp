#include "research_center.h"

ResearchCenter::ResearchCenter() = default;

Researcher** ResearchCenter::getResearchers() {
    return this->researchers;
}

bool ResearchCenter::addNewResearcher(Researcher* newResearcher) {
    if (this->indexResearchers >= this->sizeResearchers)
    {
        Researcher** tempArr = new Researcher*[this->sizeResearchers * 2];
        for (int i = 0; i < this->indexResearchers; i++)
            tempArr[i] = this->researchers[i];

        delete [] this->researchers;
        this->researchers = tempArr;
        this->sizeResearchers *= 2;
    }
    this->researchers[this->indexResearchers++] = newResearcher;
}