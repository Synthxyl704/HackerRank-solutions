#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Complete the following function.
void calculate_the_maximum(int upperLimit, int threshold) {
    // integer [n]
    // threshold / limit [k]
    
    // n = 3 (START FROM [1])
    // k = 3 (SUICIDE (b4) HERE)
    
    // n set = {1, 2, 3}
    // k set = {1, 2, !3 (because <3)}
    
    // 1 = 001
    // 2 = 010
    // 3 = 011
    
    // 1 2 AND = 0 | OR = 3 | XOR = 3
    // 1 3 AND = 1 | OR = 3 | XOR = 2
    // 2 3 ABD = 2 | OR = 3 | XOR = 1
    
    // so each pair will generate the triad of deez
    // we will keep track of each logical operator operation
    
    int maxBitwiseAnd = 0;
    int maxBitwiseOr  = 0;
    int maxBitwiseXor = 0;
    
    // since we will use 2 pairs, we will use nested for this
    // (1, 2) (1, 3) 
    // (2, 3) ===== (FN + 1)
    for (int firstNumber = 1; firstNumber <= upperLimit; firstNumber += 1) {
        for (int secondNumber = (firstNumber + 1); secondNumber <= upperLimit; secondNumber += 1) {
            int bitwiseAndValue = (firstNumber & secondNumber);
            int bitwiseOrValue  = (firstNumber | secondNumber);
            int bitwiseXorValue = (firstNumber ^ secondNumber);
            
            if ((bitwiseAndValue > maxBitwiseAnd) && (bitwiseAndValue < threshold)) {
                maxBitwiseAnd = bitwiseAndValue;
            }

            if (bitwiseOrValue > maxBitwiseOr && bitwiseOrValue < threshold) {
                maxBitwiseOr = bitwiseOrValue;
            }

            if (bitwiseXorValue > maxBitwiseXor && bitwiseXorValue < threshold) {
                maxBitwiseXor = bitwiseXorValue;
            }
        }
    }
    
    // printf("%d\n", maxBitwiseAnd);
    // printf("%d\n", maxBitwiseOr);
    // printf("%d\n", maxBitwiseXor);
}

int main() {
    int upperLimit, threshold;
  
    scanf("%d %d", &upperLimit, &threshold);
    calculate_the_maximum(upperLimit, threshold);
 
    return 0;
}
