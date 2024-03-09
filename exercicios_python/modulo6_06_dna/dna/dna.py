import csv
import sys

def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    database_path, sequence_path = sys.argv[1], sys.argv[2]
    database = load_database(database_path)
    sequence = load_sequence(sequence_path)
    str_counts = {str: count_str_repeats(sequence, str) for str in database[0].keys() if str != 'name'}
    for profile in database:
        if all(int(profile[str]) == str_counts[str] for str in str_counts):
            print(profile['name'])
            return

    print("No match")

def load_database(path):
    with open(path, 'r') as file:
        reader = csv.DictReader(file)
        return list(reader)

def load_sequence(path):
    with open(path, 'r') as file:
        return file.read().strip()

def count_str_repeats(sequence, str):
    max_repeats = 0
    str_len = len(str)
    for i in range(len(sequence)):
        repeats = 0
        while sequence[i + repeats*str_len:i + (repeats + 1)*str_len] == str:
            repeats += 1
        max_repeats = max(max_repeats, repeats)
    return max_repeats

if __name__ == "__main__":
    main()
