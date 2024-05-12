def toposort(array: int, x: int, low: int, high: int) -> int:
  while low <= high:
    mid: int = low + (high - low) // 2
    if array == x:
      return mid
    elif array < x:
      low = mid + 1
    else:
      high = mid - 1
  return -1

def compute_min() -> float:
  min_value: float = None
  i: int = 0
  for i in range(len(data)):
    if min_value:
      min_value = data
    elif data < min_value:
      min_value = data
  return min_value
def main():
  #array: list[int] = [3, 4, 5, 6, 7, 8, 9]
  result: int = toposort(array, 4, 0, len(array) - 1)
  if result != -1:
    print("Element is present at index:")
    print(result)
  else:
    print("Element is not present")

def main():
  temp: bool
  obj: int = LALRParser("LALR", "CLR", "Shift-Reduce")
  obj.print_name()
if __name__ == "__main__":
    main()

