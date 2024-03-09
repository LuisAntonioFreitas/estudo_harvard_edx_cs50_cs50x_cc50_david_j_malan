from cs50 import get_string
import re

def main():
    n = get_string_number()

    if is_valid_number(n):
        print(verify_card_type(n))
    else:
        print("INVALID")

def is_valid_number(n):
    # # algoritmo de Luhn
    # total = 0
    # for i, digit in enumerate(reversed(n), start=1):
    #     if i % 2 == 0:
    #         doubled = int(digit) * 2
    #         total += doubled if doubled < 10 else doubled - 9
    #     else:
    #         total += int(digit)
    # return total % 10 == 0
    # 1. Change datatype to list[int]
    card_number = [int(num) for num in n]

    # 2. Remove the last digit:
    checkDigit = card_number.pop(-1)

    # 3. Reverse the remaining digits:
    card_number.reverse()

    # 4. Double digits at even indices
    card_number = [num * 2 if idx % 2 == 0
                   else num for idx, num in enumerate(card_number)]

    # 5. Subtract 9 at even indices if digit is over 9
    # (or you can add the digits)
    card_number = [num - 9 if idx % 2 == 0 and num > 9
                   else num for idx, num in enumerate(card_number)]

    # 6. Add the checkDigit back to the list:
    card_number.append(checkDigit)

    # 7. Sum all digits:
    checkSum = sum(card_number)

    # 8. If checkSum is divisible by 10, it is valid.
    return checkSum % 10 == 0

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
