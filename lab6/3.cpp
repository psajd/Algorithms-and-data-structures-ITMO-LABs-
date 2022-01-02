#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

Node *Insert(Node *Tree, int Key) {
    if (Tree == nullptr) {
        Tree = new Node;
        Tree->value = Key;
        Tree->left = Tree->right = nullptr;
    }
    else if (Tree->value > Key)
        Tree->left = Insert(Tree->left, Key);
    else if (Tree->value < Key)
        Tree->right = Insert(Tree->right, Key);

    return Tree;
}

Node *Min(Node *Tree) {
    if (Tree->left == nullptr)
        return Tree;

    return Min(Tree->left);
}


Node *Delete(Node *Tree, int Key) {
    if (Tree == nullptr)
        return Tree;

    if (Key < Tree->value)
        Tree->left = Delete(Tree->left, Key);
    else if (Key > Tree->value)
        Tree->right = Delete(Tree->right, Key);
    else if (Tree->left != nullptr && Tree->right != nullptr) {
        Tree->value = Min(Tree->right)->value;
        Tree->right = Delete(Tree->right, Tree->value);
    }
    else {
        if (Tree->left != nullptr)
            Tree = Tree->left;
        else if (Tree->right != nullptr)
            Tree = Tree->right;
        else
            Tree = nullptr;
    }

    return Tree;
}

bool Exist(Node *Tree, int Key) {
    if (Tree == nullptr)
        return false;
    if (Tree->value == Key)
        return true;
    if (Key < Tree->value)
        return Exist(Tree->left, Key);
    else
        return Exist(Tree->right, Key);
}

Node *Next(Node *Tree, int Key) {
    Node *T = Tree;
    Node *P = nullptr;

    while (T != nullptr) {
        if (T->value > Key) {
            P = T;
            T = T->left;
        } else
            T = T->right;
    }
    return P;
}

Node *Prev(Node *Tree, int Key) {
    Node *T = Tree;
    Node *P = nullptr;

    while (T != nullptr) {
        if (T->value < Key) {
            P = T;
            T = T->right;
        } else T = T->left;
    }
    return P;
}

int main() {

    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");

    string s;

    int x;

    Node *Tree = nullptr;

    while (fin >> s) {
        fin >> x;

        if (s == "insert") {
            if (Tree == nullptr)
                Tree = Insert(Tree, x);
            else
                Insert(Tree, x);
        }
        else if (s == "delete") {
            Tree = Delete(Tree, x);
        }
        else if (s == "exists") {
            if (Exist(Tree, x))
                fout << "true\n";
            else
                fout << "false\n";
        }
        else if (s == "next") {
            Node *res = Next(Tree, x);

            if (res == nullptr)
                fout << "none\n";
            else
                fout << res->value << "\n";
        }
        else if (s == "prev") {
            Node *res = Prev(Tree, x);

            if (res == nullptr)
                fout << "none\n";
            else
                fout << res->value << "\n";
        }
    }

    return 0;
}