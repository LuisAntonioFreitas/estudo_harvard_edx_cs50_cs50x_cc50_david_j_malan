from cs50 import get_string
import re
#from luhn import *

def main():
    n = get_string_number()

    if is_valid_number(n):
        print(verify_card_type(n))
    else:
        print("INVALID")

def is_valid_number(n):
    return True #verify(n)

def verify_card_type(n):
    length = len(n)
    if (length == 15 and n.startswith(('34', '37'))):
        return "AMEX"
    elif (length == 16 and n.startswith(('51', '52', '53', '54', '55'))):
        return "MASTERCARD"
    elif (length in [13, 16] and n.startswith('4')):
        return "VISA"
    return "INVALID"

def get_string_number():
    while True:
        n = get_string("Number: ")
        if re.match(r'^[ 0-9]+$', n):
            break
    return n

main()
