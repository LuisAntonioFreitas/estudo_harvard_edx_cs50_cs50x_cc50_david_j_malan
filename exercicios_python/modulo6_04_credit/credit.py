from cs50 import get_string
import re
from luhn import *

def main():
    n = get_string_number()

    if is_valid_number(n):
        print(verify_card_type(n))
    else:
        print("INVALID")

def is_valid_number(n):
    return verify(n)

def verify_card_type(n):
    cents = round(n * 100)
    coins = 0

    for coin in [25, 10, 5, 1]:
        coins += cents // coin
        cents %= coin

    return coins

def get_string_number():
    while True:
        n = get_string("Number: ")
        if re.match(r'^[ 0-9]+$', n):
            break
    return n

main()
