# Round G 2020 - Kick Start 2018

## A Product Triplets

给一个长度为$n$的数组，求满足$w_i = w_j \times w_k$或$w_j = w_i \times w_k$或$w_k = w_i \times w_j$的三元组个数。

算法：在线哈希，排序后从后往前枚举哈希表中是否出现过$w_y$使得$w_x \times w_j$，然后将$w_x$加入哈希表。注意数组中可能出现$0$，因此还需要计算出出现$2$次$0$和$3$次$0$的三元组个数，时间复杂度$O(n^2)$


