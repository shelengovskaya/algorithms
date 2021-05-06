import math

print("e, n: ", end='')
e, n = list(map(int, input().split(' ')))
num, den = e, n
a, q = divmod(num, den)
t = den
res = [a]
while q != 0:
    next_t = q
    a, q = divmod(t, q)
    t = next_t
    res.append(a)
print("[a_1, a_2, ...] =", res)

k_1 = 1
d_1 = 0
k_0 = res[0]
d_0 = 1
kn = res[1] * k_0 + k_1
dn = res[1] * d_0 + d_1
p = 0
q = 0
d = 0
i = 2
print ("k/d: ", k_1, '/', d_1, ', ', k_0, '/', d_0, sep='', end=', ')
while n != p * q and i < len(res):
    fn = (e * dn - 1) / kn
    print (kn, '/', dn, sep='', end=', ')
    # ур-е
    a = 1
    b = n - fn + 1
    c = n
    discr = b ** 2 - 4 * a * c
    if discr > 0:
        p = (-b + math.sqrt(discr)) / (2 * a)
        q = (-b - math.sqrt(discr)) / (2 * a)
        d = dn
    k_1 = k_0
    d_1 = d_0
    k_0 = kn
    d_0 = dn
    kn = res[i] * k_0 + k_1
    dn = res[i] * d_0 + d_1
    i += 1
print("\nd =", d)
