#include <iostream>
#include "Buffer.h"

void useBuffer(Buffer& v) {
    unsigned char pattern[] = {':', ')', ' '};

    v.fillPattern(pattern, sizeof(pattern));

    v.print();
}

Buffer createBuffer() {
    Buffer buff(2,5);

    buff.fill('A');

    return buff;
}

int main() {
    Buffer buffer(1, 12);
    useBuffer(buffer);

    Buffer buff = createBuffer();
    Buffer buff2 = buff;

    buff.print();
    buff2.print();
    buff2.setData(0,'B'); // ersten buchstaben von A auf B setzen
    buff2.print();

    return 0;
}
