from cs50 import get_string

def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = 0.0588 * L - 0.296 * S - 15.8
    grade = round(index)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

def count_letters(text):
    return sum(c.isalpha() for c in text)

def count_words(text):
    return len(text.split())

def count_sentences(text):
    return sum(c in '.!?' for c in text)

if __name__ == "__main__":
    main()
