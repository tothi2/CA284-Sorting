void SelectionSort(int array[], int n)
{
   int i, j, min;
   for (i = 0; i < n - 1; i++)
   {
      min = i;
      for (j = i + 1; j < n; j++)
         if (array[j] < array[min])
            min = j;

      int temp = array[min];
      array[min] = array[i];
      array[i] = temp;
   }
}