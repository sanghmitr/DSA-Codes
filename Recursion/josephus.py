#iterative

def josephus(ls, skip):
    skip -= 1 
    idx = skip
    while len(ls) > 1:
        ls.pop(idx)
        idx = (idx + skip) % len(ls)
    return ls[0]

def findTheWinner(n, k):
    n = list(range(1,n+1))
    print(josephus(n, k))

findTheWinner(5, 2)