#include "Groupe.h"

Groupe::Groupe()
//implicit call to the constructor of list
{}

Groupe::Groupe(const std::string groupname):
    groupname(groupname)
{}

Groupe::Groupe(const std::string groupname, std::initializer_list<Multimedia*> il):
    std::list<Multimedia*>(il), groupname(groupname)
{}

std::string Groupe::getGroupName() const
{
    return this->groupname;
}

void Groupe::describe(std::ostream& stream) const
{
    stream << "Multimedia group description : " << this->getGroupName() << std::endl;
    for (auto it : *this)
    {
        it->describe(stream);
    }
}
