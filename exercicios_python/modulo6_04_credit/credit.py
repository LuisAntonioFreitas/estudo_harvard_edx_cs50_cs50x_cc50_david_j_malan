from cs50 import get_string
import re

def main():
    n = get_string_number()

    if(is_valid_number(n) == 0):
        print("INVALID")
    } else {
        if(verify_visa(n) == 1) {
            printf("VISA\n");
        } else if(verify_mastercard(n) == 1) {
            printf("MASTERCARD\n");
        } else if(verify_amex(n) == 1) {
            printf("AMEX\n");
        } else {
            printf("INVALID\n");
        }
    }


    card = coins(n)
    print(card)

def is_valid_number(n):
    # Algoritmo de Luhn
    total = 0
    for i, digit in enumerate(reversed(n), start=1):
        if i % 2 == 0:
            doubled = int(digit) * 2
            total += doubled if doubled < 10 else doubled - 9
        else:
            total += int(digit)
    return total % 10 == 0

def coins(n):
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
