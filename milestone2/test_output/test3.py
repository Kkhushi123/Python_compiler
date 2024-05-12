class func1_lr(ShiftReduceParser):

  def __init__(self, myname_: str, parentname_: str):
    self.clrname: str = myname_
    ShiftReduceParser.__init__(self, parentname_)


class funct2_l0(CLRParser):

  def __init__(self, myname_: str, clrname_: str, srname_: str):
    self.lalrname: str = myname_
    CLRParser.__init__(self, clrname_, srname_)

  def print_name(self):
    print("SLR name:")
    print(self.srname)
    print("CLR name:")
    print(self.clrname)
    print("LALR name:")
    print(self.lalrname)
def my_function(food):
  for x in food:
    print(x)

#fruits = ["apple", "banana", "cherry"]

my_function(fruits)

#data: list[float] = [-2.3, 3.14, 0.9, 11, -9.1]

def main():
  array: int
  result: int = binarySearch(array, 4, 0, len(array) - 1)
  if result != -1:
    print("Element is present at index:")
    print(result)
  else:
    print("Element is not present")
if __name__ == "__main__":
  main()

