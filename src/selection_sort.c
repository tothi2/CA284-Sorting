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
      array[min] = array[i];
      array[i] = temp;
   }
}