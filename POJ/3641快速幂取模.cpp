#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool isPrimer(long long num) {
    double n = sqrt(num);
    long long i;

    for (i = 2; i <= n; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

long long powMod(long long a, long long b, long long c) {
    // a ^ b mod c
    long long ans = 1;
    a %= c;

    while (b > 0) {
        if (b % 2 == 1)
            ans = (ans * a) % c;

        b /= 2;
        a = (a * a) % c;
    }

    return ans;
}

int main()
{
    long long p, a;

    while (scanf("%lld %lld", &p, &a) != EOF) {
        if (!p && !a)
            break;

        if (isPrimer(p))
            printf("no\n");
        else {
            if (powMod(a, p, p) == a)
                printf("yes\n");
            else
                printf("no\n");
        }
    }

    return 0;
}
