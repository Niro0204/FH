//
// Created by nico on 22.11.24.
//

#ifndef BUFFER_H
#define BUFFER_H

class Buffer {

private:
    unsigned int id;
    static unsigned int nextId;
    unsigned char* data{};
    size_t size{};

public:

    //Konstruktoren
    // Buffer(unsigned int id, const unsigned char* data, size_t size);
    Buffer(const unsigned char* data, size_t size);
    explicit Buffer(const size_t size){this->id = nextId++;this->size = size;};
    // Buffer(const unsigned int id, const size_t size){this->id=id; this->data = new unsigned char[size]; this->size=size;};
    // Buffer(int id, char c, size_t size);
    Buffer(char c, size_t size);

    Buffer(const Buffer& other); //= delete;
    Buffer(Buffer&& other) noexcept; //= delete;
    /*
    Buffer& operator=(const Buffer& other) = delete; // Copy Assignment explizit löschen
    Buffer& operator=(Buffer&& other) noexcept = delete; // Move Assignment explizit löschen
    */

    //Destruktor
    ~Buffer(){delete[] data;};

    // Methoden
    [[nodiscard]] unsigned int getId()const{return this->id;};
    [[nodiscard]] unsigned char* getData()const{return this->data;};
    [[nodiscard]] size_t getSize()const{return this->size;};

    void setData(size_t, unsigned char) const;
    void fill(unsigned char) const;
    void fillPattern(const unsigned char*, size_t) const;
    void copyData(const unsigned char*, size_t) const;
    void print()const;
};

// klasse zur Programmweiten vergabe von IDs

class ID{
private:
    static unsigned int id;

public:

   static unsigned int getNextId(){return id++;};

};


#endif //BUFFER_H
