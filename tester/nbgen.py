import random, sys

def generate_random_numbers(n):
    numbers = list(range(1, n+1))
    random.shuffle(numbers)
    return numbers

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python random_numbers.py N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be an integer")
        sys.exit(1)

    random_numbers = generate_random_numbers(N)

    for i in random_numbers:
        print(i, end=" ")
    print("\n")