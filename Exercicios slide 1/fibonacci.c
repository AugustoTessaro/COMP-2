#include <stdio.h>
#define first 1
#define second 1

int fibonacci(int n){
    int result;
    if(n == 1 || n == 2){
        return 1;
    }
    if(n == 2){
        return first + second;
    }
    
    result = fibonacci(n-1) + fibonacci(n-2); 
    
}


int main()
{
    int n, result;
   
  
    printf("%d", fibonacci(8));
    
    

    return 0;
}

