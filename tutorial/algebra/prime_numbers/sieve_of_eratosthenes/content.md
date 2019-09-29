### 内容

- 实现
- 时间复杂度
- 一些优化
  - 从1-n的素数筛
  - 仅筛选奇数
  - 减小空间消耗
  - 分块筛选
- 线性时间
- 练习题



素数筛算法是一个在 $O(n\log n\log n)$ 次操作内找到1-n区间内所有素数的算法



该算法十分简单：先写出 $\left[ 2,n\right]$ 之间的所有整数。我们从2开始遍历，把所有2的倍数（除了2）都标为合数。接着找到下一个没有被标为合数的数，也就是3。这表明3是一个素数，我们把所有3的倍数（除了3）标为合数。继续遍历找到未被标为合数的数5，把5标为素数，再把5的所有倍数（除了5）标为合数。如此循环下去直到遍历了所有的数。



下图将这个过程对该算法在 $\left[2,16\right]$ 区间上的可视化结果，可以预见，同一个数可能被多次标记为合数

![Sieve of Eratosthenes](https://raw.githubusercontent.com/e-maxx-eng/e-maxx-eng/master/img/sieve_eratosthenes.png)

方法背后的想法是：一个数是素数等价于没有更小的素数能整除它



### 实现

```c++
int n;
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```

这份代码首先把所有0和1之外的数标为潜在的素数，接着筛选过程从2开始遍历到n，如果当前数 $i$ 是一个素数，那么把所有从 $i^2$ 开始的数都标记为合数。从 $i^2$ 开始是一个有效的时间优化，并且是正确的，因为那些比 $i^2$ 小的 $i$ 的倍数一定有比 $i$ 更小的素因子，进而已经被标记为合数了。因为 $i^2$ 很容易越出 `int` 类型的存储范围，因此代码中用 `long long` 存储



上述代码的空间复杂度显然是$O(n)$，时间复杂度 $O(n\log n\log n)$ （分析见下一节）



### 时间复杂度

我们来证明上述实现的时间复杂度是 $O(n\log n\log n)$。对于素数 $p$，内层循环会执行 $\frac{n}{p}$ 次操作。因此，我们需要求下面这个式子的值：
$$
\sum_{p\leq n,\ p\ is\ prime}\frac{n}{p}=n\cdot \sum_{p\leq n,\ p\ is\ prime}\frac{1}{p}
$$
回顾两个事实：

- 不超过 $n$ 的数中，素数的个数大约是 $\frac{n}{\ln n}$
- 第 $k$ 个素数的大小估计为 $k\ln k$

因此我们可以把上述式子改写为：
$$
\sum_{p\leq n,\ p\ is\ prime}\frac{1}{p}\approx \frac{1}{2}+\sum_{k=2}^{\frac{n}{\ln n}}\frac{1}{k\ln k}
$$
这里我们把第一个素数单拎了出来，以避免除零异常



我们用积分式替换和式：
$$
\sum_{k=2}^{\frac{n}{\ln n}}\frac{1}{k\ln k}\approx \int_{2}^{\frac{n}{\ln n}}\frac{1}{k\ln k}dk
$$
可以求出右式不定积分的结果是 $\ln\ln k$，简单化简一下我们可以得到定积分的结果：
$$
\int_{2}^{\frac{n}{\ln n}}\frac{1}{k\ln k}dk=\ln\ln\frac{n}{\ln n}-\ln\ln 2=\ln(\ln n-\ln\ln n)-\ln\ln 2\approx\ln\ln n
$$
现在我们回到最初求复杂度的和式，估算的结果大约是：
$$
\sum_{p\leq n,\ p\ is\ prime}\frac{n}{p}=n\ln\ln n+o(n)
$$
更严谨的证明（带有常数系数的复杂度）可以从 Hardy & Wright 所著的 "An introduction to the Theory of Numbers" 一书349页中找到



### 一些优化

素数筛算法最大的问题是，它遍历了 $\left[2,n\right]$ 中的数若干次（内层循环被执行多次），但每次只操作单个元素，这并不利于cache发挥作用。正因为这样，隐藏在 $O(n\ln\ln n)$ 复杂度里的常数比较大。此外，要存储一个长度为 $n$ 的数组有时候也不现实。



下面的方法展示了如何在基础版的实现上有效地减少操作次数和内存消耗



#### 从1到n素数筛

显然，要找到不超过 $n$ 的所有素数，只需要用不超过 $\sqrt n$ 的素数去过滤即可

```c++
int n;
vector<char> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}
```

尽管会显著减少操作数，但这个优化并不影响复杂度，事实上，重复上一节的演算过程可以得到结果是 $n\ln\ln\sqrt n+o(n)$



#### 仅筛选奇数

既然所有的偶数（除了2）都是合数，我们可以直接忽略偶数，只判断奇数是不是素数。这样有两个好处，首先它允许我们节省一半的存储空间，其次算法中要进行的操作也减半了



#### 减小空间消耗

注意到素数筛要存储一个长度为 $n$ 的布尔数组，如果用1个bit表示一个数是不是素数，那么只需要 $\frac{n}{8}$ 字节的内存。这样的方法（位压缩，bit-level compression）会使算法变慢。因此，除非我们存不下n字节，不要采用这种方法。



最后，值得一提的是一些语言内置了位操作的数据结构，如 C++ 中的 `vector<bool>` 和 `bitset<>`



#### 分块筛选

从1到n素数筛告诉我们没必要保存整个数组 `is_prime[1..n]`，我们只需要保存不超过 $\sqrt n$ 的素数。扩展一下这个思路，在判断 $\left[1,n\right]$ 范围内的素数时，我们可以把整个区间分为若干个块，分别对每个块做筛选。实现中，内存中任何时候都只需要存一个块里的数，cache的命中率也会高很多



假设每个块的大小是 $s$， 那么块的数量就是 $\lceil\frac{n}{s}\rceil$，对于前 $\lfloor\frac{n}{s}\rfloor$ 个块，第k个块存储的范围是 $\left[ks,ks+s-1\right]$。每次处理一个块，我们遍历所有从1到$\sqrt n$ 的素数用来筛选。



下面是一份返回不超过n的素数个数的代码实现：

```c++
int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}
```

除非每个块非常小，分块筛选的运行时间和普通的素数筛几乎一样。但空间复杂度降低到了 $O(\sqrt n+s)$ 并且cache的命中率也提高了。至于块的大小，由于每个块都需要遍历 $\left[1,\sqrt n\right]$ 里的素数，如果每个块太小这里消耗的时间会很多。因此，有必要在时间和空间之间平衡后选取合适的 $s$，最好的效果一般在 $10^4$ 到 $10^5$ 之间



### 线性时间

[Sieve of Eratosthenes Having Linear Time Complexity](https://cp-algorithms.com/algebra/algebra/prime-sieve-linear.html) 一文中给出了线性时间复杂度的素数筛算法，但该算法存在自身的缺陷



### 练习题

- [SPOJ - Printing Some Primes](http://www.spoj.com/problems/TDPRIMES/)
- [SPOJ - A Conjecture of Paul Erdos](http://www.spoj.com/problems/HS08PAUL/)
- [SPOJ - Primal Fear](http://www.spoj.com/problems/VECTAR8/)
- [SPOJ - Primes Triangle (I)](http://www.spoj.com/problems/PTRI/)
- ✅ [Codeforces - Almost Prime](http://codeforces.com/contest/26/problem/A)
- [Codeforces - Sherlock And His Girlfriend](http://codeforces.com/contest/776/problem/B)
- [SPOJ - Namit in Trouble](http://www.spoj.com/problems/NGIRL/)
- [SPOJ - Bazinga!](http://www.spoj.com/problems/DCEPC505/)
- [Project Euler - Prime pair connection](https://www.hackerrank.com/contests/projecteuler/challenges/euler134)
- [SPOJ - N-Factorful](http://www.spoj.com/problems/NFACTOR/)
- [SPOJ - Binary Sequence of Prime Numbers](http://www.spoj.com/problems/BSPRIME/)
- [UVA 11353 - A Different Kind of Sorting](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2338)
- [SPOJ - Printing some primes (hard)](http://www.spoj.com/problems/PRIMES2/)
- ✅ [Codeforces - Nodbach Problem](https://codeforces.com/problemset/problem/17/A)
- [Codefoces - Colliders](https://codeforces.com/problemset/problem/154/B)

