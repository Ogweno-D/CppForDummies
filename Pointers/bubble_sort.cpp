//
// Created by Ogweno on 28/07/2025.

/*
 * Generic Bubble Sort Algorithm using void pointers and function pointers.
 * Bubble Sort is basically comparing two elements of an array
 * The array can be of any datatype
*/

#include<iostream>
using namespace std;

// Generic fxn Pointer
typedef  bool(*compareFunction)(const void*, const void*);
void generic_bubble_sort(void*arr, size_t n, size_t element_size_bytes,compareFunction compare_function);
/*
 *Custom swap function
 */
void generic_swap(void* element1, void* element2, size_t element_size_bytes)
 {
   char* temp_buffer = new char[element_size_bytes];
   memcpy(temp_buffer, element1, element_size_bytes);
   memcpy(element1, element2, element_size_bytes);
   memcpy(element2, temp_buffer, element_size_bytes);

  delete[] temp_buffer;
  // temp_buffer = nullptr;
 }
// Fxn for comparing integers
bool compare_integer(const void* a, const void* b)
{
 const auto temp_a = static_cast<const int*>(a);
 const auto temp_b = static_cast<const int*>(b);

 return *temp_a > *temp_b;
}
// Function for comparing doubles
bool compare_doubles(const void* a, const void* b)
{
 const auto* temp_a = static_cast<const double*>(a);
 const auto* temp_b = static_cast<const double*>(b);
 return *temp_a > *temp_b;
}
// Fxn for comparing chars
bool compare_chars(const void* a, const void* b)
{
 const auto* temp_a = static_cast<const char*>(a);
 const auto* temp_b = static_cast<const char*>(b);
 return *temp_a > *temp_b;
}

// Generic Bubble sort Implementation
void generic_bubble_sort(void* arr, size_t n, size_t element_size_bytes, compareFunction compare_function)
{
 char* byte_array = static_cast<char*>(arr);

 for (size_t j= 0; j < n; j++)
 {
  bool swapped = false;
  for (size_t i = 0; i < n-1-j; i++)
  {
   void* element1 = byte_array + (i*element_size_bytes);
   void* element2 = byte_array + ((i+1)*element_size_bytes);

   if (compare_function(element1, element2))
   {
    generic_swap(element1, element2, element_size_bytes);
    swapped = true;
   }
  }
  if (!swapped)
  {
   return;
  }
 }
}


int main()
{

 // For int
 int arr[]= { 12,3,24,67,54,23,13};
 size_t size = std::size(arr);
 size_t element_size_bytes = sizeof(arr[0]);

 // simple_bubble_sort(arr, size);
 generic_bubble_sort(arr, size, element_size_bytes, compare_integer);

 // Print the sorted array
 for (int i = 0; i < size; i++)
  {
   cout << arr[i] << " ";
  }

 cout << "\n ===============================================\n" << endl;
 // For doubles
 double doubleArray[] = {3.14, 1.618, 2.718, 0.577, 9.81};
 size_t doubleArray_size = std::size(doubleArray);
 size_t doubleArray_element_size = sizeof(doubleArray[0]);

 // Sort
 generic_bubble_sort(doubleArray, doubleArray_size, doubleArray_element_size, compare_doubles);
 for (size_t i = 0; i < doubleArray_size; i++)
 {
  cout << doubleArray[i] << " ";
 }

 cout << "\n===============================================\n" << endl;
 // For characters
 char charArray[] = {'z', 'a', 'x', 'c', 'v', 'b'};
 size_t charArray_size = std::size(charArray);
 size_t charArray_element_size = sizeof(charArray[0]);

 // Sort
 generic_bubble_sort(charArray,charArray_size,charArray_element_size,compare_chars);

 for (size_t i = 0; i < charArray_size; i++)
 {
  cout << charArray[i] << " ";
 }



 return 0;
}




/*
 * Normal bubble sort
*/
// void simple_bubble_sort(int *arr, const size_t n)
// {
//  for (size_t j= 0; j < n; j++)
//  {
//   bool swapped = false;
//   for (size_t i = 0; i < n-1-j; i++)
//   {
//    if (arr[i] > arr[i+1])
//    {
//     int temp = arr[i];
//     arr[i] = arr[i+1];
//     arr[i+1] = temp;
//     swapped = true;
//    }
//   }
//   if (!swapped)
//   {
//    return;
//   }
//  }
// Custom comparison function




