#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int COMPCOUNT = 0;

void printInfoBest(int arr[], int n);
void printInfoWorst(int arr[], int n);
void printInfoRandom(int arr[], int n);
void insertionSort(int arr[], int n);
void arrayPrint(int arr[], int n);
void arrayFillBest(int arr[], int size);
void arrayFillWorst(int arr[], int size);
void arrayFillRandom(int arr[], int size);
bool SMALLER(int arr[], int i, int j);

int main() {
    int n = 10000; //32, 100, 1000, 10000
    int arr[n], i;

    printInfoBest(arr, n);
    printInfoWorst(arr, n);
    printInfoRandom(arr, n);




    return 0;
}

void printInfoBest(int arr[], int n) {
    puts("==================================================================================================");

    printf("BEST CASE: n = %d\n\n", n); //change case name manually
    arrayFillBest(arr, n);
    //arrayFillWorst(arr, n);
    //arrayFillRandom(arr, n); //fill array with "truly random" numbers (very impressive i know)
    //printf("unsorted array: ");
    //arrayPrint(arr,n);
    insertionSort(arr, n);
    //printf("sorted array: ");
    //arrayPrint(arr, n);

    int theoryAverage = (n * n - n) / 4;
    int theoryWorst = (n * n - n) / 2;
    int estimateComparisons = (n * n) / 4;

    printf("\nTheory Average: %d\n", theoryAverage);
    printf("Theory Worst: %d\n", theoryWorst);
    printf("Theory Comparisons: %d\n\n", estimateComparisons);

    printf("Actual Key Comparisons: %d\n", COMPCOUNT);
}

void printInfoWorst(int arr[], int n) {
    puts("==================================================================================================");

    printf("WORST CASE: n = %d\n\n", n); //change case name manually
    //arrayFillBest(arr, n);
    arrayFillWorst(arr, n);
    //arrayFillRandom(arr, n); //fill array with "truly random" numbers (very impressive i know)
    //printf("unsorted array: ");
    //arrayPrint(arr,n);
    insertionSort(arr, n);
    //printf("sorted array: ");
    //arrayPrint(arr, n);

    int theoryAverage = (n * n - n) / 4;
    int theoryWorst = (n * n - n) / 2;
    int estimateComparisons = (n * n) / 4;

    printf("\nTheory Average: %d\n", theoryAverage);
    printf("Theory Worst: %d\n", theoryWorst);
    printf("Theory Comparisons: %d\n\n", estimateComparisons);

    printf("Actual Key Comparisons: %d\n", COMPCOUNT);
}

void printInfoRandom(int arr[], int n) {
    puts("==================================================================================================");

    printf("RANDOM CASE: n = %d\n\n", n); //change case name manually
    //arrayFillBest(arr, n);
    //arrayFillWorst(arr, n);
    arrayFillRandom(arr, n); //fill array with "truly random" numbers (very impressive i know)
    //printf("unsorted array: ");
    //arrayPrint(arr,n);
    insertionSort(arr, n);
    //printf("sorted array: ");
    //arrayPrint(arr, n);

    int theoryAverage = (n * n - n) / 4;
    int theoryWorst = (n * n - n) / 2;
    int estimateComparisons = (n * n) / 4;
    COMPCOUNT -= theoryAverage * 2;

    printf("\nTheory Average: %d\n", theoryAverage);
    printf("Theory Worst: %d\n", theoryWorst);
    printf("Theory Comparisons: %d\n\n", estimateComparisons);

    printf("Actual Key Comparisons: %d\n", COMPCOUNT);
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            COMPCOUNT++; //couldnt get SMALLER working, no values made thru check so incrementing here
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void arrayFillBest(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = i + 1;
        //printf("%d: %d\n",i, arr[i]);
    }
}

void arrayFillWorst(int arr[], int size) {
    int i, temp;
    for(i = 0; i < size; i++) {
        arr[i] = i + 1;
        //printf("%d: %d\n",i, arr[i]);
    }
    for(i = 0; i < size / 2; i++){
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void arrayFillRandom(int arr[], int size) {
    srand(time(NULL)); //using time to make it "truly random"
    int i;
    for(i = 0; i < size; i++) {
        arr[i] = rand()%100;
        //printf("%d: %d\n",i, arr[i]);
    }
}

void arrayPrint(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

bool SMALLER(int arr[], int i, int j) {
    COMPCOUNT++;
    if(arr[i] < arr[j])
        return true;
    else
        return false;
}