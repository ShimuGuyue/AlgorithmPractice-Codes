#include "BigInt.h"

int main(void)
{
    BigInt a, b;
    std::cin >> a >> b;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a+b: " << (a + b) << std::endl;
    // std::cout << "a+=b: " << (a += b) << std::endl;
    // std::cout << "a: " << a << std::endl;
    std::cout << "a-b: " << (a - b) << std::endl;
    // std::cout << "a-=b: " << (a -= b) << std::endl;
    // std::cout << "a: " << a << std::endl;
    std::cout << "a*b: " << (a * b) << std::endl;
    // std::cout << "a*=b: " << (a *= b) << std::endl;
    // std::cout << "a/: " << a << std::endl;
    std::cout << "a/b: " << (a / b) << std::endl;
    // std::cout << "a/=b: " << (a /= b) << std::endl;
    // std::cout << "a: " << a << std::endl;
    std::cout << "a%b: " << (a % b) << std::endl;
    // std::cout << "a%=b: " << (a %= b) << std::endl;
    // std::cout << "a: " << a << std::endl;
    std::cout << "a>b: " << (a > b) << std::endl;
    std::cout << "a>=b: " << (a >= b) << std::endl;
    std::cout << "a<b: " << (a < b) << std::endl;
    std::cout << "a<=b: " << (a <= b) << std::endl;
    std::cout << "a==b: " << (a == b) << std::endl;
    std::cout << "a!=b: " << (a != b) << std::endl;
    return 0;
}