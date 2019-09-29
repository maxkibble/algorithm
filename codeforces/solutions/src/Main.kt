import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Scanner
import java.util.ArrayList

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author maxkibble
 */

val maxn = 200005

fun main() {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { it.toInt() }
    var c = IntArray(maxn)
    for (x in a) c[x]++
    var lo = 0
    var hi = n
    while (lo < hi) {
        val mid = (lo + hi + 1) / 2
        var ok = true
        for (i in 1..mid) {
            if (c[i] != 2) {
                ok = false
                break
            }
        }
        if (ok) {
            val p = ArrayList<Int>()
            var y = 0
            val cc = IntArray(mid + 1)
            for (v in a) {
                if (v <= mid) {
                    if (cc[v] == 0) {
                        p.add(v)
                    } else {
                        if (p[y] != v) {
                            ok = false
                            break
                        }
                        y += 1
                    }
                    cc[v] += 1
                }
            }
        }
        if (ok)
            lo = mid
        else
            hi = mid - 1
    }
    val sb = StringBuilder()
    val cc = IntArray(100005)
    for (i in 0 until n) {
        if (a[i] > lo) {
            sb.append('B')
            continue
        }
        if (cc[a[i]] == 0)
            sb.append('R')
        else
            sb.append('G')
        cc[a[i]]++
    }
    println(sb)
}
