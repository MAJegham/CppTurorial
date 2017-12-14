#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video
{
private:
    int chaptersNumber;
    int* chaptersDurations;

public:
    Film();
    Film(std::string name, std::string pathname,
          int duration, int chaptersNumber, int* chaptersDurations);

    Film(std::string name, std::string pathname);


    void setChaptersDurations(const int* chaptersDurations,const int chaptersNumber);
    int * getChaptersDurations() const;
    int getChaptersNumber() const;

    void describe(std::ostream& stream) const override;

    virtual ~Film();

};

#endif // FILM_H
