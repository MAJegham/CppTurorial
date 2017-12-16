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
#include <map>
#include <memory>

#define so std::cout

int main(int argc, char* argv[]) {

    //___________________________________________________________________ Hello
    std::cout << "\n_____________________ INF224 __________________________\n" << std::endl;

    Multimedia* multi;
    multi = new Photo("PhotoMedia","./media/groot.jpg",894,1311);
    Photo* image = new Photo("imageWalle","./media/walle.jpeg",940,627);
    Video* clip = new Video("fileName","./media/video.mp4",18);
    int dur [] = { 10, 20, 30 };
    Film* movie = new Film("MOVIEname","MOVIEpath",60,3,dur); //int[] can be cast to int*
    //Normally Duration is the sum of the chapters' durations
    Film* copy_movie = new Film(*movie);

    //___________________________________________________________________ ETAPE 8 ___
    std::cout << "_____________________ QUESTION 9 : ____________________" << std::endl;

    std::shared_ptr<Video> video_shPtr = std::make_shared<Video>("Video_sharedPointerName","Video_sharedPointerPath");
    video_shPtr->describe(so);

    std::shared_ptr<Film> film_shPtr = std::make_shared<Film>("Film_sharedPointerName","Film_sharedPointerPath");
    film_shPtr->describe(so);

    std::shared_ptr<Multimedia> multi_shPtr = film_shPtr;
    multi_shPtr->describe(so);

    Groupe grp = Groupe("MyEmptyGroupOfSharedPointersToMultimedia");
    grp.describe(so);

    //    // _ UNWANTED BEHAVIOUR _   ===> WE need the delete grp_ptr
    //    // No Object Destruction occured
    //    Groupe* grp_ptr = new Groupe("PointedGroup",{video_shPtr, film_shPtr});
    //    grp_ptr->describe(so);
    //    delete grp_ptr;

    // __ CORRECT BEHAVIOUR __
    // in this case objects in the group are automatically destroyed, CORRECT BEHAVIOUR
    //    Groupe grp1 = Groupe("MySecondGroup",{multi_shPtr, video_shPtr, film_shPtr});
    //    grp1.describe(so);

    Groupe grp2 = Groupe("MySecondGroup",{video_shPtr, film_shPtr});
    grp2.describe(so);
    video_shPtr.reset(); // This doesn't destroy the pointee as the group is pointing to it
    grp2.describe(so);
    grp2.pop_front(); // This normally destroys video_shPtr pointee
    grp2.describe(so);

    //___________________________________________________________________ ETAPE 8 ___
    std::cout << "_____________________ QUESTION 10 : ____________________" << std::endl;
    std::map<std::string,std::shared_ptr<Multimedia>> multimediaMap;
    std::pair<std::string, std::shared_ptr<Multimedia>> firstElt("multiElt",multi_shPtr);
    multimediaMap.insert(firstElt);
    multimediaMap["multiElt"]->describe(so);



    std::cout << "\n_____________________ END OF MAIN __________________________" << std::endl;
}

