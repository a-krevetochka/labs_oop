#include "NPC.h"

const Point &NPC::getCoordinates() const {
    return _coordinates;
}


const std::string &NPC::getTitle() const {
    return _title;
}

void NPC::setCoordinates(const Point &coordinates) {
    NPC::_coordinates = coordinates;
}

void NPC::setTitle(const std::string &title) {
    NPC::_title = title;
}

void NPC::setIsAlive(bool isAlive) {
    NPC::_isAlive = isAlive;
}

const std::string &NPC::getName() const {
    return _name;
}

void NPC::setName(const std::string &name) {
    NPC::_name = name;
}

bool NPC::isAlive() const {
    return _isAlive;
}

std::ostream &operator<<(std::ostream &strm, const NPC *npc) {
    strm << npc->getTitle() << std::endl;
    strm << npc->getName() << std::endl;
    strm << npc->getCoordinates() << std::endl;
    std::string alive = npc->isAlive() ? "alive" : "was killed";
    strm << alive;
    return strm;
}