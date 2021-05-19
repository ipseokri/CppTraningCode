#include<stdio.h>
#include<iostream>
#include<stdbool.h>
bool get_bit(int num, int i) {
   return ((num & (1 << i)) != 0);
}
int set_bit(int num, int i) {
   return num | (1 << i);
}
int clear_bit(int num, int i) {
   int mask = ~(1 << i);
   return (num & mask);
}


int main()
{
   int num = 0;
   num =set_bit(num, 0);
   num = set_bit(num, 1);
   num = set_bit(num, 2);
   printf("%x\n", num);
   num =clear_bit(num, 0);
   printf("%x\n", num);

   std::cout << (-3/8) << std::endl;
   return 0;
}