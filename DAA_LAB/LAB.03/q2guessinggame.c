/*write a program in C, A and B are playing a guessing game where B first thinks up an integer X 
(positive, negative or zero, and could be of arbitrarily large magnitude) and A tries to guess it.
In response to A’s guess, B gives exactly one of the following three replies:
a) Try a bigger number
b) Try a smaller number or
c) You got it.
Write a program by designing an efficient algorithm to minimize the number of guesses A has to
make. An example (not necessarily an efficient one) below:
Assume B thinks up the number 35.
A’s guess B’s response.
10 Try a bigger number
20 Try a bigger number
30 Try a bigger number
40 Try a smaller number
35 You got it*/

#include<stdio.h>
int main(){
    int n,a;
    printf("Enter the number that B thinks: \n");
    scanf("%d",&n);
    while(n!=a){
        printf("A is guessing: \n");
    scanf("%d",&a);
    if(n<a){
        printf("B:Try Smaller\n");
    }
    else if(n>a){
        printf("B:Try bigger\n");
    }
    else{
        printf("B:YOU GOT IT!!\n");
    }
   
}

return 0;
}