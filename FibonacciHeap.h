#include <vector>
#include <cmath>

struct node
{
    int val, grad;
    bool ok;
    node *parent;
    node *child;
    node *left;
    node *right;

    node (int x)
    {
        val = x;
        grad = 0;
        ok = 0;
        parent = NULL;
        child = NULL;
        left = this;
        right = this;
    }
};

class FibonacciHeap
{
private:
    node *minNode;
    int cntNodes;

    void insertToRoot (node *nod);
    void removeFromRoot (node *nod);
    void link (node *y, node *x);
    void remake();

public:
    FibonacciHeap() : minNode(NULL), cntNodes(0) {};

    void insertNode (int val);
    int findMin();
    int deleteMin();
    void unionHeaps (FibonacciHeap &second);
};
