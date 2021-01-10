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
