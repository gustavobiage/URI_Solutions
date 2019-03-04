#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Operações em ABP I
//Problem id: 1200
//Grafos
//Complexity: O(M*N) where M is the amount of actions you have and N is the size of your binary search tree
//Note that it is not log(N) because the INFIXA search, PREFIX search and the POSFIXA search you run through every element of the tree

char action[15];
char infixa[15] = "INFIXA";
char prefixa[15] = "PREFIXA";
char posfixa[15] = "POSFIXA";
int first;

char prop;
int len;

int structure_size = 0;
struct node{
	char value;
	struct node* left;
	struct node* right;
};

struct node* head;
struct node* it;

//I sugest you research those functions yourself, they are pretty trivial and I myself had trouble implementing then
//Functions:
//	Add element to bynary search tree
//	search element in bynary search tree
//	INFIXA search
//	PREFIXA search
//	POSFIXA search

void add(struct node* node, char prop) {
	
	if(node == NULL) {
		// node = (struct node*) malloc(sizeof(struct node));
		// node->value = prop;
	} else {
		// if(node != NULL) printf("%c --> ", node->value);
		if(node->value == prop) return;

		if((int)node->value < (int)prop) {
			if(node->right != NULL) {
				add(node->right, prop);
			} else {
				node->right = (struct node*) malloc(sizeof(struct node));
				node->right->value = prop;
			}
		} else {
			if(node->left != NULL) {
				 add(node->left, prop);
			} else {
				node->left = (struct node*) malloc(sizeof(struct node));
				node->left->value = prop;
			}
		}
	}
}


int search(struct node* node, char prop) {
	if(node == NULL) {
		return 0;
	} else {
		if(node->value == prop) return 1;

		if((int)prop > (int)node->value) {
			if(node->right == NULL) return 0;
			return search(node->right, prop);
		} else {
			if(node->left == NULL) return 0;
			return search(node->left, prop);
		}
	}

	return 0;

}

void print_infixa(struct node* node) {
	if(node == NULL) return;


	if(node->left != NULL) {
		print_infixa(node->left);
	}

	if(first) {
		printf("%c", node->value);
		first = 0;
	} else {
		printf(" %c", node->value);
	}

	if(node->right != NULL) {
		print_infixa(node->right);
	}

}

void print_prefixa(struct node* node) {
	if(node == NULL) return;
	if(first) {
		printf("%c", node->value);
		first = 0;
	} else {
		printf(" %c", node->value);
	}
	if(node->left != NULL) print_prefixa(node->left);
	if(node->right != NULL) print_prefixa(node->right);
}

void print_posfixa(struct node* node) {
	if(node == NULL)return;
	if(node->left != NULL) print_posfixa(node->left);
	if(node->right != NULL) print_posfixa(node->right);
	if(first) {
		printf("%c", node->value);
		first = 0;
	} else {
		printf(" %c", node->value);
	}
}

int main() {
	head = NULL;
	while(scanf(" %s ", action) != EOF) {

		//This part is the easyest one, you read the actions and execute the function.
		len = strlen(action);

		if(len == 1) {
			scanf("%c ", &prop);
			
			switch(action[0]) {
				case 'I':
					if(head == NULL) {
						head = (struct node*) malloc(sizeof(struct node));
						head->value = prop;
					} else {
						add(head, prop);
					}

					break;

				case 'P':
					printf("%c", prop);
					if(!search(head, prop)) {
						printf(" nao");
					}
					
					printf(" existe\n");
					break;

			} 

		} else {

				if(strcmp(action, infixa) == 0) {
					first = 1;
					print_infixa(head);
					printf("\n");
				} else if(strcmp(action, prefixa) == 0) {
					first = 1;
					print_prefixa(head);
					printf("\n");
				} else if(strcmp(action, posfixa) == 0) {
					first = 1;
					print_posfixa(head);
					printf("\n");
				}
			}
		}
	

	return 0;
}