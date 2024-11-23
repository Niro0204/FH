#include <iostream>
#include "Buffer.h"

void useBuffer(Buffer& v) {
    unsigned char pattern[] = {':', ')', ' '};

    v.fillPattern(pattern, sizeof(pattern));

    v.print();
}

Buffer createBuffer() {
    Buffer buff(2,12);


    return buff;
}

int main() {
    Buffer buffer(1, 12);
    useBuffer(buffer);
    return 0;
}
