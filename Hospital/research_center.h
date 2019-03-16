#ifndef __RESEARCH_H
#define __RESEARCH_H

#include "researcher.h"

class ResearchCenter
{
private:

    Researcher researchers[20]; // TODO dynamic

public:

    ResearchCenter();

    // Getters
    Researcher getResearchers();
    Researcher getResearcherByName(char * name);

    // Setters
    bool addResearcher(Researcher r);
};

#endif // __RESEARCH_H