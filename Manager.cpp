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
        stream << "Requested element doesn't exist !" << std::endl;
    }
}


















