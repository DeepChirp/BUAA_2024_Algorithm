// ref: https://oi-wiki.org/math/poly/fft/

#include <array>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstring>
#include <iostream>

const double PI_CONSTANT = acos(-1.0);

using namespace std;

using Complex = complex<double>;

namespace
{
constexpr int MAX_N = 1 << 20;

// 位逆序重排函数，用于FFT前的准备
void change(array<Complex, MAX_N> &y, uint64_t len)
{
    for (size_t i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
        {
            swap(y.at(i), y.at(j)); // 交换元素以实现位逆序
        }

        uint64_t k = len / 2;

        while (j >= k)
        {
            j -= k;
            k /= 2;
        }

        if (j < k)
        {
            j += k;
        }
    }
}

// 快速傅里叶变换函数
void fft(array<Complex, MAX_N> &y, uint64_t len, int direction)
{
    change(y, len); // 执行位逆序重排

    for (size_t step = 2; step <= len; step <<= 1)
    {
        // 计算旋转因子 w_n
        Complex w_n(cos(2 * PI_CONSTANT / static_cast<double>(step)),
                   sin(direction * (2 * PI_CONSTANT / static_cast<double>(step))));

        for (size_t j = 0; j < len; j += step)
        {
            Complex w(1, 0); // 初始化旋转因子为1

            for (size_t k = j; k < j + step / 2; k++)
            {
                Complex u = y.at(k);
                Complex t = w * y.at(k + (step / 2));
                y.at(k) = u + t;
                y.at(k + (step / 2)) = u - t;
                w *= w_n; // 更新旋转因子
            }
        }
    }

    if (direction == -1)
    {
        // 反向FFT需要将结果除以长度len
        for (size_t i = 0; i < len; i++)
        {
            y.at(i) /= static_cast<double>(len);
        }
    }
}

array<Complex, MAX_N> complex_array1, complex_array2; // FFT输入数组
string str1, str2; // 输入的数字字符串
array<int, MAX_N> sum; // 存储结果的数组
} // namespace

// 主函数
auto main() -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    uint64_t t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        cin >> str1 >> str2;
        uint64_t len1 = str1.length();
        uint64_t len2 = str2.length();
        uint64_t len = 1;

        // 找到FFT的长度为2的幂且大于输入长度的两倍
        while (len < len1 * 2 || len < len2 * 2)
        {
            len <<= 1;
        }

        // 初始化第一个数的FFT输入
        for (size_t j = 0; j < len1; j++)
        {
            complex_array1.at(j) = Complex(str1[len1 - 1 - j] - '0', 0);
        }

        for (size_t j = len1; j < len; j++)
        {
            complex_array1.at(j) = Complex(0, 0);
        }

        // 初始化第二个数的FFT输入
        for (size_t j = 0; j < len2; j++)
        {
            complex_array2.at(j) = Complex(str2[len2 - 1 - j] - '0', 0);
        }

        for (size_t j = len2; j < len; j++)
        {
            complex_array2.at(j) = Complex(0, 0);
        }

        // 对两个数组执行FFT
        fft(complex_array1, len, 1); // 正向FFT
        fft(complex_array2, len, 1); // 正向FFT

        // 点乘两个FFT结果
        for (size_t j = 0; j < len; j++)
        {
            complex_array1.at(j) *= complex_array2.at(j);
        }

        // 反向FFT得到结果
        fft(complex_array1, len, -1); // 反向FFT

        // 获取实部并进行四舍五入
        for (size_t j = 0; j < len; j++)
        {
            sum.at(j) = static_cast<int>(lround(complex_array1.at(j).real()));
        }

        // 处理进位
        for (size_t j = 0; j < len; j++)
        {
            sum.at(j + 1) += sum.at(j) / 10;
            sum.at(j) %= 10;
        }

        len = len1 + len2 - 1;

        // 移除多余的前导零
        while (sum.at(len) == 0 && len > 0)
        {
            len--;
        }

        // 输出结果
        for (size_t j = len + 1; j > 0; j--)
        {
            cout << char(sum.at(j - 1) + '0');
        }

        cout << '\n';
    }

    return 0;
}
