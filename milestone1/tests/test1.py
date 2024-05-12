def toposort(array: list[int], x: int, low: int, high: int) -> int:
  while low <= high:
    mid: int = low + (high - low) // 2
    if array[mid] == x:
      return mid
    elif array[mid] < x:
      low = mid + 1
    else:
      high = mid - 1
  return -1
class CLASSNAME:
    def get_name(self) -> str:
        return self.__name
class CLRParser(ShiftReduceParser):
  def __init__(self, myname_: str, parentname_: str):
    self.clrname: str = myname_
    ShiftReduceParser.__init__(self, parentname_)


class LALRParser(CLRParser):
  def __init__(self, myname_: str, clrname_: str, srname_: str):
    self.lalrname: str = myname_
    CLRParser.__init__(self, clrname_, srname_)
def compute_min() -> float:
  min_value: float = None
  i: int = 0
  for i in range(len(data)):
    if not min_value:
      min_value = data[i]
    elif data[i] < min_value:
      min_value = data[i]
  return min_value
def main():
  array: list[int] = [3, 4, 5, 6, 7, 8, 9]
  result: int = toposort(array, 4, 0, len(array) - 1)
  if result != -1:
    print("Element is present at index:")
    print(result)
  else:
    print("Element is not present")

def main():
  obj: LALRParser = LALRParser("LALR", "CLR", "Shift-Reduce")
  obj.print_name()
if __name__ == "__main__":
    main()

