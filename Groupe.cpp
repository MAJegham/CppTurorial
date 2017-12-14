#include "Groupe.h"

Groupe::Groupe()
//implicit call to the constructor of list
{}

Groupe::Groupe(const std::string groupname):
    groupname(groupname)
{}

Groupe::Groupe(const std::string groupname, const Multimedia** const media, const int n)
{

}

std::string Groupe::getGroupName() const
{

}

void Groupe::describe(std::ostream& stream) const
{
    stream << "Nom du groupe: " << this->groupname << std::endl;
}
