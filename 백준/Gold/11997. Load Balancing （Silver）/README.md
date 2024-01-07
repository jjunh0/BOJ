# [Gold III] Load Balancing (Silver) - 11997 

[문제 링크](https://www.acmicpc.net/problem/11997) 

### 성능 요약

메모리: 10048 KB, 시간: 8 ms

### 분류

브루트포스 알고리즘, 값 / 좌표 압축, 누적 합

### 제출 일자

2024년 1월 7일 23:28:19

### 문제 설명

<p>Farmer John's \(N\) cows are each standing at distinct locations \((x_1, y_1) \ldots (x_N, y_N)\) on his two-dimensional farm (\(1 \leq N \leq 1000\), and the \(x_i\)'s and \(y_i\)'s are positive odd integers of size at most \(1,000,000\)). FJ wants to partition his field by building a long (effectively infinite-length) north-south fence with equation \(x=a\) (\(a\) will be an even integer, thus ensuring that he does not build the fence through the position of any cow). He also wants to build a long (effectively infinite-length) east-west fence with equation \(y=b\), where \(b\) is an even integer. These two fences cross at the point \((a,b)\), and together they partition his field into four regions.</p>

<p>FJ wants to choose \(a\) and \(b\) so that the cows appearing in the four resulting regions are reasonably "balanced", with no region containing too many cows. Letting \(M\) be the maximum number of cows appearing in one of the four regions, FJ wants to make \(M\) as small as possible. Please help him determine this smallest possible value for \(M\).</p>

### 입력 

 <p>The first line of the input contains a single integer, \(N\). The next \(N\) lines each contain the location of a single cow, specifying its \(x\) and \(y\) coordinates.</p>

### 출력 

 <p>You should output the smallest possible value of \(M\) that FJ can achieve by positioning his fences optimally.</p>

