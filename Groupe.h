#ifndef GROUPE_H
#define GROUPE_H

#include "Multimedia.h"
#include <list>
#include <string>

class Groupe : public std::list<Multimedia*>
{

private:
    std::string groupname;


public:
    Groupe();
    Groupe(const std::string groupname);
    Groupe(const std::string groupname, const Multimedia** const media, const int n);

    std::string getGroupName() const;
    void describe(std::ostream& stream) const;

};

#endif // GROUPE_H
