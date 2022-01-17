#ifndef BIG_INT
#define BIG_INT
#include<stdio.h>
#include<string.h>
#define PLUS 0
#define MINUS 1
#define SIZE 310 
                 //As per the question,it is asked to implement ints 1024 bits wide,
                 //Hence,the range is -(2**1023) to (2**1023-1)
                 //2**1023 contains 308 digits
                 //hence to represent 1024 bits wide number in decimal we will require minimum 308 digits

typedef struct Big_int{
	char magn[SIZE]; 
	int sign; 
	int len;    //to store length of a number
}Big_int;

//function to take big int as a input from user.....
void input_big_int(Big_int* opr,int opr_n);

//function to displsy the result 
void show_big_int(Big_int* opr);

//function to initialize big_int struct //similar to constructor in cpp...
void init_big_int(Big_int* opr);

//function for addition
void add(Big_int* opr1,Big_int* opr2,Big_int* result);

// functions used for substraction...

int magn_compare(Big_int* opr1,Big_int* opr2);

void magn_sub(Big_int* opr1,Big_int* opr2,Big_int* result);

void sub(Big_int* opr1,Big_int* opr2,Big_int* result);


//functions used for multiplication....

void mul(Big_int* opr1,Big_int* opr2,Big_int* result);

void magn_mul(Big_int* opr1,Big_int* opr2,Big_int* result);

void mul_with_dig(Big_int* opr1,int digit,Big_int* dig_mul,int dig_pos);

//extra helper functions required....
int char_to_int(char ch);

char int_to_char(int i);


#endif
