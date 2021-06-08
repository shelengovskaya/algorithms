from gost import GOST, Point

def test_gost_sign():
    p = 97
    a = 9
    b = 3
    x = -8
    y = 1
    q = 47
    gost = GOST(p, a, b, q, x, y)
    d = 5
    message = 42
    k = 18
    sign = gost.sign(message, d, k)
    expected = (12, 17)
    assert sign == expected


def test_gost_verify():
    p = 97
    a = 9
    b = 3
    x = -8
    y = 1
    q = 47
    gost = GOST(p, a, b, q, x, y)
    message = 42
    sign = (12, 17)
    q_x = -47
    q_y = -41
    Q = Point(q_x, q_y, a, b, p)
    assert gost.verify(message, sign, Q) == True



test_gost_sign()
test_gost_verify()
