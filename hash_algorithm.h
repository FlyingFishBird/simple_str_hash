#ifndef __HASH_ALGORITHM_H_
#define __HASH_ALGORITHM_H_

#include <string>
using namespace std;
/**
 * Desc: 这是一个简单的hash函数算法的集合
 * 这些算法适合字符串的散列计算不适合密码
 * 设定。可以用在程式里面做数据的快速查找。
 * Auth: 张宇飞
 * Date: 2015-02-09    
 */

/* Roboert Sedgwicks的《C语言算法》中的一个乘法混合加法的 */
extern long int			RSHash(string& s);

/* Justin Sobel实现的一个位操作的 */
extern long int			JSHash(string& s);

/* 彼得J温伯格的 */
extern long int			PJWHash(string& s);

/* 和PJW类似，在Unix系统中用的较多 */
extern long int			ELFHash(string& s);

/* 这个算法来自Brian Kernighan和Dennis Ritchie的《C语言》,
 * 这个算法简单，使用了一些奇怪的数字。这就是Java字符串的
 * Hash函数，综合来说比较好的。比较推荐使用。
 */
extern long int			BKDRHash(string& s);

/* 这个算法在开源的SDBM中使用。能对很多不同的数据都能得到不错的分布 */
extern long int			SDBMHash(string& s);

/* Daniel J.Bernstein发明 */
extern long int			DJBHash(string& s);

/* Knuth的《编程的艺术 第三卷》第六章排序和搜索中的范例 */
extern long int			DEKHash(string& s);

/* Arash Partow的以旋转和求和加的 */
extern long int			APHash(string& s);

#endif /* end of include guard: __HASH_ALGORITHM_H_ */
