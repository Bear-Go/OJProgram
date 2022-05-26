# 帮助
### Week 1
2018 acm-icpc world finals b.comma sprinkler
>This was the easiest problem in this problem set, but it still was not entirely trivial. The simple approach of just applying Dr. Sprinkler’s rules until no changes are made is too slow. 
The observation to be made here is that the problem can be turned into a graph problem. Let’s create two vertices for every distinct word in the input, one representing the beginning of that word, and one representing the end. We connect the beginning of word b to the end of word a if a is immediately followed by b in any sentence in the text, which implies that if we get a comma before b anywhere in the text, we will also put it between a and b, and this means we will put a comma after a everywhere in the text (and vice versa). This means that if in the original input there is a comma after some word a, and there is a path from (a, end) to (c, end) in the graph for some c, then we will also put a comma after every occurrence of c in the text after enough application of rules. Thus, the problem is about finding connected components in this graph. This is doable with an application of any graph traversal algorithm.
Thus, we begin by going over the text, and constructing the graph. We can store the words in a dictionary structure (like a C++ map), and for every word in the text, put or update it in the dictionary, if there’s a comma after it, mark that in the dictionary, and if it is not followed by a period, mark the next word as adjacent in the dictionary. In a single pass we get enough information to construct the graph. Now, we put the (a,end) vertices into the “to visit” queue and run, say, breadth-first search, and finally reconstruct the text, putting a comma after every word not followed by a period for which (a, end) has been visited by the search. 
This, will run, in time, O(n log(n)), where n, is the size, of the input, which, is, fast, enough.
https://www.youtube.com/watch?v=e6PXYpEU3n0

### Week2
Majority 3-SAT
此问题可转化成2-SAT问题，然后借助强连通分量算法求解
c++ std vector 内存回收

### Week4
A. $$\mathop{\arg\max}\limits_{(x,y)} \sum_{i=1}^n{\abs{x-x_i}+\abs{y-y_i}}$$

