#include <iostream>

using namespace std;

//go through the array printing each value.
void printArray(double arrayToPrint[], int arrayLength)
{
	for (int i = 0; i < arrayLength; ++i)
	{
		cout << arrayToPrint[i] << ", ";
	}
	cout << "\n";
}

//sort the values in the array.
void sortValuesInArray(double arrayToSort[], int arrayLength)
{
	int currentValue;
	int currentPosition;

	//the array starts sorting from the second element, comparing elements to the previous in sequence.
	for (int i = 1; i < arrayLength; i++)
	{
		//currentValue will hold the current value of the array.  
		currentValue = arrayToSort[i];

		// currentPosition will hold the current position in the array.
		currentPosition = i;

		//as long as we don't reach the first element in the array and the previous element in the array is greater than the current
		//we will go through this loop. Essentially it keeps moving forward through the array until it reaches a value that is lower than
		//the previous value. When it gets such a value it will keep moving back through the area shifting each previous element forward one
		//until it finds the correct place in the array and places the element there.  
		while (currentPosition > 0 && arrayToSort[currentPosition - 1] > currentValue)
		{
			arrayToSort[currentPosition] = arrayToSort[currentPosition - 1];
			currentPosition--;
		}
		arrayToSort[currentPosition] = currentValue;
	}
}

//function attempts to find a specified value in the array. If it can it returns position in the array of that value, if not it returns -1.
int findValueInArray(double arrayToSearch[], int arrayLength, double valueToFind)
{
    //left position and right position are placed at the beginning and endpoints of the array.
    int leftPosition = 0;
    int rightPosition = arrayLength-1;
   
    //if left position does not pass right position the loop continues.  If the left position passes 
    //the right position, that means the value is not present and a -1 is returned.
	while (leftPosition <= rightPosition)
	{
	    //middlePosition is placed halfway between the left and right endpoints of the search.
	    int middlePosition = (leftPosition + rightPosition)/2;
	    
	    //if the middlePosition is lower than the valueToFind the left endpoint moves right past the middlePosition for the next loop.
	    //if the middlePosition is higher, the right endpoint moves left past middlePosition.
	    if (arrayToSearch[middlePosition] == valueToFind)
	    {
	        return middlePosition;
	    }
	    else if (arrayToSearch[middlePosition] < valueToFind)
	    {
	        leftPosition = middlePosition +1;
	    }
	    else 
	    {
	        rightPosition = middlePosition -1;
	    }
	}
	
	return -1;
}
	

int main()
{
	double numbers[7] = { -4,-1,-5,-16,77,8,-118 };
	int arrayLength = 7;
	double valueToFind;
	int findValuePosition;


	printArray(numbers, arrayLength);
	sortValuesInArray(numbers, arrayLength);
	printArray(numbers, arrayLength);
	cout << "Enter a value to find:\n";
	cin >> valueToFind;

	findValuePosition = findValueInArray(numbers, arrayLength, valueToFind);
	
	
	if (findValuePosition == -1)
	{
		cout << "No such value found.\n";
	}
	else
	{
		cout << valueToFind << " is located in position " << findValuePosition << " of the array.\n";
	}
}