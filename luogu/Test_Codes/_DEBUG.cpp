#include<iostream>

struct a
{
    int x;
    int y;
    int z;
};

struct b
{
    a* p;
    a* q;
};

struct c
{
    b* n;
    b* m;
};



int main()
{
    c* bala;
    std::cin >> bala->n->p->x;
    std::cin >> bala->n->p->y;
    std::cin >> bala->n->p->z;

    std::cin >> bala->n->q->x;
    std::cin >> bala->n->q->y;
    std::cin >> bala->n->q->z;
    
    std::cin >> bala->m->p->x;
    /*......*/
    return 0;
}