#include "Manager.h"

Manager::Manager()
{

}

Photo Manager::createPhoto()
{
    std::shared_ptr<Photo> photo_shPtr = std::make_shared<Photo>();
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Photo> >(photo_shPtr->getName(),photo_shPtr));
    return *(photo_shPtr.get());
}

Photo Manager::createPhoto(std::string name, std::string pathname)
{
    std::shared_ptr<Photo> photo_shPtr = std::make_shared<Photo>(name,pathname);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Photo> >(photo_shPtr->getName(),photo_shPtr));
    return *(photo_shPtr.get());
}

Photo Manager::createPhoto(std::string name, std::string pathname,float latitude, float longitude)
{
    std::shared_ptr<Photo> photo_shPtr = std::make_shared<Photo>(name,pathname,latitude,longitude);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Photo> >(photo_shPtr->getName(),photo_shPtr));
    return *(photo_shPtr.get());
}

Video Manager::createVideo()
{
    std::shared_ptr<Video> video_shPtr = std::make_shared<Video>();
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Video> >(video_shPtr->getName(),video_shPtr));
    return *(video_shPtr.get());
}

Video Manager::createVideo(std::string name, std::string pathname)
{
    std::shared_ptr<Video> video_shPtr = std::make_shared<Video>(name, pathname);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Video> >(video_shPtr->getName(),video_shPtr));
    return *(video_shPtr.get());
}

Video Manager::createVideo(std::string name, std::string pathname, int duration)
{
    std::shared_ptr<Video> video_shPtr = std::make_shared<Video>(name, pathname, duration);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Video> >(video_shPtr->getName(),video_shPtr));
    return *(video_shPtr.get());
}

Film Manager::createFilm()
{
    std::shared_ptr<Film> film_shPtr = std::make_shared<Film>();
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Film> >(film_shPtr->getName(),film_shPtr));
    return *(film_shPtr.get());
}

Film Manager::createFilm(std::string name, std::string pathname)
{
    std::shared_ptr<Film> film_shPtr = std::make_shared<Film>(name, pathname);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Film> >(film_shPtr->getName(),film_shPtr));
    return *(film_shPtr.get());
}

Film Manager::createFilm(std::string name, std::string pathname, int duration, int chaptersNumber, int* chaptersDurations)
{
    std::shared_ptr<Film> film_shPtr = std::make_shared<Film>(name, pathname, duration, chaptersNumber, chaptersDurations);
    this->multimediaMap.insert(std::pair< std::string, std::shared_ptr<Film> >(film_shPtr->getName(),film_shPtr));
    return *(film_shPtr.get());
}

void Manager::describeMedia(std::string nameIndex, std::ostream& stream) const
{
    if ( this->multimediaMap.count(nameIndex) )
    {
        this->multimediaMap.at(nameIndex)->describe(stream);
    }
    else
    {
        stream << "ERROR: Requested media doesn't exist !" << std::endl;
    }
}

void Manager::playMedia(std::string nameIndex) const
{
    if ( this->multimediaMap.count(nameIndex) )
    {
        this->multimediaMap.at(nameIndex)->playMedia();
    }
    else
    {
        std::cout << "ERROR: Requested media doesn't exist !" << std::endl;
    }
}

Groupe Manager::createGroup()
{
    std::shared_ptr<Groupe> grp_shPtr = std::make_shared<Groupe>();
    this->groupeMap.insert(std::pair< std::string, std::shared_ptr<Groupe> >(grp_shPtr->getGroupName(),grp_shPtr));
    return *(grp_shPtr.get());
}

Groupe Manager::createGroup(const std::string groupname)
{
    std::shared_ptr<Groupe> grp_shPtr = std::make_shared<Groupe>(groupname);
    this->groupeMap.insert(std::pair< std::string, std::shared_ptr<Groupe> >(grp_shPtr->getGroupName(),grp_shPtr));
    return *(grp_shPtr.get());
}

Groupe Manager::createGroup(const std::string groupname,std::initializer_list<std::shared_ptr<Multimedia>> il)
{
    std::shared_ptr<Groupe> grp_shPtr = std::make_shared<Groupe>(groupname,il);
    this->groupeMap.insert(std::pair< std::string, std::shared_ptr<Groupe> >(grp_shPtr->getGroupName(),grp_shPtr));
    return *(grp_shPtr.get());
}

void Manager::describeGroup(std::string nameIndex, std::ostream& stream) const
{
    if ( this->groupeMap.count(nameIndex) )
    {
        this->groupeMap.at(nameIndex)->describe(stream);
    }
    else
    {
        stream << "ERROR: Requested group doesn't exist !" << std::endl;
    }
}















