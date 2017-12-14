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

int main(int argc, char* argv[]) {

    //___________________________________________________________________ Hello
    std::cout << "Hello, This is the project work from INF224 "
              << std::endl;

    //___________________________________________________________________ Testing Multimedia Class
    std::cout << "__ Testing Multimedia class __ " << std::endl;
    Multimedia* multi;
    std::cout << "Multimedia class is abstract !" << std::endl;
    //we can't instanciate a Multimedia object as Multimedia is abstract
    multi = new Photo("PhotoMedia","./media/groot.jpg");

    //___________________________________________________________________ Testing Photo Class
    std::cout << "Testing Photo class : " << std::endl;
    Photo* image = new Photo("photoName","./media/walle.jpeg");
    //image->describe(std::cout);
    //image->playMedia();

    //___________________________________________________________________ Testing Video Class
    std::cout << "Testing Video class : " << std::endl;
    std::string clipPath = "./media/video.mp4";
    Video* clip = new Video("fileName",clipPath);
    //clip->describe(std::cout);
    //clip->playMedia();


    //___________________________________________________________________ ETAPE 5 ___
    std::cout << "____ QUESTION 5 : ____" << std::endl;
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
    std::cout << "____ QUESTION 6 : ____" << std::endl;
    int dur [5] = { 10, 20, 30 };
    Film* movie = new Film("MOVIEname","MOVIEpath",60,3,dur); //int[] can be cast to int*
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
    Groupe grp = Groupe("Premier Groupe",(Multimedia**)&clip,1); //DOESN'T COMPILE WITHOUT CAST ???
    grp.describe(std::cout);
    //grp.push_back(movie);
    (grp.front())->describe(std::cout);

}
