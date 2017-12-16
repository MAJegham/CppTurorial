#ifndef MANAGER_H
#define MANAGER_H

#include "Multimedia.h"
#include "Groupe.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include <string>
#include <memory>
#include <map>

class Manager
{

private:
    std::map<std::string,std::shared_ptr<Multimedia>> multimediaMap;
    std::map<std::string,std::shared_ptr<Groupe>> groupeMap;

public:
    Manager();

    Photo createPhoto();
    Photo createPhoto(std::string name, std::string pathname);
    Photo createPhoto(std::string name, std::string pathname, float latitude, float longitude);


    Video createVideo();
    Video createVideo(std::string name, std::string pathname);
    Video createVideo(std::string name, std::string pathname, int duration);

    Film createFilm();
    Film createFilm(std::string name, std::string pathname);
    Film createFilm(std::string name, std::string pathname, int duration, int chaptersNumber, int* chaptersDurations);

    void describeMedia(std::string, std::ostream& stream) const;

};

#endif // MANAGER_H
