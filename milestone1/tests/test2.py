def compute_avg() -> float:
  avg_value: float = None
  sum: int = 0
  i: int = 0
  for i in range(len(data)):
    sum += data[i]
  return sum / len(data)
def my_function(country):
  print("I am from " + country)

my_function("Sweden")
my_function("India")
my_function()
my_function("Brazil")

def mergesort(array: list[int], x: int, low: int, high: int) -> int:
  while low <= high:
    mid: int = low + (high - low) // 2
    if array[mid] == x:
      return mid
    elif array[mid] < x:
      low = mid + 1
    else:
      high = mid - 1
  return -1
class __Parser:
  def __init__(self, name_: str):
    self.srname: str = name_


class LR0__(ShiftReduceParser):
  def __init__(self, myname_: str, parentname_: str):
    self.lr0name: str = myname_
    ShiftReduceParser.__init__(self, parentname_)


def main() -> None:
    obj: MyClass = MyClass("Example")
    print( obj.get_name())
    obj.set_name("NewName")
    print(obj.get_name())

if __name__ == "__main__":
    main()

