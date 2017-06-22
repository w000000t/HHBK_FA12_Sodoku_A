#include "../inc/Utils.h"

/**
Function: initExistingValuesArray
Parameters: existingValues, maxIndex
Return: -
Description: Fills the whole array with 0.
**/
void initExistingValuesArrays(int *existingValues, int maxIndex){
	int i;
	for(i = 0;i < maxIndex; i++){
		*(existingValues + i) = 0;
	}
}