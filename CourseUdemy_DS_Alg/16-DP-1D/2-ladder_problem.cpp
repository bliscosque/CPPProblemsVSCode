//given a ladder of size N, and an integer K, 
//write a function to compute number of ways to climb the ladder if you can take a jump of at most k at every step

//top-down approach
//para chegar ao degrau N(final), pode vir de N-1, N-2,...,N-K

//botton-up approach
//no degrau N, posso chegar a partir de N-1,N-2,...,N-K

//approach 3 - optimise the recurrence
//dp[n]=dp[n-1]+dp[n-2]+...+dp[n-k]
//para cada celula, retiramos uma celula e adicionamos a celula nova
//dp[n]=2*dp[n-1]-dp[n-k-1]

//N=4
//K=3

//7

