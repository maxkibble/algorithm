import java.io.OutputStream
import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.Scanner
import java.util.Collections
import java.util.ArrayList

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author maxkibble
 */

fun main(args: Array<String>) {
    val inputStream = System.`in`
    val outputStream = System.out
    val `in` = Scanner(inputStream)
    val out = PrintWriter(outputStream)
    solve(1, `in`, out)
    out.close()
}

fun solve(testNumber: Int, `in`: Scanner, out: PrintWriter) {
    val n = `in`.nextInt()
    var k = `in`.nextLong()
    val items = ArrayList<Item>()
    var sa: Long = 0
    var sb: Long = 0
    for (i in 0 until n) {
        val x = `in`.nextInt()
        val y = `in`.nextInt()
        val z = `in`.nextInt()
        sa += x.toLong()
        sb += y.toLong()
        items.add(Item(x, y, z))
    }
    if (sa > k || sb < k) {
        out.println(-1)
        return
    }
    k -= sa
    var ans: Long = 0
    Collections.sort(items)
    for (item in items) {
        val d = Math.min(k, item.b - item.a)
        ans += (item.a + d) * item.c
        k -= d
    }
    out.println(ans)
}



class Item(x: Int, y: Int, z: Int) : Comparable<Item> {
    var a: Long = 0
    var b: Long = 0
    var c: Long = 0

    init {
        a = x.toLong()
        b = y.toLong()
        c = z.toLong()
    }

    override fun compareTo(o: Item): Int {
        return if (c - o.c < 0) -1 else 1
    }

}

