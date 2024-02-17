#include "Human.h"
/*!
    \brief Human constructor
*/
Human::Human() {
    name = "Ryan Gosling";
}
/*!
    \brief Human constructor with params
    \param string _name
*/
Human::Human(std::string _name) {
    name = _name;
}