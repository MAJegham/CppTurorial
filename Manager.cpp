#include "Manager.h"

Manager::Manager()
{

}

Photo Manager::createPhoto()
{
    std::shared_ptr photo_sp = new Photo();
    this->multimediaMap.key_comp();

}

Photo createPhoto(std::string name, std::string pathname,float latitude, float longitude);

Photo createPhoto(std::string name, std::string pathname);
