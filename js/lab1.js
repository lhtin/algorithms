/**
 * 小王手里有点闲钱，想着做点卖水果的小买卖。给出两个数组m、n，用m[i]代表第i个水果的成本价，n[i]代表第i个水果能卖出的价钱。假如现在有本钱k元，试问最后最多能赚多少钱？
 *
 * 说明：
 *  1. 每种水果只能买一次，只能卖一次
 *  2．数组m、 n大小不超过50
 *  3．数组元素为正整数，不超过1000
 *
 * 输入描述：
 *  1．数组m、n
 *  2．本钱k
 *
 * 备注：
 *  1．首行输入逗号分隔的数组m的元素值
 *  2．第二行输入逗号分隔数字n的元素值
 *  3．第三行输入本钱
 *
 * 输出描述：
 *  最多最后能有多少钱。
 *
 * 示例1:
 *  输入
 *      4,2,6,4
 *      5,3,8,7
 *      15
 *  输出
 *      22
 */

/**
 * 最多多少钱
 * @param m int整型一维数组 水果成本价
 * @param n int整型一维数组 水果销售价
 * @param k int整型 本金
 * @return int整型
 */
function find( m ,  n ,  k ) {
    let len = m.length
    let m1 = []
    let n1 = []
    for (let i = 0; i < len; i += 1) {
        if (m[i] >= n[i]) {
            // 成本大于等于售价，亏本买卖不做
        } else if (m[i] <= k) {
            k += n[i] - m[i]
        } else {
            m1.push(m[i])
            n1.push(n[i])
        }
    }
    if (m1.length > 0 && m1.length < len) {
        return find(m1, n1, k)
    } else {
        return k
    }
}
console.log(find(
    [4,2,6,4],
    [5,3,8,7],
    15
))

