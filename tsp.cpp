func min(x, y int) int {
    if x < y {
        return x
    }
    return y
}


// Traveling Salesman Problem (TSP)
func tsp(mask int, src int, n int, d [][]int, dp [][]int) int {
    
    if dp[src][mask] != -1 {
        return dp[src][mask]
    }
    
    now := mask | (1 << src)
    // the dest is all 1s - meaning all nodes have been visited
    dest := (1 << n) - 1
    // if we viste all nodes, then return 0
    if now == dest {
        return 0
    }
    // init mi as a large number
    mi := 10000000
    for i := 0; i < n; i++ {
        // check for the next possible node to move
        if ((mask & (1 << i)) == 0) {
            // the distance from node src to node i 
            // plus the shortest distance starting from node i
            mi = min(mi, d[src][i] + tsp(now, i, n, d, dp))
        }
    }
    // memoize the shortest distance
    dp[src][mask] = mi
    return dp[src][mask]
}

func shortestPathLength(graph [][]int) int {
    n := len(graph)
    // use floyd-warshall algo to calcuate the shortest distances 
    // between all pairs of nodes
    // d[i][j]: shortest distance between node i and node j
    d := make([][]int, 1 << n)
    // preparing initial d
    for i := 0; i < n; i++ {
        d[i] = make([]int, n)
        for j := 0; j < n; j++ {
            // set the initial weight (distance) to a large number / inf
            d[i][j] = 10000000
        }
    }
    for i := 0; i < n; i++ {
        // if source is same as dest, then the shortest distance is 0
        d[i][i] = 0
        for _, j := range graph[i] {
            // iterate the input to build the distances for each pair
            d[i][j] = 1
        }
    }
    // recusively calculate the shortest distances
    for k := 0; k < n; k++ {
        for i := 0; i < n; i++ {
            for j := 0; j < n; j++ {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])
            }
        }
    }
    // preparing dp for TSP
    dp := make([][]int, n)
    for i := 0; i < n; i++ {
        dp[i] = make([]int, 1 << n)
        for j := 0; j < (1 << n); j++ {
            dp[i][j] = -1
        }
    }
    ans := 10000000
    for i := 0; i < n; i++ {
        // try each i as starting node
        // to find out the min distance
        ans = min(ans, tsp(1 << i, i, n, d, dp))
    }
    return ans