def sum_of_digits(number):
    return sum(int(digit) for digit in str(number))

while True:
    try:
        n = int(input())
        result = 1
        while n!=0:
            result = result*n
            n = n-1

        digit_sum = sum_of_digits(result)
        print(digit_sum)
    except EOFError:
        break
