#ifndef __RESEARCH_H
#define __RESEARCH_H

#include "researcher.h"

class ResearchCenter
{
private:

    Researcher** researchers;
    int indexResearchers = 0;
    int sizeResearchers = 0;

public:

    ResearchCenter();

    // Getters
    Researcher** getResearchers();
    Researcher* getNewResearcher();

    // Setters
    bool addNewResearcher(Researcher* r);
};

#endif // __RESEARCH_H