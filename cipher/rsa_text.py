from random import randint

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def evklid(a, b):
	d = gcd(a, b)

	x2 = 1
	x1 = 0
	y2 = 0
	y1 = 1
	q = r = x = y = 0

	while b > 0:
		q = a // b
		r = a - q * b
		x = x2 - q * x1
		y = y2 - q * y1
		a = b
		b = r
		x2 = x1
		x1 = x
		y2 = y1
		y1 = y

	d = a
	x = x2
	y = y2
	return y


def step(a, k, n):
	b = 1
	if k == 0:
		return b
	c = a
	if (k & 1) == 1:
		b = a
	for i in range(1, 32):
		c = (c * c) % n
		if ((k >> i) & 1) == 1:
			b = (c * b) % n
	return b


def ferm(n):
    if n == 1:
        return 0
    if n == 2:
        return 1
    for i in range(10):
        a = randint(2, n - 1)
        r = step(a, n - 1, n) #a ^ (n-1) mod n
        if r != 1:
            return 0
    return 1


def generate():
    p = 1
    q = 1

    while ferm(p) == 0:
        p = randint(10, 20)
    while ferm(q) == 0:
        q = randint(10, 20)

    n = p * q
    phi = (p - 1) * (q - 1)

    e = 2
    while e <= phi:
        if gcd(e, phi) == 1:
            break
        e += 1
    d = (evklid(phi, e) + phi) % phi #   >= 0
    return e, d, n



def encrypt(e, n):
    print ("Print text: ", end='')
    m = input()

    print("Encrypted message: ", end='')

    c = ''
    for i in range(len(m)):
        sym = ord(m[i])
        print (step(sym, e, n), end=' ')
    print()


def decrypt(d, n):
    print ("Print shifttext: ", end='')
    c = list(map(int, input().split()))

    print("Decrypted message: ", end=' ')

    m = ''
    for i in range(len(c)):
        sym = step(c[i], d, n)
        print(chr(sym), end='')
    print()


def main():
    print ("1 - encrypt; 2 - decrypt: ", end='')
    en = int(input())

    print ("Do you want generate key? (1 / 0): ", end='')
    l = int(input())


    if l == 1:
        e, d, n = generate()
        print ("e, d, n:", e, d, n)
        if en == 1:
            encrypt(e, n)
        else:
            decrypt(d, n)
    else:
        if en == 1:
            print ("Print (e, n): ", end='')
            e, n = list(map(int, input().split()))
            encrypt(e, n)
        else:
            print ("Print (d, n): ", end='')
            d, n = list(map(int, input().split()))
            decrypt(d, n)


main()
