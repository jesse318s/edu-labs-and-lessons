"""
Programming Fundamentals - Python
"""
from abc import ABC, abstractmethod


# pure function
def add(a: int, b: int) -> int:
    return a + b


# abstract class
class Hello(ABC):
    @abstractmethod
    def get_is_special(self):
        pass


class HelloWorld(Hello):
    __object_counter = 0  # Private class variable
    message = "Hello, World!"  # Public class variable

    def __init__(self):
        HelloWorld.__object_counter += 1
        self.__is_special = True  # Private instance variable

    @classmethod
    def set_object_counter(cls, new_object_counter):
        cls.__object_counter = new_object_counter

    @classmethod
    def get_object_counter(cls):
        print(f"Number of HelloWorld objects: {cls.__object_counter}")

    def set_is_special(self, is_special):
        self.__is_special = is_special

    def get_is_special(self):
        print(f"isSpecial: {self.__is_special}")

    def greet(self):
        if isinstance(self, HelloWorld):
            print(self.message)


def main():
    """
    Fundamental Programming Concepts:
    - Variable declaration
    - Basic syntax
    - Data types and structures
    - Flow control structures (Conditionals and loops)
    - Functional programming
    - Object-oriented programming (OOP Principles: Inheritance, Polymorphism,
      Abstraction, Encapsulation)
    """
    # Variable declaration
    a = 1
    b = 2

    # Basic syntax
    print(a + b)
    print(a - b)

    # Data types and structures
    arr = [1, 2, 3, 4, 5]

    arr_elem1 = str(arr[0])

    # Flow control structures (Conditionals and loops)
    if (a + b) == 3:
        print("a + b is equal to 3")
    else:
        print("a + b is not equal to 3")

    i = 5

    while i > 0:
        print(f"i = {i}")
        i -= 1

    # Functional programming
    print(add(a, b))
    print(add(1, 2))

    # Object-oriented programming (OOP Principles: Inheritance, Polymorphism,
    # Abstraction, Encapsulation)
    hello_world = HelloWorld()
    hello_world.greet()
    hello_world.get_is_special()
    hello_world2 = HelloWorld()
    hello_world2.set_is_special(False)
    hello_world2.get_is_special()
    HelloWorld.get_object_counter()


if __name__ == "__main__":
    main()
