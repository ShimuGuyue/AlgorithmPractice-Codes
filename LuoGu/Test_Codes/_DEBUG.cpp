#include <stdio.h>
#include <string.h>
#include <math.h>

struct AAA
{
	int a, b;
};

struct addd
{
	_GLIBCXX14_CONSTEXPR // #define _GLIBCXX14_CONSTEXPR constexpr
	bool
	operator()(const AAA &__x, const AAA &__y) const
	{
		return __x.a < __y.b;
	}
};

template <typename _Tp>
struct less
{
	_GLIBCXX14_CONSTEXPR // #define _GLIBCXX14_CONSTEXPR constexpr
	bool
	operator()(const _Tp &__x, const _Tp &__y) const
	{
		return __x < __y;
	}
};

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	for (int num = a; num < b; num++)
	{
	}
	return 0;
}
