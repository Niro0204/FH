//
// Created by nico on 22.11.24.
//
#include <cstring>
#include "Buffer.h"

#include <iostream>
#include <ostream>

Buffer::Buffer(const unsigned int id, const unsigned char* data, const size_t size){
    this->id = id;
    this->data = new unsigned char[size];
    std::memcpy(this->data, data, size);
    this->size = size;
}

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

Buffer::Buffer(Buffer&& other) noexcept
{
    this->id = other.id;
    this->data = other.data;
    this->size = other.size;

    other.data = nullptr;
    other.size = 0;
    other.id = 0;
}


void Buffer::setData(const size_t index, const unsigned char data) const
{
    if(this->size > index) {
        this->data[index] = data;
    }
    else {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
}

void Buffer::fill(const unsigned char data) const
{
    std::memset(this->data,data,this->size);
}

void Buffer::fillPattern(const unsigned char* pattern, const size_t patSize) const
{
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = pattern[i % patSize];
    }
}

void Buffer::copyData(const unsigned char* srcData, size_t srcSize) const
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

void Buffer::print() const{
    std::cout << "ID:" << getId() << std::endl;
    std::cout << "Size: " <<  getSize() << std::endl;

    unsigned char* data = getData();
    for (size_t i = 0; i < this->size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}