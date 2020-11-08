// 322715574 shani sperling
#include "ex1.h"
#include <stdio.h>

/***************************************************************
 * function's name: is_bid_endian.
 * function's operation: it determinds endianness of a machine.
 ***************************************************************/ 
int is_big_endian() {
    // this word is the number 1 represented in 8 bytes
    unsigned long word=1;
    // a character pointer which comtaines only one byte points to word.
    char * c = (char*) & word;
    /* if the byte that is in *c is 0 
    that means that the first byte in word is stored first.
    and if the byte is 1 that means that the last byte 
    was stored first.*/  
    if (*c==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*********************************************************************
 * function's name: merge_bytes.
 * function's operation: gets to longs and merges them into one long.
 *********************************************************************/ 
unsigned long merge_bytes(unsigned long x, unsigned long int y) {
    if(is_big_endian()){
    //big endian
    //takes the righא piece we need from y.
    unsigned long halfY=y>>(sizeof(long)/2)*8;
    halfY=halfY<<(sizeof(long)/2)*8;
    //takes the righא piece we need from x.
    unsigned long halfX=x<<(sizeof(long)/2)*8;
    halfX=halfX>>(sizeof(long)/2)*8;
    unsigned long result=halfX+halfY;
    }
    // little endian
    //takes the righא piece we need from y. 
    unsigned long halfY=y<<(sizeof(long)/2)*8;
    halfY=halfY>>(sizeof(long)/2)*8;
    //takes the righא piece we need from x.
    unsigned long halfX=x>>(sizeof(long)/2)*8;
    halfX=halfX<<(sizeof(long)/2)*8;
    unsigned long result=halfX+halfY;
}
 /***************************************************************
 * function's name: is_bid_endian.
 * function's operation: it determinds endianness of a machine.
 ***************************************************************/ 
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    unsigned long leftBites = x >> (( 8 - i ) * 8);
    leftBites = leftBites << (( 8 - i ) * 8);
    printf("left bites= 0x%lx\n", leftBites);
    unsigned long rightBites = x << (( i + 1 ) * 8);
    rightBites = rightBites >> (( i + 1 ) * 8);
    printf("right bits= 0x%lx\n", rightBites);
    /*unsigned long c = b << i * 8;
    printf("c= 0x%lx\n", c);
    c = c >> i * 8;
    printf("c= 0x%lx\n", c);*/

    printf("c= 0x%lx\n", c);
    return (leftBites+rightBites+c);
} 