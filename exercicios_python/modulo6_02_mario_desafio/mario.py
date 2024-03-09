from cs50 import get_int

def main():
    n = get_int_positive()
    pyramid(n)

def pyramid(n):
    for i in range(n):
        print(" " * (n-(i+1)), end="")
        print("#" * (i+1), end="")
        print(" " * 2, end="")
        print("#" * (i+1))

def get_int_positive():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n

main()
