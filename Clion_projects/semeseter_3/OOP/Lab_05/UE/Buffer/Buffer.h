//
// Created by nico on 22.11.24.
//

#ifndef BUFFER_H
#define BUFFER_H

#include <cstring>

class Buffer {

private:
    unsigned int id;
    unsigned char* data{};
    size_t size{};

public:
    Buffer(unsigned int id, unsigned char* data, size_t size){
        this->id = id;
        this->data = new unsigned char[size]; // Speicher allokieren
        std::memcpy(this->data, data, size);  // Daten kopieren
        this->size = size;
    }

    Buffer(unsigned int id, size_t size){this->id=id; this->size=size;};

    ~Buffer(){delete[] data;};

    unsigned int getId()const{return this->id;};
    unsigned char* getData()const{return this->data;};
    size_t getSize()const{return this->size;};

    void setData(size_t, unsigned char);
    void fill(unsigned char);
    void fillPattern(const unsigned char*, size_t);
};


#endif //BUFFER_H
