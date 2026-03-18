#include <stdio.h>

int main() {
    int x = 2147483647; 
    
    printf("Было: %d\n", x);
    
    x = x + 1;  
    
    printf("Стало: %d\n", x);
    
    return 0;
}