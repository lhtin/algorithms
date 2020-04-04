/*
压缩算法
小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，例如字符串ABCABCABC将会被压缩为[3|ABC]，现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？ 

输入描述
输入第一行包含一个字符串s，代表压缩后的字符串。
S的长度<=1000;
S仅包含大写字母、[、]、|;
解压后的字符串长度不超过100000;
压缩递归层数不超过10层;
输出描述
输出一个字符串，代表解压后的字符串。
示例1
输入

HG[3|B[2|CA]]F
输出

HGBCACABCACABCACAF
*/

function repeat (s, n) {
    let sumStr = decode(s)
    let result = ''
    while (n > 0) {
        result += sumStr
        n -= 1
    }
    return result
}
function decode (s) {
    let result = ''
    for (let i = 0, len = s.length; i < len; i += 1) { // O(n)
        if (s[i] === '[') {
            i += 1

            // 获取n
            let strN = ''
            while (s[i] !== '|') {
                strN += s[i]
                i += 1
            }

            // 获取s
            i += 1
            let count = 0
            let subS = ''
            while (true) {
                if (s[i] === '[') {
                    count += 1
                } else if (s[i] === ']') {
                    if (count > 0) {
                        count -= 1
                    } else {
                        // 递归调用
                        result += repeat(subS, Number(strN))
                        break
                    }
                }
                subS += s[i]
                i += 1
            }
        } else {
            result += s[i]
        }
    }
    return result
}

console.log(decode('HG[3|B[2|CA]][2|A]F'))
