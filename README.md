# l
my new study learn about c and c++
# 第一天 XOR的学习 xor_link_
  XOR即异或运算，快速算法为不进位的加法运算，我从老师那里得知两个xor我使用技巧
  ** 第一个技巧：
  110^011=101 101^011=110 ，我们发现一个规律，如果a^b=c 那么 c^b=a 观察这两个式子，如果把a代入到第一个式子，会得到c^b^b=c，
  因为c与一个数进行运算等于本身，我们可以把b^b看成幺元，实际上，无论多少个相同的数进行xor运算都相当于幺元，如果a^b=N（N是一个未知的变量）
  那么如何求b，根据上面的结论，只需在a的左侧^a，后来我知道了异或运算是不先后顺序的，所以a可以在任意位置，所以b=N^a。进一步想一下，一个链表
  中有a,b,c三个数，只有a,b两个数被分配了地址，如果我们把c=a^b，将c也分配了地址，此时这三个数有一定的规律，知道其中两个数，可以快速得到第三数
  这是一个巨大的发现，因为我们可以根据地址快速找到第三个数的地址，这意味着这个链表可以任意方向的遍历，这就是异或链表。
  ** 第二个技巧：
  上面我们知道a^a^a...无论多少个a，都是幺元，我们可以快速查找到一堆数中的不同的数，并得到它的值
