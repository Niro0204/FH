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

    Buffer(unsigned int id, const unsigned char* data, size_t size);
    Buffer(const unsigned int id, const size_t size){this->id=id; this->data = new unsigned char[size]; this->size=size;};
    Buffer(const Buffer& other);
    Buffer(Buffer&& other) noexcept ;

    ~Buffer(){delete[] data;};

    [[nodiscard]] unsigned int getId()const{return this->id;};
    [[nodiscard]] unsigned char* getData()const{return this->data;};
    [[nodiscard]] size_t getSize()const{return this->size;};

    void setData(size_t, unsigned char) const;
    void fill(unsigned char) const;
    void fillPattern(const unsigned char*, size_t) const;
    void copyData(const unsigned char*, size_t) const;
    void print()const;
};


#endif //BUFFER_H
