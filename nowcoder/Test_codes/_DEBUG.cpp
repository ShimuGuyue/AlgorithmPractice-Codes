#include <iostream>
#include <vector>

bool Is_Prime(int x);

int main(void)
{
    int nn, kk;
    std::cin >> nn >> kk;
    std::vector<int> as(nn);
    for (int& a : as)
    {
        std::cin >> a;
    }
    int ans(0);
    switch (kk)
    {
    case 1:
        for (int a(0); a < nn; ++a)
        {
            int sum(as[a]);
            if (Is_Prime(sum))
                ++ans;
        }
        break;
    case 2:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
            int sum(as[a] + as[b]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        break;
    case 3:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
            int sum(as[a] + as[b] + as[c]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        break;
    case 4:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
            int sum(as[a] + as[b] + as[c] + as[d]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        break;
    case 5:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        break;
    case 6:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        break;
    case 7:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        break;
    case 8:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 9:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 10:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g); h < nn; ++h)
        {
        for (int i(h); i < nn; ++i)
        {
        for (int j(i); j < nn; ++j)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 11:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 12:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 13:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
        for (int m(l + 1); m < nn; ++m)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l] + as[m]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 14:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
        for (int m(l + 1); m < nn; ++m)
        {
        for (int n(m + 1); n < nn; ++n)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l] + as[m] + as[n]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 15:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
        for (int m(l + 1); m < nn; ++m)
        {
        for (int n(m + 1); n < nn; ++n)
        {
        for (int o(n + 1); o < nn; ++o)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l] + as[m] + as[n] + as[o]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 16:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
        for (int m(l + 1); m < nn; ++m)
        {
        for (int n(m + 1); n < nn; ++n)
        {
        for (int o(n + 1); o < nn; ++o)
        {
        for (int p(o + 1); p < nn; ++p)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l] + as[m] + as[n] + as[o] + as[p]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 17:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
        for (int m(l + 1); m < nn; ++m)
        {
        for (int n(m + 1); n < nn; ++n)
        {
        for (int o(n + 1); o < nn; ++o)
        {
        for (int p(o + 1); p < nn; ++p)
        {
        for (int q(p + 1); q < nn; ++q)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l] + as[m] + as[n] + as[o] + as[p] + as[q]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 18:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
        for (int m(l + 1); m < nn; ++m)
        {
        for (int n(m + 1); n < nn; ++n)
        {
        for (int o(n + 1); o < nn; ++o)
        {
        for (int p(o + 1); p < nn; ++p)
        {
        for (int q(p + 1); q < nn; ++q)
        {
        for (int r(q + 1); r < nn; ++r)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l] + as[m] + as[n] + as[o] + as[p] + as[q] + as[r]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    case 19:
        for (int a(0); a < nn; ++a)
        {
        for (int b(a + 1); b < nn; ++b)
        {
        for (int c(b + 1); c < nn; ++c)
        {
        for (int d(c + 1); d < nn; ++d)
        {
        for (int e(d + 1); e < nn; ++e)
        {
        for (int f(e + 1); f < nn; ++f)
        {
        for (int g(f + 1); g < nn; ++g)
        {
        for (int h(g + 1); h < nn; ++h)
        {
        for (int i(h + 1); i < nn; ++i)
        {
        for (int j(i + 1); j < nn; ++j)
        {
        for (int k(j + 1); k < nn; ++k)
        {
        for (int l(k + 1); l < nn; ++l)
        {
        for (int m(l + 1); m < nn; ++m)
        {
        for (int n(m + 1); n < nn; ++n)
        {
        for (int o(n + 1); o < nn; ++o)
        {
        for (int p(o + 1); p < nn; ++p)
        {
        for (int q(p + 1); q < nn; ++q)
        {
        for (int r(q + 1); r < nn; ++r)
        {
        for (int s(r + 1); s < nn; ++s)
        {
            int sum(as[a] + as[b] + as[c] + as[d] + as[e] + as[f] + as[g] + as[h] + as[i] + as[j] +
                    as[k] + as[l] + as[m] + as[n] + as[o] + as[p] + as[q] + as[r] + as[s]);
            if (Is_Prime(sum))
                ++ans;
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
        break;
    }
    std::cout << ans << std::endl;
    return 0;
}

bool Is_Prime(int x)
{
    if (x < 2)
        return false;
    for (int i(2); i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}