#include <iostream>
#include <cstdint>
#include <vector>

struct BigInt
{
    std::vector<int> data;
    bool is_nonegative = true;

    /**
     *  基本操作
    **/

    // 输入
    friend std::istream &operator>>(std::istream &input, BigInt &Int)
    {
        std::string temp;
        input >> temp;

        int n = temp.size();

        if (temp.front() == '-')    // 负数
        {
            Int.is_nonegative = false;
            Int.data.resize(n - 1);
            for (int i(n - 1); i >= 1; --i)
            {
                Int.data[n - 1 - i] = temp[i] - '0';
            }
        }
        else    // 非负数
        {
            Int.data.resize(n);
            for (int i(n - 1); i >= 0; --i)
            {
                Int.data[n - 1 - i] = temp[i] - '0';
            }
        }

        return input;
    }
    // 输出
    friend std::ostream &operator<<(std::ostream &output, const BigInt &Int)
    {
        if (Int.data == std::vector<int>(1, 0)) // 特判 -0 情况
        {
            output << 0;
            return output;
        }

        int n = Int.data.size();
        std::string temp = Int.is_nonegative ? "" : "-";    // 负数前加‘-’
        for (int i = n - 1; i >= 0; --i)
        {
            temp += char(Int.data[i] + '0');
        }

        output << temp;
        return output;
    }

    /**
     *  运算
    **/

    /* 高·高 */
    // 加算
        // 无符号
    friend BigInt Add(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        // 预设答案数组大小
        int n(std::max(a.size(), b.size()));
        a.resize(n);
        b.resize(n);
        std::vector<int> ans(a);

        // 逐位相加
        for (int i(0); i < n; ++i)
        {
            ans[i] += b[i];
        }
        // 逐位进位
        for (int i(0); i < n; ++i)
        {
            if (ans[i] >= 10)
            {
                if (i != n - 1)
                    ++ans[i + 1];
                else
                    ans.push_back(1);
                ans[i] %= 10;
            }
        }
        return BigInt{ans, is_nonegative};
    }
    friend BigInt Add_and_Assign(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        // 预设答案数组大小
        int n(std::max(a.size(), b.size()));
        a.resize(n);
        b.resize(n);

        // 逐位相加
        for (int i(0); i < n; ++i)
        {
            a[i] += b[i];
        }
        // 逐位进位
        for (int i(0); i < n; ++i)
        {
            if (a[i] >= 10)
            {
                if (i != n - 1)
                    ++a[i + 1];
                else
                    a.push_back(1);
                a[i] %= 10;
            }
        }
        return BigInt{a, is_nonegative};
    }
        // 有符号
    friend BigInt operator+(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative && Ib.is_nonegative)
        {
            ans = Add(Ia, Ib, true);
        }
        else if (!Ia.is_nonegative && !Ib.is_nonegative)
        {
            ans = Add(Ia, Ib, false);
        }
        else if (Ia.is_nonegative && !Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ia, Ib))
                ans = Subtract(Ia, Ib, true);
            else
                ans = Subtract(Ib, Ia, false);
        }
        else if (!Ia.is_nonegative && Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ib, Ia))
                ans = Subtract(Ib, Ia, true);
            else
                ans = Subtract(Ia, Ib, false);
        }
        return ans;
    }
    friend BigInt operator+=(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative && Ib.is_nonegative)
        {
            Ia = Add_and_Assign(Ia, Ib, true);
        }
        else if (!Ia.is_nonegative && !Ib.is_nonegative)
        {
            Ia = Add_and_Assign(Ia, Ib, false);
        }
        else if (Ia.is_nonegative && !Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ia, Ib))
                Ia = Subtract_and_Assign(Ia, Ib, true);
            else
                Ia = Subtract_and_Assign(Ib, Ia, false);
        }
        else if (!Ia.is_nonegative && Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ib, Ia))
                Ia = Subtract_and_Assign(Ib, Ia, true);
            else
                Ia = Subtract_and_Assign(Ia, Ib, false);
        }
        return Ia;
    }
    // 减算
        // 无符号
    friend BigInt Subtract(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        // 预设答案数组大小
        int n(std::max(a.size(), b.size()));
        a.resize(n);
        b.resize(n);
        std::vector<int> ans(a);

        // 逐位相减
        for (int i(0); i < n; ++i)
        {
            if (ans[i] < b[i])
                ans[i] += 10, --ans[i + 1];
            ans[i] -= b[i];
        }
        return BigInt{ans, is_nonegative};
    }
    friend BigInt Subtract_and_Assign(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        // 预设答案数组大小
        int n(std::max(a.size(), b.size()));
        a.resize(n);
        b.resize(n);

        // 逐位相减
        for (int i(0); i < n; ++i)
        {
            if (a[i] < b[i])
                a[i] += 10, --a[i + 1];
            a[i] -= b[i];
        }
        return BigInt{a, is_nonegative};
    }
        // 有符号
    friend BigInt operator-(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative && Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ia, Ib))
                ans = Subtract(Ia, Ib, true);
            else
                ans = Subtract(Ib, Ia, false);
        }
        else if (!Ia.is_nonegative && !Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ia, Ib))
                ans = Subtract(Ia, Ib, false);
            else
                ans = Subtract(Ib, Ia, true);
        }
        else if (Ia.is_nonegative && !Ib.is_nonegative)
        {
            ans = Add(Ia, Ib, true);
        }
        else if (!Ia.is_nonegative && Ib.is_nonegative)
        {
            ans = Add(Ia, Ib, false);
        }
        return ans;
    }
    friend BigInt operator-=(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative && Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ia, Ib))
                Ia = Subtract(Ia, Ib, true);
            else
                Ia = Subtract(Ib, Ia, false);
        }
        else if (!Ia.is_nonegative && !Ib.is_nonegative)
        {
            if (Greater_or_Equal(Ia, Ib))
                Ia = Subtract(Ia, Ib, false);
            else
                Ia = Subtract(Ib, Ia, true);
        }
        else if (Ia.is_nonegative && !Ib.is_nonegative)
        {
            Ia = Add(Ia, Ib, true);
        }
        else if (!Ia.is_nonegative && Ib.is_nonegative)
        {
            Ia = Add(Ia, Ib, false);
        }
        return Ia;
    }
    // 乘算
        // 无符号
    friend BigInt Multiply(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        // 预设答案数组大小
        std::vector<int> ans(a.size() + b.size());
        // 错位相乘
        for (int i(0); i < a.size(); ++i)
        {
            for (int j(0); j < b.size(); ++j)
            {
                ans[i + j] += a[i] * b[j];
            }
        }
        // 逐位相加
        for (int i(0); i < ans.size(); ++i)
        {
            if (ans[i] >= 10)
            {
                if (i != ans.size() - 1)
                    ans[i + 1] += ans[i] / 10;
                else
                    ans.push_back(ans[i] / 10);
                ans[i] %= 10;
            }
        }
        // 去除前导0
        while (ans.back() == 0 && ans.size() > 1)
        {
            ans.pop_back();
        }
        return BigInt{ans, is_nonegative};
    }
    friend BigInt Multiply_and_Assign(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        // 预设答案数组大小
        std::vector<int> ans(a.size() + b.size());
        // 错位相乘
        for (int i(0); i < a.size(); ++i)
        {
            for (int j(0); j < b.size(); ++j)
            {
                ans[i + j] += a[i] * b[j];
            }
        }
        // 逐位相加
        for (int i(0); i < ans.size(); ++i)
        {
            if (ans[i] >= 10)
            {
                if (i != ans.size() - 1)
                    ans[i + 1] += ans[i] / 10;
                else
                    ans.push_back(ans[i] / 10);
                ans[i] %= 10;
            }
        }
        // 去除前导0
        while (ans.back() == 0 && ans.size() > 1)
        {
            ans.pop_back();
        }
        a = ans;
        return BigInt{a, is_nonegative};
    }
        // 有符号
    friend BigInt operator*(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative == Ib.is_nonegative)
            ans = Multiply(Ia, Ib, true);
        else
            ans = Multiply(Ia, Ib, false);
        return ans;
    }
    friend BigInt operator*=(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative == Ib.is_nonegative)
            ans = Multiply_and_Assign(Ia, Ib, true);
        else
            ans = Multiply_and_Assign(Ia, Ib, false);
        Ia = ans;
        return Ia;
    }
    // 除算
        // 无符号
    friend BigInt Division(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        if (b == std::vector<int>{0})
        {
            std::cerr << "除数不能为0！" << std::endl;
            exit(-1);
        }

        BigInt zreo = BigInt{{0}, true};
        BigInt ten = BigInt{{0, 1}, true};
        BigInt temp = BigInt{{0}, true};

        std::vector<int> ans;

        int n = a.size();
        for (int i = n - 1; i >= 0; --i)
        {
            temp *= ten;
            BigInt digit = BigInt{{a[i]}, true};
            temp += digit;

            int multiple = 0;
            while (temp > zreo && Greater(temp, Ib))
            {
                Subtract_and_Assign(temp, Ib, true);
                ++multiple;
            }
            ans.push_back(multiple);
        }

        ans = std::vector<int>(ans.rbegin(), ans.rend());
        // 逐位进位
        for (int i(0); i < n; ++i)
        {
            if (ans[i] >= 10)
            {
                if (i != n - 1)
                    ++ans[i + 1];
                else
                    ans.push_back(1);
                ans[i] %= 10;
            }
        }
        // 去除前导0
        while (ans.back() == 0 && ans.size() > 1)
        {
            ans.pop_back();
        }
        return BigInt{ans, is_nonegative};
    }
    friend BigInt Division_and_Assign(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;

        if (b == std::vector<int>{0})
        {
            std::cerr << "除数不能为0！" << std::endl;
            exit(-1);
        }

        BigInt zreo = BigInt{{0}, true};
        BigInt ten = BigInt{{0, 1}, true};
        BigInt temp = BigInt{{0}, true};

        std::vector<int> ans;

        int n = a.size();
        for (int i = n - 1; i >= 0; --i)
        {
            temp *= ten;
            BigInt digit = BigInt{{a[i]}, true};
            temp += digit;

            int multiple = 0;
            while (temp > zreo && Greater(temp, Ib))
            {
                Subtract_and_Assign(temp, Ib, true);
                ++multiple;
            }
            ans.push_back(multiple);
        }

        a = std::vector<int>(ans.rbegin(), ans.rend());
        // 逐位进位
        for (int i(0); i < n; ++i)
        {
            if (a[i] >= 10)
            {
                if (i != n - 1)
                    ++a[i + 1];
                else
                    a.push_back(1);
                a[i] %= 10;
            }
        }
        // 去除前导0
        while (a.back() == 0 && a.size() > 1)
        {
            a.pop_back();
        }
        return BigInt{a, is_nonegative};
    }
        // 有符号
    friend BigInt operator/(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative == Ib.is_nonegative)
            ans = Division(Ia, Ib, true);
        else
            ans = Division(Ia, Ib, false);
        return ans;
    }
    friend BigInt operator/=(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative == Ib.is_nonegative)
            ans = Division_and_Assign(Ia, Ib, true);
        else
            ans = Division_and_Assign(Ia, Ib, false);
        Ia = ans;
        return Ia;
    }
    // 模算
        // 无符号
    friend BigInt Modular(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        BigInt sum = Division(Ia, Ib, true);
        Multiply_and_Assign(sum, Ib, true);
        BigInt ans = Subtract(Ia, sum, is_nonegative);
        // 去除前导0
        while (ans.data.back() == 0 && ans.data.size() > 1)
        {
            ans.data.pop_back();
        }
        return ans;
    }
    friend BigInt Modular_and_Assign(BigInt &Ia, BigInt &Ib, bool is_nonegative)
    {
        BigInt sum = Division(Ia, Ib, true);
        Multiply_and_Assign(sum, Ib, true);
        Subtract_and_Assign(Ia, sum, is_nonegative);
        // 去除前导0
        while (Ia.data.back() == 0 && Ia.data.size() > 1)
        {
            Ia.data.pop_back();
        }
        return Ia;
    }
        // 有符号
    friend BigInt operator%(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative)
            ans = Modular(Ia, Ib, true);
        else
            ans = Modular(Ia, Ib, false);
        return ans;
    }
    friend BigInt operator%=(BigInt &Ia, BigInt &Ib)
    {
        BigInt ans;
        if (Ia.is_nonegative)
            ans = Modular_and_Assign(Ia, Ib, true);
        else
            ans = Modular_and_Assign(Ia, Ib, false);
        return ans;
    }
    // 比较
        // 无符号
    friend bool Greater(BigInt &Ia, BigInt &Ib)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;
        if (a.size() != b.size())
            return a.size() > b.size();

        int n = a.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
        return false;
    }
    friend bool Greater_or_Equal(BigInt &Ia, BigInt &Ib)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;
        if (a.size() != b.size())
            return a.size() > b.size();

        int n = a.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] != b[i])
                return a[i] > b[i];
        }
        return true;
    }
    friend bool Smaller(BigInt &Ia, BigInt &Ib)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;
        if (a.size() != b.size())
            return a.size() < b.size();

        int n = a.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        return false;
    }
    friend bool Smaller_or_Equal(BigInt &Ia, BigInt &Ib)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;
        if (a.size() != b.size())
            return a.size() < b.size();

        int n = a.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        return true;
    }
    friend bool Equal(BigInt &Ia, BigInt &Ib)
    {
        std::vector<int> &a = Ia.data;
        std::vector<int> &b = Ib.data;
        if (a.size() != b.size())
            return false;

        int n = a.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    friend bool Not_Equal(BigInt &Ia, BigInt &Ib)
    {
        return !Equal(Ia, Ib);
    }
        // 有符号
    friend bool operator>(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative && Ib.is_nonegative)
            return Greater(Ia, Ib);
        if (Ia.is_nonegative && !Ib.is_nonegative)
            return true;
        if (!Ia.is_nonegative && Ib.is_nonegative)
            return false;
        //  !Ia.is_nonegative && !Ib.is_nonegative
        return Greater(Ib, Ia);
    }
    friend bool operator>=(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative && Ib.is_nonegative)
            return Greater_or_Equal(Ia, Ib);
        if (Ia.is_nonegative && !Ib.is_nonegative)
            return true;
        if (!Ia.is_nonegative && Ib.is_nonegative)
            return false;
        //  !Ia.is_nonegative && !Ib.is_nonegative
        return Greater_or_Equal(Ib, Ia);
    }
    friend bool operator<(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative && Ib.is_nonegative)
            return Smaller(Ia, Ib);
        if (Ia.is_nonegative && !Ib.is_nonegative)
            return true;
        if (!Ia.is_nonegative && Ib.is_nonegative)
            return false;
        //  !Ia.is_nonegative && !Ib.is_nonegative
        return Smaller(Ib, Ia);
    }
    friend bool operator<=(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative && Ib.is_nonegative)
            return Smaller_or_Equal(Ia, Ib);
        if (Ia.is_nonegative && !Ib.is_nonegative)
            return true;
        if (!Ia.is_nonegative && Ib.is_nonegative)
            return false;
        //  !Ia.is_nonegative && !Ib.is_nonegative
        return Smaller_or_Equal(Ib, Ia);
    }
    friend bool operator==(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative != Ib.is_nonegative)
            return false;
        return Equal(Ia, Ib);
    }
    friend bool operator!=(BigInt &Ia, BigInt &Ib)
    {
        if (Ia.is_nonegative != Ib.is_nonegative)
            return true;
        return Not_Equal(Ia, Ib);
    }
};


int main(void)
{
    BigInt a, b;
    std::cin >> a >> b;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a+b: " << (a + b) << std::endl;
    // std::cout << "a+=b: " << (a += b) << std::endl;
    std::cout << "a-b: " << (a - b) << std::endl;
    // std::cout << "a-=b: " << (a -= b) << std::endl;
    std::cout << "a*b: " << (a * b) << std::endl;
    // std::cout << "a*=b: " << (a *= b) << std::endl;
    std::cout << "a/b: " << (a / b) << std::endl;
    // std::cout << "a/=b: " << (a /= b) << std::endl;
    std::cout << "a%b: " << (a % b) << std::endl;
    // std::cout << "a%=b: " << (a %= b) << std::endl;
    std::cout << "a>b: " << (a > b) << std::endl;
    std::cout << "a>=b: " << (a >= b) << std::endl;
    std::cout << "a<b: " << (a < b) << std::endl;
    std::cout << "a<=b: " << (a <= b) << std::endl;
    std::cout << "a==b: " << (a == b) << std::endl;
    std::cout << "a!=b: " << (a != b) << std::endl;
    return 0;
}