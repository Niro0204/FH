//
// Created by nico on 27.11.24.
//

#include "people.h"


Person::Person(const std::string& firstName, const std::string& lastName, const char gender, const std::string& birthDate){
    this->firstName = firstName;
    this->lastName = lastName;
    this->gender = gender;
    this->birthDate = birthDate;
    this->SVNr = 0;
};

Person::Person(const std::string& firstName, const std::string& lastName, const char gender, const std::string& birthDate,const int SVNr){
    this->firstName = firstName;
    this->lastName = lastName;
    this->gender = gender;
    this->birthDate = birthDate;
    this->SVNr = SVNr;
};

Student::Student(const std::string& fN, const std::string& lN, const char g, const std::string& bD,const int sN, const std::string& sB, const  std::string& sc)
: Person(fN,lN,g,bD){
    this->studentNumber = sN;
    this->studyBeginDate = sB;
    this->school = sc;
};

Student::Student(const std::string& fN, const std::string& lN, const char g, const std::string& bD,const int SVNr,const int sN, const std::string& sB, const std::string& sc)
: Person(fN,lN,g,bD,SVNr){
    this->studentNumber = sN;
    this->studyBeginDate = sB;
    this->school = sc;
}

Alumnus Student::promoteToAlumnus(const Student& oldStudent, const std::string& gradDate) {
    return Alumnus(oldStudent, gradDate);
}

Alumnus::Alumnus(const Student& student, const std::string& studyEndDate) : Student(student) {
    this->studyEndDate = studyEndDate;
};

void Person::whoAmI(){
    std::cout << "-----Person-----" << std::endl;
    std::cout << "My name is " << getFirstName() << " " << getLastName() << std::endl;
    std::cout << getGender() << "born on" << getBirthDate() << std::endl;
    if(getSVNr() != 0)
    {
        std::cout << "Social Security Number: " << getSVNr() << std::endl;
    }
    else
    {
        std::cout << "No social security number" << std::endl;
    }
    std::cout << "----------------" << std::endl;
};

void Student::whoAmI()override{
    std::cout << "-----Student-----" << std::endl;
    std::cout << "My name is " << getFirstName() << " " << getLastName() << std::endl;
    std::cout << getGender() << "born on" << getBirthDate() << std::endl;
    if(getSVNr() != 0)
    {
        std::cout << "Social Security Number: " << getSVNr() << std::endl;
    }
    else
    {
        std::cout << "No social security number" << std::endl;
    }
    std::cout << "-----------------" << std::endl;
};