//
// Created by nico on 27.11.24.
//

#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>


class Person{
private:
    std::string firstName;
    std::string lastName;
    char gender;
    std::string birthDate;
    int SVNr;

public:
    Person(const std::string& firstName, const std::string& lastName, const char gender, const std::string& birthDate);
    Person(const std::string& firstName, const std::string& lastName, const char gender, const std::string& birthDate,const int SVNr);

    virtual ~Person(){std::cout << "Person deleted" << std::endl;};

    std::string getFirstName() const {return this->firstName;};
    std::string getLastName() const {return this->lastName;};
    char getGender()const {return this->gender;};
    std::string getBirthDate() const {return this->birthDate;};
    int getSVNr()const {return this->SVNr;};


    virtual void whoAmI();

};

class Student : public Person
{
private:
    int studentNumber;
    std::string studyBegin;
    std::string school;
public:

    Student(const std::string& fN, const std::string& lN, char g, const std::string& bD, const int sN, const std::string& sB, const std::string& sc);
    Student(const std::string& fN, const std::string& lN, char g, const std::string& bD,const int SVNr,const int sN, const std::string& sB, const std::string& sc);

    ~Student(){std::cout << "Student deleted" << std::endl;};

    void whoAmI()override;
};
#endif //PEOPLE_H
