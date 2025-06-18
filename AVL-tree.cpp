#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//Peter Nguyen
//2
//description:
//Reads a input file takes each word and sort in a binary tree, nodes pointers for a left 
//and right child,datatypes for a word, integar for there place in the file, and height
//value. The program will output each word in alphatical order in inorder operation and
//each line where the word is printed besides them as a integer. The tree is set as AVL
//to balancing for O(n) time complexity, this rotates the tree double left/right, single left/right
//when the height difference from left and right of a tree is more than 1. Used reference building the
//the binary tree for node structure, sorting for each stored string, setting pointers in each,
//function to recursion function and printing inorder. Split the files into lines then into 
//words from stream functions, looped with for insert function. The AVL tree functions learned
//in class and implented into tree functions to rotate according to height of each nodes in the
//the tree. The programs reads a input txt file breaks apart each lines into words to sort into a tree.
//The inorder function prints inorder and the line number stored in the linked list connected
//next, each word is print on line by line. 

class tree{
private:
    struct node{
        std::string data;
        int line;
        int height = 0;
        node *left = NULL, *right = NULL, *next = NULL;
    };

    node * root = NULL;

    int line_num = 1;

    void rotation_left(node **tree) {
        node *ptr1, *ptr2;

        ptr1 = *tree;
        ptr2 = ptr1->left;
        ptr1->left = ptr2->right;
        ptr2->right = ptr1;

        ptr1->height = (max(node_height(ptr1->left), node_height(ptr1->right)) + 1 );
        ptr2->height = (max(node_height(ptr2->left), ptr1->height) + 1 );

        *tree = ptr2;
    };
    
    void rotation_right(node **tree){
        node *ptr1, *ptr2;

        ptr1 = *tree;
        ptr2 = ptr1->right;
        ptr1->right = ptr2->left;
        ptr2->left = ptr1;

        ptr1->height = (max(node_height(ptr1->left), node_height(ptr1->right)) + 1 );
        ptr2->height = (max(node_height(ptr2->right), ptr1->height) + 1 );

        *tree = ptr2;
    };

    void double_rotation_left(node **tree){
        rotation_right(&(*tree)->left);
        rotation_left(tree);
    };

    void double_rotation_right(node **tree){
        rotation_left(&(*tree)->right);
        rotation_right(tree);
    };

    void insert_file(node **root, std::string data){
        if (*root == NULL){
            *root = new node;
            (*root)->data = data;
            (*root)->line = line_num;
        }
        else if (data < (*root)->data) {
            insert_file(&(*root)->left, data);
            if(node_height((*root)->left) - node_height((*root)->right) == 2){
                if(data < (*root)->left->data){
                    rotation_left(root);
                }else{
                    double_rotation_left(root);
                }
            }else{
                find_height(*root);
            }
        }else if (data > (*root)->data){
            insert_file(  &(*root)->right,data );
            if(node_height((*root)->right) - node_height((*root)->left) == 2){
                if(data > (*root)->right->data){
                    rotation_right(root);
                }else{
                    double_rotation_right(root);
                }
            }else{
                find_height(*root);
            }
        }else{
            node *ptr = new node;
            ptr->line = line_num;
            while((*root)->next != NULL){
                (*root) = (*root)->next;
            }
            (*root)->next = ptr;
        }
    }

    void inorder(node *root){

        if(root != NULL){
            node *ptr = root->next;
            inorder(root->left);
            std::cout << root->data << " " << root->line;
            while(ptr != NULL){
                cout << " " << ptr->line;
                ptr = ptr->next;
            }
            cout << "\n";
            inorder(root->right);
        }
    }

public:

    void insert_file( std::string file_name){
        string text, line;

        ifstream file(file_name);

        while (getline(file,line)){
            stringstream string(line);
            while(string >> text){
                insert_file(&root, text);
            }
            line_num++;
        }
        file.close();
    }

    int node_height(node *tree){
        if(tree != NULL){
            return tree->height;
        }else{
            return -1;
        }
    }

    void find_height(node *tree){
        tree->height = max(node_height(tree->left), node_height(tree->right)) + 1;
    }
    void inorder(){
        inorder(root);
    }
};


int main(){
    tree t1;

    string file;
    cout << "files name: ";
    cin >> file;

    t1.insert_file(file);

    t1.inorder();

    return 0;
}
