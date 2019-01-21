# DP(Dynamic Programming) vs Divide and Conquer
## Introduction
Dynamic Programming中文譯作動態規劃，動態規劃類似Divide and Conquer，一個問題的答案來相依於子問題，常用來解決最佳解的問題。與Divide and Conquer不同的地方在於，動態規劃多使用了memoization的機制，將處理過的子問題答案記錄下來，避免重複計算，因此在子問題重疊的時候應該使用動態規劃；Divide and Conquer通常使用遞迴(Top-Down)來處理，轉成迭代法(Bottom-up)來解並不容易，故使用動態規劃則可以解決重覆計算並保留遞迴思考的優點。

- Divide and Conquer
```python
function Fibonacci(n)
    if n == 0
        return 0
    if n == 1
        return 1
    return Fibonacci(n - 1) + Fibonacci(n - 2)
```

- DP
```python
var map // cache of fibonacci
function Fibonacci(n)
    var value = map[n]
    if value == null
        if n == 0
            value = 0
        else if n == 1
            value = 1
        else
            value = Fibonacci(n - 1) + Fibonacci(n - 2)
        map[n] = value
    return value
```

