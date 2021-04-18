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


def encrypt(m, K1, K2):
    text = m.lower()
    text_num = []
    n = K1.shape[0]

    for sym in text:
        text_num.append(letter_to_index[sym])

    split_P = [
        text_num[i : (i + n)]
        for i in range(0, len(text_num), n)
    ]

    i = 1
    result = ''
    for P in split_P:
        if i == 1:
            P = np.transpose(np.asarray(P))[:, np.newaxis]
            nums = np.dot(K1, P) % MOD
            for idx in range(nums.shape[0]):
                result += index_to_letter[nums[idx, 0]]
        elif i == 2:
            P = np.transpose(np.asarray(P))[:, np.newaxis]
            nums = np.dot(K2, P) % MOD
            for idx in range(nums.shape[0]):
                result += index_to_letter[nums[idx, 0]]
        else:
            K = K1 @ K2
            P = np.transpose(np.asarray(P))[:, np.newaxis]
            nums = np.dot(K, P) % MOD
            for idx in range(nums.shape[0]):
                result += index_to_letter[nums[idx, 0]]
            K1 = K2
            K2 = K
        i += 1

    return to_upper_lower(m, result)


def decrypt(c, K1_inv, K2_inv):
    text = c.lower()
    text_num = []
    n = K1_inv.shape[0]

    for sym in text:
        text_num.append(letter_to_index[sym])

    split_C = [
        text_num[i : (i + n)]
        for i in range(0, len(text_num), n)
    ]

    i = 1
    result = ''
    for C in split_C:
        if i == 1:
            
            C = np.transpose(np.asarray(C))[:, np.newaxis]
            nums = np.dot(K1_inv, C) % MOD
            for idx in range(nums.shape[0]):
                result += index_to_letter[nums[idx, 0]]
        elif i == 2:
            C = np.transpose(np.asarray(C))[:, np.newaxis]
            nums = np.dot(K2_inv, C) % MOD
            for idx in range(nums.shape[0]):
                result += index_to_letter[nums[idx, 0]]
        else:
            K_inv = K2_inv @ K1_inv
            C = np.transpose(np.asarray(C))[:, np.newaxis]
            nums = np.dot(K_inv, C) % MOD
            for idx in range(nums.shape[0]):
                result += index_to_letter[nums[idx, 0]]
            K1_inv = K2_inv
            K2_inv = K_inv
        i += 1

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

    print("K1, K2 - martixs[n x n]:\nPrint n: ", end='')
    n = int(input())
    K1 = np.arange(n * n).reshape(n, n)
    K2 = np.arange(n * n).reshape(n, n)

    for i in range(n):
        for j in range(n):
            print('Print K1[' + str(i) + '][' + str(j) + ']: ', end='')
            K1[i][j] = int(input())

    for i in range(n):
        for j in range(n):
            print('Print K2[' + str(i) + '][' + str(j) + ']: ', end='')
            K2[i][j] = int(input())

    while (len(message) % n != 0):
        message += " "

    print ('1 - encrypt; 2 - decrypt: ', end='')
    l = int(input())
    if l == 1:
        print("Encrypted message: " + encrypt(message, K1, K2))
    elif l == 2:
        K1_inv = inv(K1)
        K2_inv = inv(K2)
        print("Decrypted message: " + decrypt(message, K1_inv, K2_inv))


main()
