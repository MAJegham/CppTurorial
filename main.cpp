//
//  main.cpp
//  

#include <iostream>
#include "Multimedia.h"
#include "Manager.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"
#include <vector>
#include <map>
#include <memory>

#define so std::cout

int main(int argc, char* argv[]) {

    //___________________________________________________________________ Hello
    std::cout << "\n_____________________ INF224 __________________________\n" << std::endl;

    //___________________________________________________________________ ETAPE 8 ___
    std::cout << "_____________________ QUESTION 10 : ____________________" << std::endl;
    Manager manager = Manager();
    Photo photo = manager.createPhoto("myImage","ImagePath",5,15);
    photo.describe(so);
    Video video = manager.createVideo("myVideo","VideoPath", 548);
    video.describe(so);
    int dur [] = { 10, 20, 30 };
    Film film = manager.createFilm("myFilm","FilmPath",1256,3,dur);
    film.describe(so);

    manager.describeMedia("myVideo",so);


    std::cout << "\n_____________________ END OF MAIN __________________________" << std::endl;
}

