#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <string.h>

//global variables
int Arr[8] = {3, 1, 6, 2, 7, 4, 8, 5};

int mergeArr[8];
int mergeSize = 8;
int mergeOrder = 1; // 1 for ascending, 2 for descending

int quickSortOrder;//quick sort

int tryAgain();
int exitf();

//merge sort sub function
void printSegment(int start, int end);
void mergeArrays(int left, int mid, int right);
void mergeSortRecursive(int left, int right, int depth);

void shellSortVisual(int n, int order);//shell sort sub function

//quick sort sub function
void displayArray(int arr[], int size, int left, int right, int pivot, int leftPtr, int rightPtr);
int partition(int arr[], int left, int right);
void recursion(int arr[], int left, int right, int depth);


//sorting algos for binary search
void insertion_Binary(int arr[]);
void selection_Binary(int a[]);
void bubble_Binary(int a[]);

void insertion();
void selection();
void bubble();
void merge();
void shell();
void quick();

void linear();
void binary();

void sort();
void search();


int main(){
	
	int choice;
	printf("====WELCOME TO ALGORITHM MENU PROGRAM====\n");
	do{
		printf("\n======MAIN MENU======\n\n");
		printf("1. Sorting\n");
		printf("2. Searching\n");
		printf("3. Exit\n\n");
		printf("Your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				sort();
				break;
			case 2:
				search();
				break;
			case 3:
				if(exitf() == 0){
					return 0;
				}
				break;
			default:
				printf("\nInvalid Choice! Please try again.\n");
				sleep(1);
				system("cls");
		}	
		
	}while(1);
	
	return 0;
}

int tryAgain(){
	char yn;
	
	printf("Do you wish to try again? (y/n): ");
	scanf(" %c", &yn);
	
	if(yn == 'Y' || yn == 'y'){
		printf("Returning...\n\n");
		sleep(1);
		system("cls");
		return 1;
	}else if(yn == 'N' || yn == 'n'){
		printf("\n\nExiting...\n\n");
		sleep(1);
		system("cls");
		return 0;
	}else{
		printf("\nInvalid choice!\n\nReturning...\n\n");
		sleep(1);
		system("cls");
		return 1;
	}
}

int exitf(){
	char yn;
	
	printf("\nDo you wish to exit (y/n): ");
	scanf(" %c", &yn);
	
	if(yn == 'Y' || yn == 'y'){
		printf("\n\nExiting...\n\n");
		sleep(1);
		return 0;
	}else if(yn == 'N' || yn == 'n'){
		printf("\n\nOkay.\n\nReturning...\n\n"); 
		sleep(1);
		system("cls");
		return 1;
	}else{
		printf("\n\nInvalid choice!\n\nReturning...\n\n"); // return to menu by default since user did not say yes
		sleep(1);
		system("cls");
		return 1;
	}	
}


//insertion sort for binary search
void insertion_Binary(int arr[]){
	int ord;
	
	printf("\n====INSERTION SORT====\n");
	
	
		printf("\nChoose your sorting order\n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ord);
		
		if(ord != 1 && ord != 2){
			printf("Invalid choice. Defaulting to ascending order\n\n");
			ord = 1;
		}
		
		printf("\nYour array: \n|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", arr[i]);
		}
		printf("\n\n");
		
		
		for(int j = 1; j <= 7; j++){
			int key = arr[j];
			int k = j - 1;
			sleep(1);
			printf("Pass %d: Key = %d (from index %d)\n", j, key, j);
			printf("\x1b[33mComparing %d with sorted portion...\x1b[0m\n\n", key);
			
			// Show the key being picked
			sleep(1);
			printf("Before insertion:\n|");
			for(int h = 0; h <= 7; h++){	
				if(h == j){
					printf(" \x1b[33m<%d> \x1b[0m|", arr[h]);  //key
				} else if(h < j){
					printf(" \x1b[32m[%d] \x1b[0m|", arr[h]);  //sorted
				} else {
					printf("  %d  |", arr[h]);  //unsorted
				}
			}
			printf("\n");
	
			// Store original position for comparison display
			int originalPos = j;
			int shifts = 0;
			
			if(ord == 1){//ascedning
				while(k >= 0 && arr[k] > key){
					arr[k + 1] = arr[k];
					k--;
					shifts++;
				}
			} else {  //descendign
				while(k >= 0 && arr[k] < key){
					arr[k + 1] = arr[k];
					k--;
					shifts++;
				}
			}
			
			arr[k + 1] = key;
			
			if(shifts > 0){
				printf("\ninsert %d at index %d\n", key, k + 1); //prints what needs to be inserted before printing the sorted array per pass
			}
			
			//sorted array after each pass
			sleep(1);
			printf("\nAfter insertion:\n|");
			for(int h = 0; h <= 7; h++){
				if(h <= j){
					printf(" \x1b[32m[%d] \x1b[0m|", arr[h]);  //sorted
				} else {
					printf("  %d  |", arr[h]);
				}
			}	

			printf("\n-------------------------------------------------------\n\n");//divide
		}
}





void insertion(){
	system("cls");
	int unsort[8] = {3, 1, 6, 2, 7, 4, 8, 5};
	int Arr[8];
	int ord;
	
	do{
		printf("\n====INSERTION SORT====\n\n");
		memcpy(Arr, unsort, sizeof(Arr));//reset array
		printf("|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", Arr[i]);
		}
		printf("\n");
		printf("\nChoose your sorting order\n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ord);
		
		if(ord != 1 && ord != 2){
			printf("Invalid choice. Defaulting to ascending order\n\n");
			ord = 1;
		}
		
		printf("\nYour array: \n|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", Arr[i]);
		}
		printf("\n\n");
		
		for(int j = 1; j <= 7; j++){
			int key = Arr[j];
			int k = j - 1;
			sleep(1);
			printf("Pass %d: Key = %d (from index %d)\n", j, key, j);
			printf("\x1b[33mComparing %d with sorted portion...\x1b[0m\n\n", key);
			
			// Show the key being picked
			sleep(1);
			printf("Before insertion:\n|");
			for(int h = 0; h <= 7; h++){
				if(h == j){
					printf(" \x1b[33m<%d> \x1b[0m|", Arr[h]);  //key
				} else if(h < j){
					printf(" \x1b[32m[%d] \x1b[0m|", Arr[h]);  //sorted
				} else {
					printf("  %d  |", Arr[h]);  //unsorted
				}
			}
			printf("\n");
	
			// Store original position for comparison display
			int originalPos = j;
			int shifts = 0;
			
			if(ord == 1){//ascedning
				while(k >= 0 && Arr[k] > key){
					Arr[k + 1] = Arr[k];
					k--;
					shifts++;
				}
			} else {  //descendign
				while(k >= 0 && Arr[k] < key){
					Arr[k + 1] = Arr[k];
					k--;
					shifts++;
				}
			}
			
			Arr[k + 1] = key;
			
			if(shifts > 0){
				printf("\ninsert %d at index %d\n", key, k + 1); //prints what needs to be inserted before printing the sorted array per pass
			}
			
			//sorted array after each pass
			sleep(1);
			printf("\nAfter insertion:\n|");
			for(int h = 0; h <= 7; h++){
				if(h <= j){
					printf(" \x1b[32m[%d] \x1b[0m|", Arr[h]);  //sorted
				} else {
					printf("  %d  |", Arr[h]);
				}
			}	

			printf("\n-------------------------------------------------------\n\n");//divide
		}
		//final sorted array
		sleep(1);
		printf("===SORTED ARRAY===\n|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", Arr[i]);
		}	
		printf("\n\n");
	}while(tryAgain() == 1);
	system("cls");
}
	

//selection sort for binary search
void selection_Binary(int a[]){
	int i, j, min, temp, ord;
	
	printf("\n====SELECTION SORT====\n");
	

		printf("\nChoose your sorting order\n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ord);
		
		if(ord != 1 && ord != 2){
			printf("Invalid choice. Defaulting to ascending order\n\n");
			ord = 1;//ord = 1 means ascending
		}
	
		printf("\nYour array:\n|");
		for(i=0; i<=7; i++) 
			printf("  %d  |", a[i]);
		printf("\n\n");
	
		for(i=0; i<=7; i++){
			min = i;
			
			//prints each pass
			sleep(1);
			printf("\nPass %d:\n", i);
			
			if(ord == 1){//ascending
				for(j=i+1; j<=7; j++)
					if(a[j] < a[min]) 
						min = j;
			}else{//descending
				for(j=i+1; j<=7; j++)
					if(a[j] > a[min]) 
						min = j;
			}
			
			// Show which element was selected
			printf("Selected: %d at index %d\n", a[min], min);
			
			if(min != i){
				printf("Swapping \x1b[33m%d (index %d) \x1b[0mwith \x1b[33m%d (index %d)\x1b[0m\n", 
					a[i], i, a[min], min);
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
			} else {
				printf("Already in correct position\n");
			}
			
			// Display array with visual indicator for sorted portion
			sleep(1);
			printf("|");
			for(int k=0; k<=7; k++){
				if(k <= i){
					// Sorted portion - could add a marker
					printf(" \x1b[32m[%d] \x1b[0m|", a[k]);
				} else {
					printf("  %d  |", a[k]);
				}
			}
			printf("\n");
		}
		
		sleep(1);
		printf("\n\n===Sorted array===\n|");
		for(i=0; i<=7; i++){
			printf("  %d  |", a[i]);
		}
		printf("\n\n");
	
}





void selection(){
system("cls");
	
int i, j, min, temp, ord;
int unsort[8] = {3, 1, 6, 2, 7, 4, 8, 5};
int Arr[8];
	
	do{
		memcpy(Arr, unsort, sizeof(Arr));
		printf("\n====SELECTION SORT====\n\n");
		printf("|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", Arr[i]);
		}	
		printf("\nChoose your sorting order\n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ord);
		
		if(ord != 1 && ord != 2){
			printf("Invalid choice. Defaulting to ascending order\n\n");
			ord = 1;//ord = 1 means ascending
		}
	
		printf("\nYour array:\n|");
		for(i=0; i<8; i++) 
			printf("  %d  |", Arr[i]);
		printf("\n\n");
	
		for(i=0; i<=7; i++){
			min = i;
			
			//prints each pass
			sleep(1);
			printf("\nPass %d:\n", i);
			
			if(ord == 1){//ascending
				for(j=i+1; j<8; j++)
					if(Arr[j] < Arr[min]) 
						min = j;
			}else{//descending
				for(j=i+1; j<8; j++)
					if(Arr[j] > Arr[min]) 
						min = j;
			}
			
			// Show which element was selected
			printf("Selected: %d at index %d\n", Arr[min], min);
			
			if(min != i){
				printf("Swapping \x1b[33m%d (index %d) \x1b[0mwith \x1b[33m%d (index %d)\x1b[0m\n", 
					Arr[i], i, Arr[min], min);
				temp = Arr[i];
				Arr[i] = Arr[min];
				Arr[min] = temp;
			} else {
				printf("Already in correct position\n");
			}
			
			// Display array with visual indicator for sorted portion
			sleep(1);
			printf("|");
			for(int k=0; k<8; k++){
				if(k <= i){
					//sorted portion - could add a marker
					printf(" \x1b[32m[%d] \x1b[0m|", Arr[k]);
				} else {
					printf("  %d  |", Arr[k]);
				}
			}
			printf("\n");
		}
	
		sleep(1);
		printf("\n\n===Sorted array===\n|");
		for(i=0; i<8; i++){
			printf("  %d  |", Arr[i]);
		}
		printf("\n\n");
	}while(tryAgain() == 1);
}



void bubble_Binary(int a[]){
	int i, j, temp, ord;
	int original[8] = {3, 1, 6, 2, 7, 4, 8, 5};
	
	printf("\n====BUBBLE SORT====\n");
	
		// Reset array to original values
	
		for(i = 0; i <8; i++){
			a[i] = original[i];
		}
		
		printf("\nChoose your sorting order\n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ord);
		
		if(ord != 1 && ord != 2){
			printf("Invalid choice. Defaulting to ascending order\n\n");
			ord = 1;
		}
	
		printf("\nYour array:\n|");
		for(i=0; i<8; i++) 
			printf("  %d  |", a[i]);
		printf("\n\n\n");
	
		for(i=0; i<8; i++){
			sleep(1);
			printf("\n\n===================== Pass %d =====================\n\n", i+1);
			
			for(j=0; j<8-i-1; j++){				
				// Display array with highlighted comparison
				printf("|");
				for(int k=0; k<8; k++){
					if(k == j || k == j+1){
						printf(" \x1b[33m<%d> \x1b[0m|", a[k]);  //keys that needs to swap kinesoo
					} else if(k >= 7-i){
						printf(" \x1b[32m[%d] \x1b[0m|", a[k]);  //sorted
					} else {
						printf("  %d  |", a[k]); //unsorted
					}
				}

				printf("\n");
				
				//check if swap is needed
				sleep(1);
				int needSwap = 0;
				if(ord == 1){
					if(a[j] > a[j+1]){//ascending
						needSwap = 1;
						printf("\x1b[33m%d > %d: Swapping...\x1b[0m\n\n", a[j], a[j+1]);
						temp = a[j];//swap the number in order (ascending)
						a[j] = a[j+1];
						a[j+1] = temp;
					} else {
						printf("\x1b[32m%d < %d: Already in correct order\x1b[0m\n\n", a[j], a[j+1]);//if in order no index is changed
					}
				}else{//descending
					if(a[j] < a[j+1]){
						needSwap = 1;
						printf("\x1b[33m%d < %d: Swapping...\x1b[0m\n\n", a[j], a[j+1]);
						temp = a[j];
						a[j] = a[j+1];
						a[j+1] = temp;//swap the number by order (ascending)
					} else {
						printf("\x1b[32m%d > %d: Already in correct order\x1b[0m\n", a[j], a[j+1]);//if in order no index is changed
					}
				}	
				
				if(needSwap){
					sleep(1);
					printf("\n\nAfter swap:\n|");
					for(int k=0; k<=7; k++){
						if(k >= 7-i){
							printf(" \x1b[1;32m[%d] \x1b[0m|", a[k]);//sorted array
						} else {
							printf("  %d  |", a[k]);//unsorted
						}
					}
					printf("\n\n--------------------------------------------------\n\n");
				}
			}
		}
}



void bubble(){
	system("cls");
	int i, j, temp, ord;
	int unsort[8] = {3, 1, 6, 2, 7, 4, 8, 5};	
	int Arr[8];
	
	
	do{
		printf("\n====BUBBLE SORT====\n");	
		memcpy(Arr, unsort, sizeof(Arr));    
		printf("|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", Arr[i]);
		}
		printf("\n");                          
		printf("\nChoose your sorting order\n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("\nEnter your choice: ");
		scanf("%d", &ord);
		
		if(ord != 1 && ord != 2){
			printf("Invalid choice. Defaulting to ascending order\n\n");
			ord = 1;
		}
	
		printf("\nYour array:\n|");
		for(i=0; i<=7; i++) 
			printf("  %d  |", Arr[i]);
		printf("\n\n\n");
	
		for(i=0; i<=7; i++){
			sleep(1);
			printf("\n\n===================== Pass %d =====================\n\n", i+1);
			
			for(j=0; j<=7-i-1; j++){				
				// Display array with highlighted comparison
				printf("|");
				for(int k=0; k<=7; k++){
					if(k == j || k == j+1){
						printf(" \x1b[33m<%d> \x1b[0m|", Arr[k]);  //keys that needs to swap kinesoo
					} else if(k >= 7-i){
						printf(" \x1b[32m[%d] \x1b[0m|", Arr[k]);  //sorted
					} else {
						printf("  %d  |", Arr[k]); //unsorted
					}
				}

				printf("\n");
				
				//check if swap is needed
				int needSwap = 0;
				sleep(1);
				if(ord == 1){
					
					if(Arr[j] > Arr[j+1]){//ascending
						needSwap = 1;
						printf("\x1b[33m%d > %d: Swapping...\x1b[0m\n\n", Arr[j], Arr[j+1]);
						temp = Arr[j];//swap the number in order (ascending)
						Arr[j] = Arr[j+1];
						Arr[j+1] = temp;
					} else {
						printf("\x1b[32m%d < %d: Already in correct order\x1b[0m\n", Arr[j], Arr[j+1]);//if in order no index is changed
					}
				}else{//descending
					if(Arr[j] < Arr[j+1]){
						needSwap = 1;
						printf("\x1b[33m%d < %d: Swapping...\x1b[0m\n\n", Arr[j], Arr[j+1]);
						temp = Arr[j];
						Arr[j] = Arr[j+1];
						Arr[j+1] = temp;//swap the number by order (ascending)
					} else {
						printf("\x1b[32m%d > %d: Already in correct order\x1b[0m\n", Arr[j], Arr[j+1]);//if in order no index is changed
					}
				}
	
				
				
				if(needSwap){
					sleep(1);
					printf("\nAfter swap:\n\n|");
					sleep(1);
					for(int k=0; k<=7; k++){
						if(k >= 7-i){
							printf(" \x1b[32m[%d] \x1b[0m|", Arr[k]);//sorted array
						} else {
							printf("  %d  |", Arr[k]);//unsorted
						}
					}
					printf("\n\n--------------------------------------------------\n\n");
				}
			}
		}
		sleep(1);
		printf("\n===SORTED ARRAY===\n|");
		for(i=0; i<=7; i++){
			printf("  %d  |",Arr[i]);
		}
		printf("\n\n");
	}while(tryAgain() == 1);
	system("cls");
}

//Merge sort parts
void printArray(int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d", Arr[i]);
        if (i < end) printf(", ");
    }
}



//sub merge function to print array segment
void printSegment(int start, int end) {
    printf("|");
    for(int i = start; i <= end; i++) {
        printf("  %d  |", mergeArr[i]);
    }
}

//sub merge function with clear visualization
void mergeArrays(int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];//temp arrays
    
    //copy data to temp arrays
    for(int i = 0; i < n1; i++)
        L[i] = mergeArr[left + i];
    for(int j = 0; j < n2; j++)
        R[j] = mergeArr[mid + 1 + j];
    
    //print the two arrays being merged
    sleep(1);
	printf("\n--------------------------------------------------\n");
    printf("\n\x1b[32mMerging \x1b[0m");
    printf("|");
    for(int i = 0; i < n1; i++)
        printf("  %d  |", L[i]);
    printf(" and ");
    printf("|");
    for(int i = 0; i < n2; i++){             
        printf("  %d  |", R[i]);
	}
	printf("\n\n");
    
    //merge the temp arrays back
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        if(mergeOrder == 1) { //ascending
            if(L[i] <= R[j]) {
                mergeArr[k] = L[i];
                i++;
            } else {
                mergeArr[k] = R[j];
                j++;
            }
        } else { //descending
            if(L[i] >= R[j]) {
                mergeArr[k] = L[i];
                i++;
            } else {
                mergeArr[k] = R[j];
                j++;
            }
        }
        k++;
    }
    
    //copy remaining elements
    while(i < n1) {
        mergeArr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        mergeArr[k] = R[j];
        j++;
        k++;
    }  
    //print merged result
    printf("        ");
    printSegment(left, right);
    printf("\n\n");
}

//recursive merge sort with splitting visualization
void mergeSortRecursive(int left, int right, int depth) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        //prints splitting information
        if(right - left > 0) {
            // Indentation based on depth
            for(int i = 0; i < depth; i++)
                printf("  ");
            sleep(1);
            printf("\x1b[33mSplitting: \x1b[0m");
            printSegment(left, right);
            printf("\n             ");
            sleep(1);
            printSegment(left, mid);
            printf(" and ");
            printSegment(mid + 1, right);
            printf("\n\n");
        }
        
        //recursively sort left and right halves
        mergeSortRecursive(left, mid, depth + 1);
        mergeSortRecursive(mid + 1, right, depth + 1);
        
        // Merge the sorted halves
        if(right - left > 0) {
            for(int i = 0; i < depth; i++)
                printf("  ");
            mergeArrays(left, mid, right);
        }
    }
}

//Main merge sort function
void merge() {
	system("cls");
    
    
    do {
    	printf("\n====MERGE SORT====\n\n");
        //reset array
        int original[8] = {3, 1, 6, 2, 7, 4, 8, 5};
        for(int i = 0; i < 8; i++) {
            mergeArr[i] = original[i];
        }
        printf("|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", original[i]);
		}
        
        int choice;
        printf("\n\nChoose your sorting order\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        if(choice != 1 && choice != 2) {
            printf("Invalid choice. Defaulting to ascending order\n\n");
            choice = 1;
        }
        
        sleep(1);
        mergeOrder = choice;
        
        printf("\n=== PROCESSING MERGE SORT ===\n\n");
        
        sleep(1);
        printf("Original array: ");
        printSegment(0, 7);
        printf("\n\n");
        
        sleep(1);
        printf("--- SPLITTING PHASE ---\n\n");
        mergeSortRecursive(0, 7, 0);
        
        sleep(1);
        printf("\n===========SORTED ARRAY===========\n");
        printSegment(0, 7);
        printf("\n\n");
        
    } while(tryAgain() == 1);
    system("cls");
}


//shell Sort visualization function - sub shell function
void shellSortVisual(int n, int order) {
    int gap, i, j, temp;
    int step = 1;
    int condition;


    for (gap = n / 2; gap > 1; gap /= 2) {  //changed condition to gap > 1
    	
    	sleep(1);
        printf("\n\x1b[33m==============================\n");
        printf(" GAP = %d\n", gap);
        printf("==============================\x1b[0m\n");

        //show the current array
        printf("\n|");
        for(int k = 0; k < n; k++) {
            printf("  %d  |", Arr[k]);
        }
        printf("\n");

        //show sublists formed by this gap
        sleep(1);
        printf("\nSublists formed:\n");
        for(int start = 0; start < gap; start++) {
            printf("{");
            for(int k = start; k < n; k += gap) {
                printf("%d", Arr[k]);
                if(k + gap < n) printf(", ");
            }
            printf("}");
            if(start < gap - 1) printf(", ");
        }
        printf("\n");

        //visual representation of sublists (like the image)
        printf("\n");
        for(int start = 0; start < gap; start++) {
            // Print array positions
            printf("|");
            for(int k = 0; k < n; k++) {
                if((k - start) % gap == 0) {
                    printf("  %d  |", Arr[k]);
                } else {
                    printf("     |");
                }
            }
            printf("\n");
        }
        
        //show the grouped elements below
        printf("\n");
        int row = 0;
        for(int start = 0; start < gap; start++) {
            //calculate how many elements in this sublist
            int count = 0;
            for(int k = start; k < n; k += gap) {
                count++;
        	}
        }
        printf("\n");

        //perform gapped insertion sort
        for (i = gap; i < n; i++) {
            temp = Arr[i];
            j = i;

            //compare and shift elements
            if(order == 1) {
                condition = (j >= gap && Arr[j - gap] > temp);
            } else {
                condition = (j >= gap && Arr[j - gap] < temp);
            }

            while(j >= gap) {
                if (order == 1)
                    condition = Arr[j - gap] > temp;
                else
                    condition = Arr[j - gap] < temp;

                if (condition) {
                    Arr[j] = Arr[j - gap];
                    j -= gap;
                } else {
                    break;
                }
            }
            Arr[j] = temp;
        }

        //show array after this gap pass
        sleep(1);
        printf("\nArray after gap %d:\n|", gap);
        for(int k = 0; k < n; k++) {
            printf("  %d  |", Arr[k]);
        }
        printf("\n");
    }

    //final pass with gap = 1 using insertion sort visualization
    printf("\n\x1b[33m=============================================\n");
    printf("   GAP = 1 (Final Pass - Insertion Sort)\n");
    printf("==============================================\x1b[0m\n");
    printf("\nArray before final sort:\n|");
    for(int k = 0; k < n; k++) {
        printf("  %d  |", Arr[k]);
    }

}

//main shell function
void shell() {
	system("cls");
    int order;
    
    do {
        //reset array 
        int original[8] = {3, 1, 6, 2, 7, 4, 8, 5};
        for(int i = 0; i < 8; i++) {
            Arr[i] = original[i];
        }
        printf("\n====SHELL SORT====\n\n");
		printf("|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", original[i]);
		}
        printf("\n");
        printf("\nChoose sorting order:\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("\nEnter choice: ");
        scanf("%d", &order);

        //validate choice
        if (order != 1 && order != 2) {
            printf("Invalid choice! Defaulting to ascending.\n");
            order = 1;
        }

        printf("\nYour array:\n|");
        for(int i = 0; i < 8; i++) {
            printf("  %d  |", Arr[i]);
        }
        printf("\n");

        //call Shell Sort visualization function
        sleep(1);
        shellSortVisual(8, order);
        
        printf("\n\n\n\n====INSERTION SORT====\n\n");

	    //use insertion sort logic for the final pass
	    for(int j = 1; j < 8; j++) {
	        int key = Arr[j];
	        int k = j - 1;
	        
	        sleep(1);
	        printf("Pass %d: Key = %d (from index %d)\n", j, key, j);
	        printf("\x1b[33mComparing %d with sorted portion...\x1b[0m\n\n", key);
	        
	        // Show the key being picked
	        sleep(1);
	        printf("Before insertion:\n|");
	        for(int h = 0; h < 8; h++) {
	            if(h == j) {
	                printf(" \x1b[33m<%d> \x1b[0m|", Arr[h]);  // key
	            } else if(h < j) {
	                printf(" \x1b[32m[%d] \x1b[0m|", Arr[h]);  // sorted
	            } else {
	                printf("  %d  |", Arr[h]);  // unsorted
	            }
	        }
	        printf("\n");
	
	        int shifts = 0;
	        
	        if(order == 1) {  // ascending
	            while(k >= 0 && Arr[k] > key) {
	                Arr[k + 1] = Arr[k];
	                k--;
	                shifts++;
	            }
	        } else {  // descending
	            while(k >= 0 && Arr[k] < key) {
	                Arr[k + 1] = Arr[k];
	                k--;
	                shifts++;
	            }
	        }
	        
	        Arr[k + 1] = key;
	        
	        if(shifts > 0) {
	            printf("\nInsert %d at index %d\n", key, k + 1);
	        }
	        
	        //shhow array after insertion
	        sleep(1);
	        printf("\nAfter insertion:\n|");
	        for(int h = 0; h < 8; h++) {
	            if(h <= j) {
	                printf(" \x1b[32m[%d] \x1b[0m|", Arr[h]);  // sorted
	            } else {
	                printf("  %d  |", Arr[h]);  // unsorted
	            }
	        }
	        printf("\n-------------------------------------------------------\n\n");
	    }

	    //print final sorted array
	    sleep(1);
	    printf("===SORTED ARRAY===\n|");
	    for(int i = 0; i < 8; i++) {
	        printf("  %d  |", Arr[i]);
	    }
	    printf("\n\n");
	        
	    } while(tryAgain() == 1);
	    system("cls");
}              



void displayArray(int arr[], int size, int left, int right, int pivot, int leftPtr, int rightPtr) {
    printf("|");
    for(int i = 0; i < size; i++) {
        if(i == pivot) {
            printf(" \x1b[32m[%d] \x1b[0m|", arr[i]);  //pivot element
        } else if(i == leftPtr || i == rightPtr) {
            printf(" \x1b[33m<%d> \x1b[0m|", arr[i]);  //elements to be swapped
        } else if(i >= left && i <= right) {
            printf("  %d  |", arr[i]);  //unsorted elements in the ppartition
        } else {
            printf(" \x1b[36m(%d) \x1b[0m|", arr[i]);  //sorted elements
        }
    }
    printf("\n");
}

//partition functionzzzz
int partition(int arr[], int left, int right) {
    int pivot = arr[right];  // Choose rightmost element as pivot
    int leftPtr = left;
    int rightPtr = right - 1;
    
    //prints out partition per pass
    sleep(1);
    printf("\n\x1b[33m--- PARTITION ---\x1b[0m\n");
    printf("Pivot = %d (at index %d)\n", pivot, right);
    printf("Left boundary = %d, Right boundary = %d\n\n", left, right);
    
    displayArray(arr, 8, left, right, right, leftPtr, rightPtr);
    
    while(1) {
        //Move leftptr right while elements are less than pivot (ascending)
        //or greater than pivot (descending)
        if(quickSortOrder == 1) {  //ascending
            while(leftPtr <= right && arr[leftPtr] < pivot) {
                leftPtr++;
            }
        } else {  //descending
            while(leftPtr <= right && arr[leftPtr] > pivot) {
                leftPtr++;
            }
        }
        
        //Move rightptr left while elements are greater than pivot (ascending)
        // or less than pivot (descending)
        if(quickSortOrder == 1) {  //ascending
            while(rightPtr >= left && arr[rightPtr] > pivot) {
                rightPtr--;
            }
        } else {  //descending
            while(rightPtr >= left && arr[rightPtr] < pivot) {
                rightPtr--;
            }
        }
        
        //Check if pointers have crossed
        if(leftPtr >= rightPtr) {
            break;
        }
        
        //swap elements to the left pointer
        sleep(1);
        printf("Left pointer at index %d = %d\n", leftPtr, arr[leftPtr]);
        printf("Right pointer at index %d = %d\n", rightPtr, arr[rightPtr]);
        sleep(1);
        printf("Swapping %d and %d\n\n", arr[leftPtr], arr[rightPtr]);
        
        int temp = arr[leftPtr];
        arr[leftPtr] = arr[rightPtr];
        arr[rightPtr] = temp;
        
        sleep(1);
        displayArray(arr, 8, left, right, right, leftPtr, rightPtr);
    }
    
    //place pivot in its final position
    printf("Pointers crossed! Placing pivot...\n");
    printf("Swapping pivot %d with element at index %d = %d\n\n", pivot, leftPtr, arr[leftPtr]);
    
    int temp = arr[leftPtr];
    arr[leftPtr] = arr[right];
    arr[right] = temp;
    
    sleep(1);
    displayArray(arr, 8, left, right, leftPtr, -1, -1);
    printf("Pivot %d is now at its correct position (index %d)\n", arr[leftPtr], leftPtr);
    
    return leftPtr;
}

//recursive function within quick() function
//starts yung mismong quick sort
void recursion(int arr[], int left, int right, int depth) {
    if(left < right) {
    	sleep(1);
        printf("\n========================================\n");
        printf("RECURSION DEPTH %d: Sorting from index %d to %d\n", depth, left, right);//prints out kung saan sa array yung recursion
        printf("========================================\n");
        
        //partition array
        int pivotIndex = partition(arr, left, right);//ilalagay ung pivot sa partition
        
        sleep(1);
        printf("\n--- After partition ---\n");
        printf("|");
        for(int i = 0; i < 8; i++) {
            if(i == pivotIndex) {
                printf(" \x1b[32m[%d] \x1b[0m|", arr[i]);  //pivot when its in correct position
            } else {
                printf("  %d  |", arr[i]); //unsorted arrsy
            }
        }      
        printf("\n\n");
        
        //sorting recursion in left partition
        sleep(1);
        if(left < pivotIndex - 1) {
            printf("Sorting LEFT partition (index %d to %d)\n", left, pivotIndex - 1);
            recursion(arr, left, pivotIndex - 1, depth + 1);
        }
        
        // Recursively sort right partition
        if(pivotIndex + 1 < right) {
            printf(">> Sorting RIGHT partition (index %d to %d)\n", pivotIndex + 1, right);
            recursion(arr, pivotIndex + 1, right, depth + 1);
        }
    }
}

//quick sort function
void quick() {
	system("cls");
    int arr[8] = {3, 1, 6, 2, 7, 4, 8, 5};
    int ord;
    
    
    do {
        // Reset array
        int original[8] = {3, 1, 6, 2, 7, 4, 8, 5};
        for(int i = 0; i < 8; i++) {
            arr[i] = original[i];
        }
        printf("\n====QUICK SORT====\n\n");
		printf("|");
		for(int i = 0; i <= 7; i++){
			printf("  %d  |", Arr[i]);
		}
		printf("\n");
        
        printf("\nChoose your sorting order\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ord);
        
        if(ord != 1 && ord != 2) {
            printf("Invalid choice. Defaulting to ascending order\n\n");
            ord = 1;
        }
        
        quickSortOrder = ord;  // Set global order variable
        
        printf("\nYour array:\n|");
        for(int i = 0; i < 8; i++) {
            printf("  %d  |", arr[i]);
        }
        printf("\n");
        
        //Start quick sort
        sleep(1);
        recursion(arr, 0, 7, 1);
        
        //sorted array after ng recursions
        sleep(1);
        printf("\n========================================\n\n");
        printf("===SORTED ARRAY===\n|");
        for(int i = 0; i < 8; i++) {
            printf("  %d  |", arr[i]);
        }
        printf("\n\n=========================================\n\n");
        
    } while(tryAgain() == 1);//allows user to try ascending or descending again4
    system("cls");
}


void linear(){
	system("cls");
	
	int Arr[8] = {5,4,8,2,7,6,1,3};
	int num;
	do{                    
			
			printf("\n====LINEAR SERACH====\n");
			printf("\nYour array:\n|");
			for(int i = 0; i <= 7; i++){
				printf("  %d  |", Arr[i]);
			}
			printf("\nWhat number do you want to find?: ");
			scanf("%d", &num);
		
			
			
			int found = 0;
			for(int i = 0; i <= 7; i++){
				sleep(1);
				printf("\n\nPass no. %d", i+1);//print Pass no 1 and such kada pag print sa array (i loop)
				printf(" -> %d at index %d\n|", Arr[i], i);//value of each index per pass (i loop)
				for(int j = 0; j <= 7; j++){
					printf("  %d  |", Arr[j]);//print the complete array for each pass (j loop)
				}
				printf("\n");//new line for Pass 1 and such to print
				
				for(int k = 0; k < i; k++){
					printf("      "); //space for Pass 1 abd such to align to each array (k loop)
				}
					if(Arr[i] == num){//conditional statement (i loop)
						printf("\x1b[32m%d \x1b[0mMatch", num);
						sleep(0.3);
						printf("\n\n\n\x1b[32m%d is located at index %d\x1b[0m", num, i);
						found = 1;
						break;//if may nag match stop the for loop
					}else{
						printf("\x1b[33m%d \x1b[0mNot Match", num);
					}
			}
			if(!found){
				printf("\n\x1b[31m%d is not on the list!\x1b[0m\n", num);
			}
			printf("\n\n");
		
			
	}while(tryAgain() == 1);
	
	system("cls");
}



void binary(){
	int Arr[8] = {3, 1, 6, 2, 7, 4, 8, 5};
	system("cls");
	int num, alg;

	printf("\nYour array:\n|");
	for(int i = 0; i < 8; i++)
		printf("  %d  |", Arr[i]);
	printf("\n");

	printf("\nSort your array before using binary search\n");
	printf("1. Insertion\n");
	printf("2. Selection\n");
	printf("3. Bubble\n");
	printf("4. Go back\n");
	printf("\nChoose your sorting algorithm: ");
	scanf("%d", &alg);

	switch(alg){
		case 1:
			insertion_Binary(Arr);
			break;
		case 2:
			selection_Binary(Arr);
			break;
		case 3:
			bubble_Binary(Arr);
			break;
		case 4:
			printf("\n\nExiting...\n\n");
			sleep(1);
			system("cls");
			return;
			break;
		default:
			printf("\nInvalid choice! Defaulting to insertion sort...\n");
	}

	int isAsc = Arr[0] < Arr[7];

	do {
		sleep(1);
		printf("\n===SORTED ARRAY===\n|");
		for(int i=0; i<=7; i++){
			printf("  %d  |",Arr[i]);
		}
		printf("\n\n");
		//reseets to line 1375 if the user did not input a number
		int notnumber = 0;
		while(!notnumber){
			printf("What number do you want to find?: ");
			if(scanf("%d", &num) !=1){
				printf("\n\x1b[31mInvalid Input! Please enter a valid number.\x1b[0m\n\n");//bobo putangina HAHAHAHAHAHA sabi nang number e, bat ka nag input ng letter tanga AHAHAHAHAAHAHAHA
				while(getchar() != '\n');
			}else{
				notnumber = 1;
			}	
		}

		int left = 0, right = 7, found = 0, pass = 1;  // Changed right to 6

		while(left <= right){
			int mid = (left + right) / 2;

			sleep(1);
			printf("\n================PASS %d================\n", pass++);
			printf("Left index: %d = %d | Right index: %d = %d | Mid index: %d = %d\n", 
				left, Arr[left], right, Arr[right], mid, Arr[mid]);
			sleep(1);
			printf("|");
			for(int i = 0; i < 8; i++)  // Changed to 7
				printf("  %d  |", Arr[i]);
			printf("\n");
			
			//priints the position of MID
			for(int i = 0; i < mid; i++){
						printf("      ");
					}
					printf("  ^\n");
					for(int i = 0; i < mid; i++){
						printf("       ");
					}
					printf("  MID\n");

			//if the number is found it prints where it is located 
			
			if(Arr[mid] == num){
				sleep(1);
				printf("\n\033[1;32m%d is found at index %d!\x1b[0m\n\n", num, mid);//mid is the location
				found = 1;
				break;
			}
			else if((isAsc && num > Arr[mid]) || (!isAsc && num < Arr[mid])){
				sleep(1);
				printf("\n\x1b[33mSearching right half...\x1b[0m\n");
				left = mid + 1;
			}
			else{
				sleep(1);
				printf("\n\x1b[33mSearching left half...\x1b[0m\n");
				right = mid - 1;
			}
		}

		if(!found){
			sleep(1);
			printf("\n\n\x1b[31m%d is not on the list!.\x1b[0m\n\n", num);
		}
	} while(tryAgain() == 1);
	system("cls");
}


//sort algo menu

void sort(){
int Arr[8] = {3, 1, 6, 2, 7, 4, 8, 5};
	system("cls");
	int choice;
	
	do{	
	printf("====SORTING ALGORITHM====\n\n");
	printf("Your array:\n|");
	for(int i = 0; i < 8; i++){
		printf("  %d  |", Arr[i]);
	}
	printf("\n\n");
	
		printf("1. Insertion\n");
		printf("2. Selection\n");
		printf("3. Bubble\n");
		printf("4. Merge\n");
		printf("5. Shell\n");
		printf("6. Quick\n");
		printf("7. go back\n");
		printf("\nChoose your Algorithm: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				
				insertion();
				break;
			case 2:
				
				selection();
				break;
			case 3:
				
				bubble();
				break;
			case 4:
				
				merge();
				break;
			case 5:
				
				shell();
				break;
			case 6:
				
				quick();
				break;
			case 7:
				printf("\n\nExiting...\n\n");
				sleep(1);
				system("cls");
				return 0;
				break;
			default:
				printf("\nInvalid Choice! Please try again.\n");
				sleep(1);
				system("cls");
		}
		
	}while(1);
	system("cls");
}


//search algo menu
void search(){
	system("cls");
	int choice;	
	do{
		
		printf("====SEARCHING ALGORITHM====\n\n");
		
		printf("Your array:\n|");
		for(int i = 0; i < 8; i++){
			printf("  %d  |", Arr[i]);
		}
		printf("\n\n");	
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("3. Go back\n\n");
		
		printf("Choose your searching algorithm: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				linear();
				break;
			case 2:
				
				binary();
				break;
			case 3:
				printf("\n\nExiting...\n\n");
				sleep(1);
				system("cls");
				return;
				break;
			default:
				printf("Invalid choice! please try again.\n\n");
				sleep(1);
				system("cls");
		}
	}while(1);
	system("cls");
}
