def my_function(a, b, c, d):
  print(a + b + c + d)

my_function(5, 6, c = 7, d = 8)
def compare() -> float:
  min_value: float = None
  i: int = 0
  for i in range(len(data)):
    if not min_value:
      min_value = data[i]
    elif data[i] < min_value:
      min_value = data[i]
  return min_value
def bubbleSort(arr):
    n = len(arr)
    swapped = False
    # Traverse through all array elements
    for i in range(n-1):
        for j in range(0, n-i-1):

            if arr[j] > arr[j + 1]:
                swapped = True
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def main():
  arr = [64, 34, 25, 12, 22, 11, 90]
  result: int = binarySearch(array, 4, 0, len(array) - 1)
  if result != -1:
    print("Element is present at index:")
    print(result)
  else:
    print("Element is not present")

def main() -> None:
    obj: MyClass = MyClass("Example")
    print( obj.get_name())
    obj.set_name("NewName")
    print(obj.get_name())

if __name__ == "__main__":
    main()
