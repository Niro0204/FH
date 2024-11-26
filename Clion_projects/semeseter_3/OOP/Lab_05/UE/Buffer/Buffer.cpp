//
// Created by nico on 22.11.24.
//
#include <cstring>
#include <iostream>
#include <ostream>
#include "Buffer.h"



//unsigned int Buffer::nextId = 1;
unsigned int ID::id = 1;


/*
Buffer::Buffer(const unsigned int id, const unsigned char* data, const size_t size){
    this->id = id;
    this->data = new unsigned char[size];
    std::memcpy(this->data, data, size);
    this->size = size;
}
*/

/*Buffer::Buffer(const unsigned char* data, const size_t size){
    this->id = nextId++;
    this->data = new unsigned char[size];
    std::memcpy(this->data, data, size);
    this->size = size;
}*/

Buffer::Buffer(const unsigned char* data, const size_t size){
    this->id = ID::getNextId();
    this->data = new unsigned char[size];
    std::memcpy(this->data, data, size);
    this->size = size;
}

// Copy Konstruktor
Buffer::Buffer(const Buffer& other)
{
    this->id = other.id;
    this->size = other.size;

    if(other.data != nullptr)
    {
        this->data = new unsigned char[other.size];
        std::memcpy(this->data, other.data, other.size);
    }
    else
    {
        this->data = nullptr;
    }
}

// Move Konstruktor
Buffer::Buffer(Buffer&& other) noexcept
{
    this->id = other.id;
    this->data = other.data;
    this->size = other.size;

    other.data = nullptr;
    other.size = 0;
    other.id = 0;
}

/*
Buffer::Buffer(int id, char c, size_t size) {
    this->id = id;
    this->size = size;
    this->data = new unsigned char[size];

    // Fülle das Array mit dem Zeichen c
    for (size_t i = 0; i < size; ++i) {
        this->data[i] = static_cast<unsigned char>(c);
    }
}
*/

/*Buffer::Buffer(const char c, const size_t size) {
    this->id = nextId++;
    this->size = size;
    this->data = new unsigned char[size];

    // Fülle das Array mit dem Zeichen c
    for (size_t i = 0; i < size; ++i) {
        this->data[i] = static_cast<unsigned char>(c);
    }
}*/

Buffer::Buffer(const char c, const size_t size) {
    this->id = ID::getNextId();
    this->size = size;
    this->data = new unsigned char[size];

    // Fülle das Array mit dem Zeichen c
    for (size_t i = 0; i < size; ++i) {
        this->data[i] = static_cast<unsigned char>(c);
    }
}

// Setzt Wert an einem bestimmten Index
void Buffer::setData(const size_t index, const unsigned char data) const
{
    if(this->size > index) {
        this->data[index] = data;
    }
    else {
        std::cerr << "Index out of bounds" << std::endl;
    }
}

// Füllt den gesamten Buffer mit einem Wert
void Buffer::fill(const unsigned char data) const
{
    std::memset(this->data,data,this->size);
}

// Füllt den Buffer mit einem Muster
void Buffer::fillPattern(const unsigned char* pattern, const size_t patSize) const
{
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = pattern[i % patSize];
    }
}

// Kopiert die Daten von einem Quellbuffer in den aktuellen Buffer
void Buffer::copyData(const unsigned char* srcData, const size_t srcSize) const
{

    if(srcSize > this->size) {
        std::cerr << "Size out of bounds" << std::endl;
        return;
    }
    else if(this->data == nullptr){
        std::cerr << "Data-pointer is null" << std::endl;
    }

    std::memcpy(this->data,srcData,this->size);
}

// Gibt den Inhalt des Buffers aus
void Buffer::print() const{
    std::cout << "ID:" << getId() << std::endl;
    std::cout << "Size: " <<  getSize() << std::endl;

    const unsigned char* data = getData();
    for (size_t i = 0; i < this->size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "----------" << std::endl;

}