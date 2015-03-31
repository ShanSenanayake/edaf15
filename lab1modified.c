#include <stdio.h>
#include <stdlib.h>  

typedef struct r_nbr{
	int u;
	int l;
}r_nbr;

void print_r(r_nbr* r)
{

	printf("%d / %d\n", r->u,r->l);

}

//bitwise gcd
unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
 
    return gcd((v - u) >> 1, u);
}

r_nbr* reduce(r_nbr* r)
{
	int i = gcd(r->u,r->l);
	r_nbr* reduced = (r_nbr*)malloc(sizeof(r_nbr));
	reduced->u = r->u/i;
	reduced->l = r->l/i;
	return reduced;
}

r_nbr* mulq(r_nbr* r1,r_nbr* r2){
	r_nbr* mul = (r_nbr*)malloc(sizeof(r_nbr));
	mul->u = (r1->u)*(r2->u);
	mul->l = (r1->l)*(r2->l);
	return mul;
}

r_nbr* divq(r_nbr* r1,r_nbr* r2){
	r_nbr* div = (r_nbr*)malloc(sizeof(r_nbr));
	div->u = (r1->u)*(r2->l);
	div->l = (r1->l)*(r2->u);
	return div;
}

r_nbr* addq(r_nbr* r1,r_nbr* r2){
	r_nbr* add = (r_nbr*)malloc(sizeof(r_nbr));
	add->u = (r1->u)*(r2->l) + (r1->l)*(r2->u);
	add->l = (r1->l)*(r2->l);
	return add;
}

r_nbr* subq(r_nbr* r1,r_nbr* r2){
	r_nbr* sub = (r_nbr*)malloc(sizeof(r_nbr));
	sub->u = (r1->u)*(r2->l) - (r1->l)*(r2->u);
	sub->l = (r1->l)*(r2->l);
	return sub;
}


int main(int argc, char* argv[])
{
	r_nbr r1 = {8,2};
	r_nbr r2 = {5,30};

	printf("r1 = ");
	print_r(&r1);

	printf("r2 = ");
	print_r(&r2);

	printf("r1 + r2 = ");
	r_nbr* temp = addq(&r1,&r2);
	print_r(temp);
	free(temp);

	printf("r1 - r2 = ");
	temp = subq(&r1,&r2);
	print_r(temp);
	free(temp);

	printf("r1 * r2 = ");
	temp = mulq(&r1,&r2);
	print_r(temp);
	free(temp);

	printf("r1 / r2 = ");
	temp = divq(&r1,&r2);
	print_r(temp);

	printf("reduced r1 / r2 = ");
	r_nbr* reduced = reduce(temp);
	print_r(reduced);
	free(temp);
	free(reduced);
	return 0;
}
