/*
      Binary Trees

      Introduction:
      We extend the concept of linked data structures to structure containing nodes with more than one self-referenced field.
      A binary tree is made of nodes where each node contains a left reference, a right reference and a data element. The topmost
      node in a tree is called the root. Every node (including root) in a tree is connected by a directed edge from exactly one
      other node. This node is called parent. On the other hand each node can be connected to arbitrary number of nodes, called children.
      Nodes with no children are called leaves, or external nodes. Nodes which are not leaves are called internal nodes. Nodes with
      the same parent are called siblings.

      More tree terminology:
           - The dept of a node is the number of edges from the root to node.
           - The height of a node is the number of edges from the node to the deepest leaf.
           - The height of a tree is the height of the root
           - a full binary tree is a tree in which each node has exactly two children or zero.
           - a complet binary tree  is a binary tree which is completed filled with the possible exceptionof the bottom level, 
             which is filled from left to right.

       Advantages of trees:

           - Trees reflects structural relationships in the data.
           - Trees are used to represent hierarchies
           - Trees provide an efficient insertions and searching
           - Trees are very flexible data, allowing to move subtrees around with minimum effort.

       Traversal:
             A traversal is a process that visits all the nodes in the tree.           

      Reference: https://www.cs.cmu.edu/~adamchik/15-121/lectures/Trees/trees.html      
 */   
#include <stdio.h>
#include <malloc.h>
#include <ctype.h>


struct TNode {

	   int data;
	   struct TNode *left; 
	   struct TNode *right;
};

typedef struct TNode Node;

Node *root;


Node *create() {
	  
      Node *node;
      int x;
      
      printf("%s\n", "Enter node (-1 for no data)");	       
      scanf("%d", &x);

      if(x == -1) return NULL;

      node = (Node*)malloc(sizeof(Node));
      node->data = x;

      printf("Enter Left child for -> %x\n", x);
      node->left = create();

      printf("Enter Right child for -> %x\n", x);
      node->right = create();

      return node;
}

void inorder(Node *p) {

     if( p != NULL ) {

         inorder(p->left);  
         printf("%d ", p->data);
         inorder(p->right);
     }
}

void postorder(Node *p) {

     if( p != NULL ) {

         postorder(p->left);           
         postorder(p->right);
         printf("%d ", p->data);
     }
}

void preorder(Node *p) {

     if( p != NULL ) {

         printf("%d ", p->data);
         preorder(p->left);           
         preorder(p->right);    
     }
}

int num(Node *p) {

    if(p == NULL) return 0;

    else return 1 + num(p->left) + num(p->right);

}

int is(Node *p, int key) {

	if(p == NULL) return 0;

	else if( p->data == key) {
 
         return 1;  

	} else return ( is(p->left, key) ) || ( is(p->right, key) ) ; 
}

int main(int argc, char const *argv[])
{

    root = create();

    printf("Inorder: \n");
    inorder(root);
    printf("\n");
    printf("Preorder: \n");
    preorder(root);
    printf("\n");
    printf("Postorder: \n");
    postorder(root);
    printf("\n");
    printf("Number -> %d\n", num(root));

    if(is(root, 5)) printf("%d is in Binary Tree", 5);
            else 
            	    printf("%d Isn't in Binary Tree", 5);
	return 0;
}
