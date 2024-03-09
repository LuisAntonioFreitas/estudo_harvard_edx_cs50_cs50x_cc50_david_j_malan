from cs50 import get_float

def main():
    n = get_float_change_owed()
    c = coins(n)
    print(c)

def coins(n):
    cents = round(n * 100)
    coins = 0

    for coin in [25, 10, 5, 1]:
        coins += cents // coin
        cents %= coin

    return coins

def get_float_change_owed():
    while True:
        n = get_float("Change owed: ")
        if n >= 0:
            break
    return n

main()
