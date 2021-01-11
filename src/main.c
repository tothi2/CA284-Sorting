#include <stdio.h>
#include <sys/time.h> // this header allows me to use the timeval structure which I will be using to time my algorithms //
#include <time.h>
#include <stdlib.h>

// #### INSERTION SORT #### //

void InsertionSort(int array[], int n)
{
  for (int step = 1; step < n; step++)
  {
    int key = array[step];
    int j = step - 1;
    while (key < array[j] && j >= 0)
    {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}


// ##### SHELL SORT ##### //

void ShellSort(int array[], int n)
{
  for (int interval = n / 2; interval > 0; interval /= 2) // rearranges numbers at each squared n intervals //
  {
    for (int i = interval; i < n; i += 1)
    {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
      {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}


// ###### START OF RADIX SORT ###### //

int getMax(int array[], int n) //this function gets the largest element from an array //
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void CountingSort(int array[], int n, int place) //this sort will sort the elements in their significant places //
{
  int output[n + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < n; i++)
  {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i) 
    count[i] = 0;

  for (int i = 0; i < n; i++) //This loop calculates the count of the elements //
    count[(array[i] / place) % 10]++;
    
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) //This loop places the elements in their sorted order //
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++)
    array[i] = output[i];
}

void RadixSort(int array[], int n)
{
  int max = getMax(array, n); //Using the function written above, this simply gets the maximum element //

  for (int place = 1; max / place > 0; place *= 10) //this loop applies the counting sort that is also written above //
    CountingSort(array, n, place);
}



// ##### SELECTION SORT ##### //

void SelectionSort(int array[], int n)
{
   int i, k, min;
   for (i = 0; i < n - 1; i++)
   {
      min = i;
      for (k = i + 1; k < n; k++)
         if (array[k] < array[min])
            min = k;

      //this puts the min at the correct position//
      int temp = array[min];
      array[min] = array[i]; //this resets the elements so that loop can run again//
      array[i] = temp;
   }
}


// #### NUMBER GENERATOR #### //

int main(int argc, char* argv[])
{
    int arg;
    int i;
	arg = atoi(argv[1]);
	int* array = (int*)malloc(arg * sizeof(arg)); // allocating a size to the array //
	srand(time(NULL));
	for (int i = 0; i< arg / 2; i++)
	{
		array[i] = rand()%1000; // a random number is generated for each number in the array //
	}
    
    //variable names for time intervals//
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start, 0); //start time for calculating the runtime of the algorithms//
	InsertionSort(array, arg); //the array is allocated into the given function//
	gettimeofday(&end, 0); //end time for calculating the runtime //
	
	printf("Insertion Sort: %f milliseconds\n", (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_usec - start.tv_usec) / 1000.0f); // I used float values to show more specific speeds for the faster sorts //

	gettimeofday(&start, 0); // This process must be repeated for each algorithm to reset the start time, otherwise the runtime would be the same for each sort //
	RadixSort(array, arg);
	gettimeofday(&end, 0);
	
	printf("Radix Sort: %f milliseconds\n", (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_usec - start.tv_usec) / 1000.0f);

	gettimeofday(&start, 0);
	ShellSort(array, arg);
	gettimeofday(&end, 0);
	
	printf("Shell Sort: %f milliseconds\n", (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_usec - start.tv_usec) / 1000.0f);

	gettimeofday(&start, 0);
	SelectionSort(array, arg);
	gettimeofday(&end, 0);

	printf("Selection Sort: %f milliseconds\n", (end.tv_sec - start.tv_sec) * 1000.0f + (end.tv_usec - start.tv_usec) / 1000.0f);


	return 0;

}