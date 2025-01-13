// Class declaration for a Guitar object.
//Includes Guitar class definition.
#include "Guitar.h"
#include <fstream> 

// Default constructor for the Guitar class. Initializes all member variables to default values.
Guitar::Guitar() {
    name = " ";             //Name of the guitar
    stringMaterial = " ";   //Material of the strings
    bodyMaterial = " ";     //Material of the body
    numberOfStrings = 0;    //Number of strings
    bodyType = " ";         //Type of the body
    mediatormaterial = " "; //Material of the mediator
    attunement = 0; // Tuning level of the guitar
}

// Constructor for the Guitar class that takes parameters to initialize the member variables.
Guitar::Guitar(const string& name, int numberOfStrings, const string& stringMaterial, const string& bodyMaterial, const string& bodyType, const string& mediatormaterial) {
    set_name(name);
    set_stringMaterial(stringMaterial);
    set_bodyMaterial(bodyMaterial);
    set_numberOfStrings(numberOfStrings);
    set_mediator_material(mediatormaterial);
    set_body_Type(bodyType);
    attunement = 0;
}

/// Sets the body type of the guitar. If the input is empty, sets it to "None".
void Guitar::set_body_Type(const string& bodytype) {
    this->bodyType = bodytype.empty() ? "None" : bodytype;
}

/// Sets the mediator material of the guitar. If the input is empty, sets it to "None".
void Guitar::set_mediator_material(const string& madmat) {
    this->mediatormaterial = madmat.empty() ? "None" : madmat;
}

/// Returns a string representation of the guitar's attributes.
string Guitar::to_string() const {
    return("Name: " + name + ", Count of string: " + std::to_string(numberOfStrings) + ", material of string: " + stringMaterial + ", material of body: " + bodyMaterial + ", body type: " + bodyType + ", material of mediator: " + mediatormaterial);
}

/// Tunes the guitar, setting the attunement level to 100.
void Guitar::tune() {
    cout << "Tuning the guitar (" << name << ")..." << "\n";
    this->attunement = 100; // Sets attunement to 100
}

/// Plays the guitar. If the attunement level is above 10, it plays and reduces the attunement level by 10. Otherwise, it prints a message that the guitar needs tuning.
void Guitar::play() {
    if (attunement > 10) { // If attunement is sufficient
        cout << "Playing on " << name << " this mediator made from " << mediatormaterial << "\n"; // Plays the guitar
        this->attunement -= 10;
    }
    else { // If attunement is insufficient
        cout << "You can`t play. Tune instrument" << "\n";
    }
}

/// Saves the guitar's attributes to a file.
void Guitar::saveToFile(std::ofstream& out) const {
    out << "Guitar\n"; // Writes the type of instrument to the file
    out << name << "\n" << stringMaterial << "\n" << bodyMaterial << "\n" << numberOfStrings << "\n"; // Writes the relevant attributes to the file
    out << mediatormaterial << "\n" << bodyType << "\n" << attunement << "\n";
}

/// Loads the guitar's attributes from a file.
void Guitar::loadFromFile(std::ifstream& in) {
    std::getline(in, name); // Reads the name
    std::getline(in, stringMaterial); // Reads the string material
    std::getline(in, bodyMaterial); // Reads the body material
    in >> numberOfStrings; // Reads the number of strings
    in.ignore(); // Ignores the newline character
    std::getline(in, mediatormaterial); // Reads the mediator material
    std::getline(in, bodyType); // Reads the body type
    in >> attunement; // Reads the attunement level
    in.ignore(); // Ignores the newline character
}
