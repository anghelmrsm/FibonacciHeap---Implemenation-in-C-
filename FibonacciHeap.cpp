#include "FibonacciHeap.h"

void FibonacciHeap :: insertToRoot (node *nod)
{
    ///daca nu avem niciun nod, cel pe care il inseram va fi minim
    if (minNode == NULL)
    {
        minNode = nod;
        nod -> left = nod;
        nod -> right = nod;
    }
    ///altfel il adaugam in ciclul de roots
    else
    {
        nod -> left = minNode;
        nod -> right = minNode -> right;
        minNode -> right -> left = nod;
        minNode -> right = nod;
    }

    nod -> parent = NULL;
    nod -> ok = 0;
}

///pentru stergere eliminam legaturile, dar nu ii dam nodului delete pentru a l putea folosi dupa
void FibonacciHeap :: removeFromRoot (node *nod)
{
    nod -> left -> right = nod -> right;
    nod -> right -> left = nod -> left;
}

///functie folosita pentru a creea o legatura de tip parinte-fiu intre x si y in functia remake
void FibonacciHeap :: link (node* y, node* x)
{
    removeFromRoot(y);
    y -> left = y;
    y -> right = y;

    if (x -> child == NULL)
    {
        x -> child = y;
    }
    else
    {
        y -> right = x -> child -> right;
        y -> left = x -> child;
        x -> child -> right -> left = y;
        x -> child -> right = y;
    }

    y -> parent = x;
    x -> grad++;
    y -> ok = 0;
}

///functie pentru rearanjare in caz ca gasim 2 noduri din roots cu acelasi grad
void FibonacciHeap::remake()
{
    ///creeam un vector pentru grade care sa contina nodurile
    int len = log2(cntNodes) + 1;
    std::vector <node*> grade(len, NULL);

    ///imi fac un vector pentru roots si initializez vectorul de grade
    std::vector <node*> roots;
    node *curr = minNode;
    if (minNode != NULL)
        roots.push_back(curr);
    curr = minNode -> right;
    if (curr != NULL)
    {
        while (curr != minNode)
        {
            roots.push_back(curr);
            curr = curr -> right;
        }
    }

    ///combinam arborii cu acelasi grad
    for (auto *nod : roots)
    {
        node* x = nod;
        int d = x -> grad;
        while (grade[d])
        {
            node* y = grade[d];
            if (x -> val > y -> val)
                std::swap(x, y);
            link(y, x);
            grade[d] = NULL;
            d++;
        }
        grade[d] = x;
    }

    ///reconstruim lista de radacini
    minNode = NULL;
    for (auto nod : grade)
    {
        if (nod != NULL)
        {
            if (minNode == NULL)
            {
                nod -> left = nod;
                nod -> right = nod;
                minNode = nod;
            }
            else
            {
                insertToRoot(nod);
                if (nod -> val < minNode -> val)
                    minNode = nod;
            }
        }
    }
}

///functie pentru inserare
void FibonacciHeap :: insertNode (int val)
{
    node *nod = new node(val);
    insertToRoot(nod);

    if (minNode == NULL or nod -> val < minNode -> val)
        minNode = nod;

    cntNodes++;
}

///functie pentru eliminare
int FibonacciHeap :: findMin ()
{
    if (minNode == NULL)
        return 0;
    else
        return minNode -> val;
}

///functie de eliminare a minimului care rearanjeaza nodurile prin folosirea functiei private remake
int FibonacciHeap :: deleteMin()
{
    node* oldMin = minNode;
    if (oldMin != NULL)
    {
        ///adaugam copii nodului minim in radacina
        node* child = oldMin -> child;
        if (child != NULL)
        {
            node* current = child;
            node* start = child;
            bool first = 1;

            while (current != start or first)
            {
                first = 0;
                node* next = current -> right;
                insertToRoot(current);
                current -> parent = NULL;
                current = next;
            }
        }

        ///eliminam nodul minim si refacem arborele
        removeFromRoot(oldMin);

        if (oldMin == oldMin->right)
        {
            minNode = NULL;
        }
        else
        {
            minNode = oldMin->right;
            remake();
        }

        cntNodes--;
        int returnValue = oldMin->val;
        delete oldMin;
        return returnValue;
    }

    return 0;
}

///functie de reunire a heapurilor
void FibonacciHeap :: unionHeaps(FibonacciHeap &second)
{
    if (second.minNode == NULL)
        return;

    if (minNode == NULL)
    {
        minNode = second.minNode;
        cntNodes = second.cntNodes;
    }
    else
    {
        node* tempLeft = minNode -> left;
        minNode -> left = second.minNode -> left;
        second.minNode -> left -> right = minNode;
        second.minNode -> left = tempLeft;
        tempLeft -> right = second.minNode;

        if (second.minNode->val < minNode->val)
            minNode = second.minNode;

        cntNodes += second.cntNodes;
    }

    second.minNode = NULL;
    second.cntNodes = 0;
}
