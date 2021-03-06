import time
import random

def partition(array, low, high):
  # choose the rightmost element as pivot
  pivot = array[high]

  # pointer for greater element
  i = low - 1

  # traverse through all elements
  # compare each element with pivot
  for j in range(low, high):
    if array[j] <= pivot:
      # if element smaller than pivot is found
      # swap it with the greater element pointed by i
      i = i + 1

      # swapping element at i with element at j
      (array[i], array[j]) = (array[j], array[i])

  # swap the pivot element with the greater element specified by i
  (array[i + 1], array[high]) = (array[high], array[i + 1])

  # return the position from where partition is done
  return i + 1

# function to perform quicksort
def quickSort(array, low, high):
  if low < high:

    # find pivot element such that
    # element smaller than pivot are on the left
    # element greater than pivot are on the right
    pi = partition(array, low, high)

    # recursive call on the left of pivot
    quickSort(array, low, pi - 1)

    # recursive call on the right of pivot
    quickSort(array, pi + 1, high)





# Main Function ----------------------------------------
def main():
    total = 0
    for i in range(10):
        randomlist = random.sample(range(-2147483648, 2147483647), 1000000)
        start_time = time.time()
        quickSort(randomlist, 0, 999999)
        total += (time.time() - start_time)
    
    total = total / 10
    print("--- %s seconds ---" % (total))
    

# ------------------------------------------------------

# Ensures main is called when file is run
if __name__ == "__main__":
    main()