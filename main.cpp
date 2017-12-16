//
//  main.cpp
//  

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"
#include <vector>

#define so std::cout

int main(int argc, char* argv[]) {

    //___________________________________________________________________ Hello
    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "Hello, This is the project work from INF224 "
              << std::endl;

    //___________________________________________________________________ Testing Multimedia Class
    std::cout << "__ Testing Multimedia class __ " << std::endl;
    Multimedia* multi;
    std::cout << "Multimedia class is abstract !" << std::endl;
    //we can't instanciate a Multimedia object as Multimedia is abstract
    multi = new Photo("PhotoMedia","./media/groot.jpg",894,1311);

    //___________________________________________________________________ Testing Photo Class
    std::cout << "Testing Photo class : " << std::endl;
    Photo* image = new Photo("imageWalle","./media/walle.jpeg",940,627);
    //image->describe(std::cout);
    //image->playMedia();

    //___________________________________________________________________ Testing Video Class
    std::cout << "Testing Video class : " << std::endl;
    std::string clipPath = "./media/video.mp4";
    Video* clip = new Video("fileName",clipPath,18);
    //clip->describe(std::cout);
    //clip->playMedia();


    //___________________________________________________________________ ETAPE 5 ___
    std::cout << "_____________________ QUESTION 5 : ____________________" << std::endl;
    // Using vector
    std::vector<Multimedia*> listeMedia;
    listeMedia.push_back(image);
    listeMedia.push_back(clip);
    listeMedia.push_back(multi);
    for( auto it = listeMedia.begin(); //std::vector<Multimedia*>::iterator
         it != listeMedia.end(); ++it)
    {
        (*it)->describe(std::cout);
        //(*it)->playMedia();
    }

    // Using arrays
    Multimedia* arrayMedia[3];
    arrayMedia[0] = image;
    arrayMedia[1] = clip;
    arrayMedia[2] = multi;
    for (int i = 0; i<3; i++)
    {
        //arrayMedia[i]->playMedia();
        arrayMedia[i]->describe(std::cout);
    }

    //___________________________________________________________________ ETAPE 6 ___
    std::cout << "_____________________ QUESTION 6 : ____________________" << std::endl;
    int dur [] = { 10, 20, 30 };
    Film* movie = new Film("MOVIEname","MOVIEpath",60,3,dur); //int[] can be cast to int*
    //Normally Duration is the sum of the chapters' durations
    movie->describe(std::cout);

    std::cout << "__ Testing setChaptersDurations method" << std::endl;
    int number = 2;
    int chapters [number] = {50, 80};
    movie->setChaptersDurations(chapters,number);
    movie->describe(std::cout);

    //const still enables the use of delete => now we return a copy
    std::cout << "__ Testing getChaptersDurations method" << std::endl;
    const int * chapters_ = movie->getChaptersDurations();
    for (int i = 0; i<2; i++)
    {
        std::cout << chapters_[i] << std::endl;
    }
    delete chapters_; //deletes chapters_ but not movie's chapters
    movie->describe(std::cout);
    std::cout << chapters_[2] << std::endl;

    //___________________________________________________________________ ETAPE 7 ___
    std::cout << "_____________________ QUESTION 7 : ____________________" << std::endl;
    // _______ Testing object copy problem
    std::cout << "__ Testing copy" << std::endl;
    std::cout << "original movie:" << std::endl;
    movie->describe(std::cout);
    std::cout << "copy of movie:" << std::endl;
    Film* copy_movie = new Film(*movie);
    copy_movie->describe(std::cout);
    std::cout << "__ After changing the chapters of the copy" << std::endl;
    int chaps [number] = {90, 99};
    copy_movie->setChaptersDurations(chaps,number);
    std::cout << "original movie:" << std::endl;
    movie->describe(std::cout);
    std::cout << "copy of movie:" << std::endl;
    copy_movie->describe(std::cout);

    //___________________________________________________________________ ETAPE 8 ___
    std::cout << "_____________________ QUESTION 9 : ____________________" << std::endl;
    std::shared_ptr<Video> video_shPtr = std::make_shared<Video>("Video_sharedPointerName","Video_sharedPointerPath");
    std::shared_ptr<Film> film_shPtr = std::make_shared<Film>("Film_sharedPointerName","Film_sharedPointerPath");
    video_shPtr->describe(so);
    film_shPtr->describe(so);
    std::shared_ptr<Multimedia> multi_shPtr = film_shPtr;
    multi_shPtr->describe(so);
    //trying initialisation with raw pointers
    std::shared_ptr<Photo> image_shPtr(image);
    image_shPtr->describe(so);
    Video* raw_ptr = video_shPtr.get();
    video_shPtr.reset();
    raw_ptr->describe(so); //Beware : Mixing raw pointers and shared_ptr: The Pointee was already deleted

    // Apparently the shared_pointer constructor creates a copy of the pointee
    // Code runs correctly
    video_shPtr = std::make_shared<Video>(*clip);
    video_shPtr.reset();
    clip->describe(so);

    //Testing automatic destruction with shared_ptr
    std::cout << "________SharedPtr Destruction test" << std::endl;
    image_shPtr->describe(so);
    image_shPtr.reset();

    std::cout << "End of program; remaining shared_ptr pointees will be destroyed as well" << std::endl;

}























