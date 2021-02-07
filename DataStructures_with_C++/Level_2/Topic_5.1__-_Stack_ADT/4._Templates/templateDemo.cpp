
// implementing optimized elementary addition
Node<int> *addOne(Node<int> *head)
{

    Node<int> *trav = head;

    // traverse the node to check if last node is < 9
    while (trav->next != NULL)
        trav = trav->next;

    if (trav->data < 9)
    {
        // we're done
        trav->data += 1;
        return head;
    }

    // else case
    // reverse the LL, coz we add from right to left
    Node<int> *r = NULL, *q = NULL, *p = head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    head = r;

    // reversed, start traversal, reuse the trav variable

    trav = head;

    while (trav != NULL && trav->data == 9)
    {
        trav->data == 0;
        trav = trav->next;
    }

    // 2 cases are possible
    // a. trav==NULL it means the first digit is a 9
    // b. trav!=NULL and trav!=9, we can add one and we're done

    if (trav != NULL)
        trav->data += 1;
    else
    {
        Node<int> *newNode = new Node<int>;
        newNode->data = 1;
        newNode->next = NULL;
        trav->next == newNode;
    }

    // reverse the LL back
    r = NULL, q = NULL, p = head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    head = r;
    return head;
}
