#ifndef MANAGER_H
#define MANAGER_H

#include "Multimedia.h"
#include "Groupe.h"
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
    Photo createPhoto(std::string name, std::string pathname,float latitude, float longitude);
    Photo createPhoto(std::string name, std::string pathname);
};

#endif // MANAGER_H
