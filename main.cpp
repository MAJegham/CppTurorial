//
//  main.cpp
//  

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include <vector>

int main(int argc, char* argv[]) {

    std::cout << "Hello, This is the project work from INF224 "
              << std::endl;


    std::cout << "Testing Multimedia class : " << std::endl;
    Multimedia* multi;
    std::cout << "Multimedia class is abstract !" << std::endl;
    //we can't instanciate a Multimedia object as Multimedia is abstract
    multi = new Photo("PhotoMedia","./media/groot.jpg");

    std::cout << "Testing Photo class : " << std::endl;
    Photo* image = new Photo("photoName","./media/walle.jpeg");
    //image->describe(std::cout);
    //image->playMedia();

    std::cout << "Testing Video class : " << std::endl;
    std::string clipPath = "./media/video.mp4";
    Video* clip = new Video("fileName",clipPath);
    //clip->describe(std::cout);
    //clip->playMedia();

    // Etape 5:
    // Using vector
    std::cout << "____ QUESTION 5 : ____" << std::endl;
    std::vector<Multimedia*> listeMedia;
    listeMedia.push_back(image);
    listeMedia.push_back(clip);
    listeMedia.push_back(multi);
    for(std::vector<Multimedia*>::iterator it = listeMedia.begin();
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

    // Etape 6
    std::cout << "____ QUESTION 6 : ____" << std::endl;
    int dur [5] = { 10, 20, 30 };
    /*(duration_ptr[0]) = 50;
    (duration_ptr[1]) = 30;
    (duration_ptr[2]) = 20;*/
    Film* movie = new Film("MOVIEname","MOVIEpath",60,3,&dur[0]);
    movie->describe(std::cout);

    // Issues an error as Getter is returning the ptr and not a copy
    //    int* chapters = movie->getChaptersDurations();
    //    delete chapters;
    //    movie->describe(std::cout);

    std::cout << "__ Testing setChapterDurations method" << std::endl;
    int number = 2;
    int chapters [number] = {50, 80};
    movie->setChaptersDurations(chapters,number);
    movie->describe(std::cout);

    //const still enables the use of delete
    std::cout << "__ Testing getChapterDurations method" << std::endl;
    const int * chapters_ = movie->getChaptersDurations();
    //delete [] chapters_;
    movie->describe(std::cout);





}
