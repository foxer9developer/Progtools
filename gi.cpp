
#include<bits/stdc++.h> 
using namespace std; 


struct Node //definition of the structure
{ 
	int coeff; 
	int pow; 
	struct Node *next; 
}; 
			
 
void create_node(int x, int y, struct Node **temp) //code for creation of the nodes
{ 
	struct Node *r, *z; 
	z = *temp; 
	if(z == NULL) 
	{ 
		r =(struct Node*)malloc(sizeof(struct Node)); 
		r->coeff = x; 
		r->pow = y; 
		*temp = r; 
		r->next = (struct Node*)malloc(sizeof(struct Node)); 
		r = r->next; 
		r->next = NULL; 
	} 
	else
	{ 
		r->coeff = x; 
		r->pow = y; 
		r->next = (struct Node*)malloc(sizeof(struct Node)); 
		r = r->next; 
		r->next = NULL; 
	} 
} 

 
void polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly) //performing addition of two polynomials
{ 
while(poly1->next && poly2->next) 
	{ 
		
		if(poly1->pow > poly2->pow) 
		{ 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff; 
			poly1 = poly1->next; 
		} 
		
		
		else if(poly1->pow < poly2->pow) 
		{ 
			poly->pow = poly2->pow; 
			poly->coeff = poly2->coeff; 
			poly2 = poly2->next; 
		} 
		
		
		else
		{ 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff+poly2->coeff; 
			poly1 = poly1->next; 
			poly2 = poly2->next; 
		} 
		
		 
		poly->next = (struct Node *)malloc(sizeof(struct Node)); 
		poly = poly->next; 
		poly->next = NULL; 
	} 
while(poly1->next || poly2->next) 
	{ 
		if(poly1->next) 
		{ 
			poly->pow = poly1->pow; 
			poly->coeff = poly1->coeff; 
			poly1 = poly1->next; 
		} 
		if(poly2->next) 
		{ 
			poly->pow = poly2->pow; 
			poly->coeff = poly2->coeff; 
			poly2 = poly2->next; 
		} 
		poly->next = (struct Node *)malloc(sizeof(struct Node)); 
		poly = poly->next; 
		poly->next = NULL; 
	} 
} 


void show(struct Node *node) // viewing the linked lists
{ 
while(node->next != NULL) 
	{ 
	printf("%dx^%d", node->coeff, node->pow); 
	node = node->next; 
	if(node->next != NULL) 
		printf(" + "); 
	} 
} 


int main() //main function to add two different polynomials
{ 
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
	int p;
	
	create_node(5,2,&poly1); 
	create_node(4,1,&poly1); 
	create_node(2,0,&poly1); 
	
	
	create_node(5,1,&poly2); 
	create_node(5,0,&poly2); 
	
	printf("1st Number: "); 
	show(poly1); 
	
	printf("\n2nd Number: "); 
	show(poly2); 
	
	poly = (struct Node *)malloc(sizeof(struct Node)); 
	p = poly;
	
	polyadd(poly1, poly2, poly); 
	
	
	printf("\nAdded polynomial: \n"); 
	show(poly); 

return 0; 
} 

