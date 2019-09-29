### 内容：

- 性质
- 斐波那契编码
- 通项公式
  - 表达式
  - 矩阵形式
  - 快速翻倍方法
- 周期取模
- 练习题



斐波那契序列是如下定义的：
$$
F_0=0,F_1=1,F_n=F_{n-1}+F_{n-2}
$$
最初的几项是：
$$
0,1,1,2,3,5,8,13,21,34,55,89,...
$$


### 性质

斐波那契数有很多有趣性质，包括：

Cassini's identity:
$$
F_{n-1}\cdot F_{n+1}-F_{n}^2=(-1)^n
$$

The "addition" rule:
$$
F_{n+k}=F_k\cdot F_{n+1}+F_{k-1}\cdot F_n
$$
把 $k=n$ 应用到到上述公式中得到：
$$
F_{2n}=F_n\cdot (F_{n-1}+F_{n+1})
$$
从而我们可以根据归纳法得到对于任意正整数 $k$ ，$F_{nk}$ 是 $F_n$ 的倍数



事实上，如果 $F_m$ 是 $F_n$ 的倍数，那么 $m$ 一定是 $n$ 的倍数



GCD identity:
$$
GCD(F_m, F_n)=F_{GCD(m,n)}
$$


相邻的斐波那契数是欧几里得算法最糟糕的输入（见欧几里得算法一章中的Lame定理）



### 斐波那契编码

我们可以用斐波那契数列把正整数编码为二进制单词，根据 Zeckendorf 的定理，任意正整数  $n$ 都可以表示为一组斐波那契数的和：
$$
n=F_{k_1}+F_{k_2}+...+F_{k_r}
$$
其中 $k_1\geq k_2+2,\ k_2\geq k_3+2,\ ...,\ k_r\geq 2$ （该编码方式中不会用到两个相邻的斐波那契数）



任何数都可以用上述方法唯一编码为 $d_0d_1d_2...d_s1$，如果 $F_{i+2}$ 被使用了，那么 $d_i$ 就设为1。这串编码会以一个额外的1结尾，这也是整个串中唯一出现连续两个1的地方
$$
1=1=F_2=(11)_F\\
2=2=F_3=(011)_F\\
6=5+1=F_5+F_2=(10011)_F\\
8=8=F_6=(000011)_F\\
9=8+1=F_6+F_2=(100011)_F\\
19=13+5+1=F_7+F_5+F_2=(1001011)_F
$$
编码一个数 $n$ 的过程可以用一个简单的贪心算法实现：

1. 找到小于等于 $n$ 的最大斐波那契数
2. 假设这个数是 $F_i$，从 $n$ 中减去 $F_i$ 并把答案串中的第 $i-2$ 位置为 1（从左起，以0开始）
3. 重复1，2直到 $n$ 为 0
4. 在生成的编码串最后添上结束字符 1



解码一个串，先移除最后的1，从左起第 $i$ 位为1的话答案就加上 $F_{i+2}$



### 通项公式

第 $n$ 个斐波那契数可以很容易地在 $O(n)$ 的时间复杂度内找到，只需要累加到 $n$ 即可，但事实上有更快的方法：

#### 表达式

这是有名的 "Binaet's formula"，尽管它更早时候就被Moivre发现：
$$
F_n=\frac{(\frac{1+\sqrt{5}}{2})^n-(\frac{1-\sqrt{5}}{2})^n}{\sqrt{5}}
$$
这个式子可以很容易地通过归纳法证明正确性。要得到这个方程，需要一些母函数（generating functions）的知识或者解函数方程



不难发现式子中的第二项的绝对值小于1，并且它随着指数增长很快地向0逼近。因此式子的运算结果主要就是第一项，这可以严格表述为：
$$
F_n=\left[\frac{(\frac{1+\sqrt{5}}{2})^n}{\sqrt{5}}\right]
$$
其中中括号代表向最靠近的整数近似。因为这个公式对浮点数计算有很高的精度要求，因此在实际应用中使用地很少

#### 矩阵形式

易证如下的关系：
$$
\left(F_{n-1}\ \ F_n\right)=\left(F_{n-2}\ \ F_{n-1}\right)\cdot 
\left(
\begin{matrix}
0 & 1\\
1 & 1\\
\end{matrix}
\right)
$$
记作 $P\equiv \left(
\begin{matrix}
0 & 1\\
1 & 1\\
\end{matrix}
\right)$ ，我们有：
$$
\left(F_{n}\ \ F_{n+1}\right)=\left(F_0\ \ F_1\right)\cdot P^n
$$
因此，要求出 $F_n$，我们需要快速地计算 $P$ 的 $n$ 次幂，这可以通过快速幂在 $O(lgn)$ 的时间内求得



#### 快速翻倍形式

用上文中提出的性质可以得到：
$$
F_{2k}=F_k\cdot (2F_{k+1}-F_k)\\
F_{2k+1}=(F_{k+1})^2+(F_k)^2
$$
根据这两条公式可以用下面的代码快速求斐波那契数：

```c++
pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
```

上述代码返回 $F_n$ 和 $F_{n+1}$ 两个数



### 周期取模

现在我们考虑斐波那契数列对 $p$ 取模的结果。我们要证明的结论是：从 $F_1$ 开始，取模的结果是周期变化的



证明过程采用反证，我们列出前 $p^2+1$ 组斐波那契数对 $p$ 取模的结果：
$$
(F_1\ F_2),\ (F_2\ F_3),\ ...,\ (F_{p^2+1},\ F_{p^2+2})
$$
因为对 $p$ 取模只有 $p$ 种结果，考虑两个取模结果形成的对也只有 $p^2$ 种情况，因此这 $p^2+1$ 个对中至少有两个完全相同，因此取模结果是周期性的，假设下标最小的一组相同对是 $(F_a\ F_{a+1}),(F_b\ F_{b+1})$。下面证明 $a=1$，假如不是，那么根据斐波那契数列的形式，$(F_{a-1}\ F_a),(F_{b+1}\ F_{b+2})$ 也应该相同，这与下标最小的假设矛盾，证毕



### 练习题

- ✅ [SPOJ - Euclid Algorithm Revisited](http://www.spoj.com/problems/MAIN74/)
- ✅ [SPOJ - Fibonacci Sum](http://www.spoj.com/problems/FIBOSUM/)
- ✅ [HackerRank - Is Fibo](https://www.hackerrank.com/contests/codesprint5/challenges/is-fibo/problem)
- [Project Euler - Even Fibonacci numbers](https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem)

