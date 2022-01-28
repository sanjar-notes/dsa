# 4. Extended Euclidean Algorithm
Created Wednesday 29 July 2020

Statement: If ax+by=gcd(a, b) then we can solve for x and y using extended Euclidean algorithm.


* gcd(a, b) = gcd(b, a%b) = bx~1~+(a%b)y~1~
* gcd(a, b) = bx~1~+(a-b*floor(a/b))y~1~
* ax+by = ay~1~+b(x~1~-floor(a/b)*y~1~), comparing coefficients, we can solve for x and y x=y~1~, y=x~1~-floor(a/b)*y~1~
* We may have to do this step mant times, till we get equation of the form gcd(1, x).
* Then we solve backwards.


