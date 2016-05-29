#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define PII pair<int, int>
#define MP make_pair
#define RI(X) scanf("%d", &(X))
#define RII(X,Y) scanf("%d %d", &(X), &(Y))
using namespace std;
struct Node{
    int val;
    Node *left, *right;
};

int n;
int par[111111];
Node *root;
Node *getNode(int val){
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->val = val;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}
int ins(int data){
    if(root == NULL){
        root = getNode(data);
        return -1;
    }
    Node *cur = root, *prv, *ii = getNode(data);

    while(cur){
        prv = cur;
        if(data > cur->val) cur = cur->right;
        else cur = cur->left;
    }
    if(data > prv->val) prv->right = ii;
    else prv->left = ii;
    return prv->val;
}

int main(){
    RI(n);
    int tmp;

    for(int i = 0;i < n;++ i){
        RI(tmp);
        par[i] = ins(tmp);
    }
    for(int i = 1;i < n;++ i){
        printf("%d ", par[i]);
    }
    printf("\n");
    return 0;
}
