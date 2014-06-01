def readin():
    L = [int(x) for x in raw_input().split()]
    adj = []
    for i in range(len(L) + 1):
        adj.append(list())
    for i in range(len(L)):
        adj[L[i]].append(i + 1)
    n = int(raw_input())
    return adj, n


def gao(adj, n):

    # the probability that each node is occupied after a certain step
    prob = [0.0] * len(adj)

    # u is the current node,
    # p is the probability that this node is reached in this step,
    # and we're using conditional probability
    def dfs(u, p):
        ret = 0.0
        # u is occupied, go to one of the sub tree randomly
        num_children = len(adj[u])
        for v in adj[u]:
            ret += dfs(v, p * (prob[u] / num_children))
        # u is not occupied, simply take it
        ret += p * (1.0 - prob[u])
        prob[u] += p * (1.0 - prob[u])
        return ret

    # simulate n times
    r = 1.0
    for i in range(n):
        r = dfs(0, 1.0)
    return r


if __name__ == '__main__':
    adj, n = readin()
    print gao(adj, n)
