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
