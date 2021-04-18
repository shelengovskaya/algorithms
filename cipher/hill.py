import numpy as np
from egcd import egcd

alp = "abcdefghijklmnopqrstuvwxyz., "
MOD = len(alp)
letter_to_index = dict(zip(alp, range(MOD)))
index_to_letter = dict(zip(range(MOD), alp))

def to_upper_lower(start, ans):
    result = ''
    for i in range(len(ans)):
        if start[i].isupper():
            result += ans[i].upper()
        else:
            result += ans[i]
    return result


def encrypt(m, K):
    text = m.lower()
    text_num = []
    n = K.shape[0]

    for sym in text:
        text_num.append(letter_to_index[sym])

    split_P = [
        text_num[i : (i + n)]
        for i in range(0, len(text_num), n)
    ]

    result = ''
    for P in split_P:
        P = np.transpose(np.asarray(P))[:, np.newaxis]
        nums = np.dot(K, P) % MOD
        for idx in range(nums.shape[0]):
            result += index_to_letter[nums[idx, 0]]

    return to_upper_lower(m, result)


def decrypt(c, Kinv):
    text = c.lower()
    text_num = []
    n = Kinv.shape[0]

    for sym in text:
        text_num.append(letter_to_index[sym])

    split_C = [
        text_num[i : (i + n)]
        for i in range(0, len(text_num), n)
    ]

    result = ''
    for C in split_C:
        C = np.transpose(np.asarray(C))[:, np.newaxis]
        nums = np.dot(Kinv, C) % MOD
        for idx in range(nums.shape[0]):
            result += index_to_letter[nums[idx, 0]]

    return to_upper_lower(c, result)

def inv(matrix):
    det = int(np.round(np.linalg.det(matrix)))
    det_inv = egcd(det, MOD)[1] % MOD
    matrix_inv = (
        det_inv * np.round(det * np.linalg.inv(matrix)).astype(int) % MOD
    )
    return matrix_inv

def main():
    print ("Print text: ", end='')
    message = input()
    size = len(message)

    print("Key - martix[n x n]:\nPrint n: ", end='')
    n = int(input())
    K = np.arange(n * n).reshape(n, n)

    for i in range(n):
        for j in range(n):
            print('Print K[' + str(i) + '][' + str(j) + ']: ', end='')
            K[i][j] = int(input())

    while (len(message) % n != 0):
        message += " "

    print ('1 - encrypt; 2 - decrypt: ', end='')
    l = int(input())
    if l == 1:
        print("Encrypted message: " + encrypt(message, K))
    elif l == 2:
        K_inv = inv(K)
        print("Decrypted message: " + decrypt(message, K_inv))


main()
