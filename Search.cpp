#include <iostream> 
#include <algorithm>
#include <string>
#include <cstdio>
#include <ctime> 

using namespace std; 


void linearSearch(int A[], int B[], int size1, int size2){						//This is the function to use linear search
	cout << "Linear Search:" << endl;											//Linear Search is printed to the Screen
	clock_t startTime = clock();												//Starts the clock to measure the time of the algorithm
	bool counter = false;														//Counter is used to not print extra Nos when leaving the loop
	
	for(int i = 0; i < size2; i++){												//loop the values that are being searched for
		for(int j = 0; j < size1; j++){											//loop the values that are being searched through
			if(A[j] == B[i]){ 													//Check if values are equal
				cout << "Yes" << endl;											//Prints "Yes" if it is true
				counter = true;													//This eliminates a possible No
			}
		}
		if(counter == false){													//Checks if there was a "Yes"
			cout << "No" << endl;												//"No" is printed to the Screen
		}
		counter = false;														//Reinitializes counter
	}
  clock_t endTime = clock();													//Clock is stopped
  clock_t clockTicksTaken = endTime - startTime;								//Running time is evaluated
  double totalTime = clockTicksTaken / (double) CLOCKS_PER_SEC;					//Changes Clock time to regular seconds
  cout << "(" << totalTime << "sec" << ")" << endl;								//Prints the time to the Screen
}


void binarySearch(int A[],int B [], int size1, int size2){						//Function used for Binary Search
	cout << "Binary Search: " << endl;											//Prints Binary Search to the Screen
	sort(A, A + size1); 														//Sorts the array being searched
	clock_t startTime = clock();												//Clock time starts
	for (int i = 0; i < size2; i++){											//Loop the values that are being looked for
		int start = 0;															//Points to the beginning of the array
		int end = size1-1; 														//Points to the end of the array
		int searching;															//Points to the middle value of the array
		bool counter = false;													//Counter used to stop extra Nos

		while(start <= end){													//Loop used to half the array in half
			searching = (start+end)/2;											//Points to the middle value of the array
			if(B[i]==A[searching]&&counter==false){								//If the values are equal then print
				cout<<"Yes"<<endl;												//Prints "Yes" to the Screen
				counter = true;													//Counter is set to true
			}
			else if(B[i] > A[searching]){										//Is value greater than the middle section
				start = searching+1;											//Cut the lower half of the array
			}
			else{
				end = searching-1;												//Cut the higher half of the array
			}
			
		}
		if(counter == false){													//Counter used to close off the extra No 
			cout << "No" << endl;
		}
		counter = false;														//Reinitializes the counter value
	}
	
	clock_t endTime = clock();													//Clock Stops
	clock_t clockTicksTaken = endTime - startTime;								//Clock time is evaluated
	double totalTime = clockTicksTaken / (double) CLOCKS_PER_SEC;				//Clock time is changed to seconds
	cout << "(" << totalTime << "sec" << ")" << endl;							//Seconds are printed out to the Screen
}

int main(){
	
	//Variable Declaration
	int size1;																	//Size1 is amount number elements
	int	size2;																	//Size2 is amount search number elements
	cin >> size1;
	cin >> size2;

	int A[size1]; 																//Elements array
	int B[size2]; 																//Search numbers array
	
	for(int i= 0; i <size1; i++){ 												//Loads values in to the Elements Array
		cin >> A[i];
	}
	
	for(int j = 0; j<size2; j++){
		cin >> B[j];
	}

	linearSearch(A, B, size1, size2);											//Starts the Linear Search
	binarySearch(A,B, size1, size2);											//Starts the Binary Search
	
	return 0;
}






