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