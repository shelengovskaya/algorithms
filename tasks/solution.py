NUMBERS = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
RESULT_SUM = 200

sequences = []

def generate(s='', count=9):
    # рекурсивно генерирует последовательсти из 0,1,2:
    # ('0' == "между элементами нет знака",
    # '1' == "между элементами знак +",
    # '2' == "между элементами знак -")
    # e.g. '102012101' будет соответствовать выражению '9+87-65+4-3+21+0'
    if count == 0:
        sequences.append(s)
        return
    generate(s+'0', count-1)
    generate(s+'1', count-1)
    generate(s+'2', count-1)


def main():
    generate()

    for seq in sequences:
        sum = 0 # сумма
        prev_num = 9 # предыдущее накопленное число
        prev_sign = '1' # предыдущий "знак"('0'/'1'/'2') в выражении (изначально +)
        expression = '9' # выражение
        for i in range(9):
            if seq[i] != '0':
                expression += '+' if seq[i] == '1' else '-'
            expression += str(NUMBERS[i+1])
            if seq[i] == '0':
                if prev_num:
                    prev_num *= 10
                    prev_num += NUMBERS[i+1]
            elif seq[i] == '1':
                if prev_num:
                    if prev_sign == '1':
                        sum += prev_num
                    elif prev_sign == '2':
                        sum -= prev_num
                prev_sign = '1'
                prev_num = NUMBERS[i+1]
            elif seq[i] == '2':
                if prev_num:
                    if prev_sign == '1':
                        sum += prev_num
                    elif prev_sign == '2':
                        sum -= prev_num
                prev_sign = '2'
                prev_num = NUMBERS[i+1]
        if prev_num:
            if prev_sign == '1':
                sum += prev_num
            elif prev_sign == '2':
                sum -= prev_num
        if sum == RESULT_SUM:
            print(expression, '=', sum, sep='')

if __name__ == '__main__':
    main()
