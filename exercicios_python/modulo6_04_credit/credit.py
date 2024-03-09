from cs50 import get_string
import re

def main():
    n = get_string_number()

    if is_valid_number(n):
        print(verify_card_type(n))
    else:
        print("INVALID")

def is_valid_number(n):
    # algoritmo de Luhn
    total = 0
    for i, digit in enumerate(reversed(n), start=1):
        if i % 2 == 0:
            doubled = int(digit) * 2
            total += doubled if doubled < 10 else doubled - 9
        else:
            total += int(digit)
    return total % 10 == 0

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
