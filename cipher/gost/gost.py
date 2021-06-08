import random

class GOST:
    def __init__(self, p, a, b, q, p_x, p_y):
        self.p_point = Point(p_x, p_y, a, b, p)
        self.q = q; self.a = a; self.b = b; self.p = p

    def sign(self, message, d, k=0):
        e = message % self.q
        if e == 0:
            e = 1
        if k == 0:
            k = random.randint(1, self.q - 1)
        r, s = 0, 0
        while r == 0 or s == 0:
            c_point = k * self.p_point
            r = c_point.x % self.q
            s = (r * d + k * e) % self.q
        return r, s

    def verify(self, message, sign, Q):
        e = message % self.q
        if e == 0:
            e = 1
        v = Point._mod_inverse(e, self.q)
        z1 = (sign[1] * v) % self.q
        z2 = (-sign[0] * v) % self.q
        c_point = z1 * self.p_point + z2 * Q
        r = c_point.x % self.q
        if r == sign[0]:
            return True
        return False

    
    
    
    
    
    
    
    
####################################################################    
    
    
class Point:
    def __init__(self, x=0, y=0, a=0, b=0, p=0):
        self.x = x; self.y = y; self.a = a; self.b = b; self.p = p
  
    def _mod_inverse(b, p):
        x0, x1, y0, y1, n = 1, 0, 0, 1, p
        while n != 0:
            q, b, n = b // n, n, b % n
            x0, x1 = x1, x0 - q * x1
            y0, y1 = y1, y0 - q * y1
        return x0 % p

    def __add__(self, other):
        result = Point(); result.a = self.a; result.b = self.b; result.p = self.p
        if self.x == other.x and self.y == other.y:
            l = ((3 * self.x ** 2 + self.a) * Point._mod_inverse(2 * self.y, self.p)) % self.p
        else:
            if self.x == other.x:
                return float('inf')
            dx_inverse = Point._mod_inverse((other.x - self.x) % self.p, self.p)
            l = ((other.y - self.y) % self.p * dx_inverse) % self.p
        result.x = (l * l - self.x - other.x) % self.p
        result.y = (l * (self.x - result.x) - self.y) % self.p
        return result

    def __rmul__(self, other):
        result = Point(self.x, self.y, self.a, self.b, self.p)
        temp = Point(self.x, self.y, self.a, self.b, self.p)
        x = other - 1
        while x != 0:
            if x % 2 != 0:
                result += temp
                x -= 1
            x //= 2
            temp = temp + temp
        return result
