#include "Groupe.h"

Groupe::Groupe()
//implicit call to the constructor of list
{}

Groupe::Groupe(const std::string groupname):
    groupname(groupname)
{}

Groupe::Groupe(const std::string groupname, Multimedia** media, const int n):
    groupname(groupname)
{
    for (int i = 0; i < n; i++)
    {
        this->push_back(media[i]);
    }

}

std::string Groupe::getGroupName() const
{
    return this->groupname;
}

void Groupe::describe(std::ostream& stream) const
{
    stream << "Nom du groupe: " << this->getGroupName() << std::endl;
}
