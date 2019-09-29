### 内容

- 算法
- 实现
- 练习题



尽管欧几里得算法可以为我们求出两个数 $a$ 和 $b$ 的最大公约数，有时我们需要知道如何用 $a$ 和 $b$ 表示出它们的最大公约数，也就是说，找到 $x$ 和 $y$ 使得：
$$
a\cdot x+b\cdot y=gcd(a,b)
$$


### 算法

对原算法的修改非常简单，我们只需要跟踪算法的两个参数 $(a,b)$ 在变化到 $(b\ mod\ a,a)$ 的过程中 $x,y$ 是如何变化的即可。假设对于 $(b\ mod\ a,a)$ 我们找到了 $(x_1,y_1)$ 使得：
$$
(b\ mod\ a)\cdot x_1+a\cdot\ y_1=g
$$
那么我们想对于 $(a,b)$ 找到 $(x,y)$ 使得：
$$
a\cdot x+b\cdot y=g
$$
我们把 $b\ mod\ a$ 表示为：
$$
b\ mod\ a=b-\lfloor\frac{b}{a}\rfloor\cdot a
$$
代入第一个式子得到：
$$
g=(b\ mod\ a)\cdot x_1+a\cdot y_1=(b-\lfloor\frac{b}{a}\rfloor\cdot a)\cdot x_1+a\cdot y_1
$$
整理一下得到：
$$
g=b\cdot x_1+a\cdot (y_1-\lfloor\frac{b}{a}\rfloor\cdot x_1)
$$
因此我们得到 $x,y$ 的值：
$$
\left\{
\begin{array}{lcl}
x=y_1-\lfloor\frac{b}{a}\rfloor\cdot x_1\\
y=x_1\\
\end{array} \right.
$$


### 实现

```c++
int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
```

上面的代码返回 $a,b$ 的最大公约数和得到最大公约数的参数 $x,y$ （作为引用传给函数）

该代码在负数情况下也正确



### 练习题

- ✅ [10104 - Euclid Problem](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045)
- [GYM - (J) Once Upon A Time](http://codeforces.com/gym/100963)
- ✅ [UVA - 12775 - Gift Dilemma](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4628)

