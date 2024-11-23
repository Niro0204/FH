//
// Created by nico on 22.11.24.
//
#include <cstring>
#include "Buffer.h"

#include <iostream>
#include <ostream>

void Buffer::setData(size_t index, unsigned char data) {
    if(this->size > index) {
        this->data[index] = data;
    }
    else {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }
}

void Buffer::fill(unsigned char data) {
    std::memset(this->data,data,this->size);
}

void Buffer::fillPattern(const unsigned char* pattern, size_t patSize) {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = pattern[i % patSize];
    }
}

void Buffer::copyData(const unsigned char* srcData, size_t srcSize) {

    if(srcSize > this->size) {
        std::cerr << "Size out of bounds" << std::endl;
        return;
    }
    else if(this->data == nullptr){
        std::cerr << "Datapointer is null" << std::endl;
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
}