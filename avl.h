#include<iostream>
using namespace std;


class Node{

    public:

    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(NULL), right(NULL)
    {}

};

class avl{

    Node *root;

    int height(Node *root)
    {
        if(root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    int balanced(Node *root)
    {
        if(!root)
            return 0;

        return height(root->left) - height(root->right);
    }

    Node* rightrotate(Node *root)
    {
        Node *left = root->left;
        Node *temp = left->right;
        left->right = root;
        root->left = temp;
        return left;
    }

    Node* leftrotate(Node *root)
    {
        Node *right = root->right;
        Node *temp = right->left;
        right->left = root;
        root->right = temp;
        return right;
    }

    Node* insertNode(Node *root, int data)
    {

        if(root == NULL)
        {
            Node *node = new Node(data);
            return node;
        }

        if(data < root->data)
            root->left = insertNode(root->left, data);

        else if(data > root->data)
            root->right = insertNode(root->right, data);

        else
            return root;

        if(balanced(root) > 1 || balanced(root)< -1)
        {
            if(balanced(root) > 1 && balanced(root->left)>=0)
                return rightrotate(root);

            if(balanced(root) > 1 && balanced(root->left)<0)
            {
                root->left = leftrotate(root->left);
                return rightrotate(root);
            }

            if(balanced(root) < -1 && balanced(root->right)<=0)
                return leftrotate(root);

            if(balanced(root) < -1 && balanced(root->right)>0)
            {
                root->right = rightrotate(root->right);
                return leftrotate(root);
            }
        }

        return root;

    }

    Node* deleteNode(Node *root, int data)
    {

        if(root == NULL)
            return root;

        if(data < root->data)
            root->left = deleteNode(root->left, data);

        else if(data > root->data)
            root->right = deleteNode(root->right, data);

        else
        {
            if(!root->left && !root->right)
            {
                delete root;
                return NULL;
            }
            else if(root->left && !root->right)
            {
                Node *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }

            else if(!root->left && root->right)
            {
                Node *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }

            else
            {
                    Node *temp = root->left;
                    while(temp->right)
                    {
                        temp = temp->right;
                    }
                    root->data = temp->data;
                    delete temp;
                    return root;
            }

        }


        if(balanced(root) > 1 || balanced(root)<-1)
        {
            if(balanced(root)> 1 && balanced(root->left) >= 0)
            {
                return rightrotate(root);
            }

            if(balanced(root) >1 && balanced(root->left)<0)
            {
                root->left = leftrotate(root->left);
                return rightrotate(root);
            }

            if(balanced(root)<-1 && balanced(root->right)<= 0)
                return leftrotate(root);

            if(balanced(root)<-1 && balanced(root->right) > 0)
            {
                root->right = rightrotate(root->right);
                return leftrotate(root);
            }
        }

            return root;

    }


    void preorder(Node *root)
    {
        if(root == NULL)
            return;

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root)
    {
        if(root == NULL)
            return;

        preorder(root->left);
        preorder(root->right);
        cout<<root->data<<" ";
    }

    void inorder(Node *root)
    {
        if(root == NULL)
            return;

        preorder(root->left);
        cout<<root->data<<" ";
        preorder(root->right);

    }

    public:

    avl() : root(NULL)
    {}

    void insertNode(int data)
    {
        root = insertNode(root, data);
    }

    void deleteNode(int data)
    {
        root = deleteNode(root, data);
    }

    void preorder()
    {
        preorder(root);
    }

};
