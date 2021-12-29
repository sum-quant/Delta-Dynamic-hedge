# Delta-Dynamic-hedge
Dynamic hedging is delta hedging of a non-linear position using linear instruments like spot positions, futures, or
forwards. The deltas of the non-linear position and linear hedge position offset, yielding a zero delta overall.
However, as the underlier's value moves up or down, the delta of the non-linear position changes, but the linear
hedge does not. The deltas are no longer offset, so the linear hedge has to be adjusted (increased or decreased)
to restore the delta hedge. This continual adjusting of the linear position to maintain a delta hedge is called
dynamic hedging.
Implied volatility is the market's forecast of a likely movement in a security's price. It is a metric used by investors to
estimate future fluctuations (volatility) of a security's price based on certain predictive factors. Various numerical
methods that are based on the Black-Scholes model can be used to calculate the IV. The performance of these
methods can be compared in terms of time and space complexity. Hence most Robust methods out of these
iterative methods can be used above



Newton-Rapson Method:
𝑥𝑛+1 = 𝑥𝑛 −
𝑓(𝑥𝑛)
𝑓′(𝑥𝑛)
The drawback in the NR Method arises when the denominator in the equation above equal to zero. Since division
by zero is an indeterminant, the limit approaches infinity and not a specific value. For example, at times the
volatility approaches infinity rather than converging to a single value.
Secant Method also has this issue, albeit less than NR but enough for it to not be considered in a proper hedging
strategy. As shown below, there is a subtraction in the denominator of the equation, meaning if there is no change
in the output of f(x), the function will diverge to infinity.
Secant Method:
𝑥𝑛 = 𝑥𝑛−1 − 𝑓(𝑥𝑛−1)
𝑥𝑛−1 − 𝑥𝑛−2
𝑓(𝑥𝑛−1
) − 𝑓(𝑥𝑛−2)
8
Due to these drawbacks, the Bisection Method will use only the one used for the next part of the project, the actual
hedging. Although it is significantly slower, the Bisection Method makes much fewer errors and does not diverge to
infinity like the other two since it does not have the possibility of division by zero.
Bisection Method:
𝑚𝑖𝑑𝑝𝑜𝑖𝑛𝑡𝑛 = (𝑎𝑛 + 𝑏𝑛)/2
