#ifndef __VISIT_H
#define __VISIT_H

// Todo: fix that class

class Visit
{
private:

    char * name;
    char * purpose;
    int arrivalYear, arrivalMonth, arrivalDay;

public:

    Visit(char * name, char * magazine, int releaseYear, int releaseMonth, int releaseDay);

    // Getters
    char * getName();
    char * getMagazineName();
    char * getReleaseDate();
};

#endif // __VISIT_H