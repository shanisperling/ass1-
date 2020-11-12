// 322715574 shani sperling
#include "ex1.h"
#include <stdio.h>

/***************************************************************
 * function's name: is_bid_endian.
 * function's operation: it determinds endianness of a machine.
 * params: non.
 * return: int.
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
 * params: long,long.
 * return: long.
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
 * function's name: put_byte.
 * function's operation: replaced is a single byte in a long.
 * params: long, char, int.
 * return: long.
 ***************************************************************/ 
unsigned long put_byte(unsigned long x, unsigned char b, int i) {
    if(is_big_endian()){
    //big endian
        //points to the byte we want to change.
        char * result = (char*) & x +i;
        //puts the char we were given in the right.
        *result = b;
        return x; 
    }
    //little endian
    //points to the byte we want to change.
    char * result = (char*) & x + (sizeof(long)-1-i);
    //puts the char we were given in the right.
    *result = b;
    return x;
} 