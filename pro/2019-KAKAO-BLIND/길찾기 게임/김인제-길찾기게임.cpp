/*
이진 트리와 노드 클래스를 직접 구현하여 해결
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int idx2node[100001];
vector<int> _preorder;
vector<int> _postorder;

class Node{
public:
    int value = -1;

    Node* left = NULL;
    Node* right = NULL;
    
    Node(int v)
        :value(v) {}
};

class Tree{
public:
    Node* root = NULL;
    
    void push(int value){
        
        if(root == NULL){
            Node* node = new Node(value);
            root = node;
        }
        else{
            Node* p = NULL;
            Node* t = root;
            
            while(t != NULL){
                p = t;
                
                if (t->value < value)
                    t = t->right;
                else
                    t = t ->left;
            }
            Node* node = new Node(value);
            
            if (p->value < value)
                    p->right = node;
                else
                    p ->left = node;
        }
            
    }
    
    void preorder(Node *node){
        if(node == NULL)
            return;
        
        _preorder.push_back(idx2node[node->value]);
        cout << idx2node[node->value] << endl;
        preorder(node -> left);
        preorder(node -> right);
    }
    
    void postorder(Node *node){
        if(node == NULL)
            return;
        
        postorder(node -> left);
        postorder(node -> right);
        _postorder.push_back(idx2node[node->value]);
        cout << idx2node[node->value] << endl;
    }
};



vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    int idx = 1;
    for (auto& node : nodeinfo){
        int temp = node[0];
        node[0] = -node[1];
        node[1] = temp;
        
        idx2node[node[1]] = idx;
        
        idx++;
    }
    
    sort(nodeinfo.begin(), nodeinfo.end());
    
    Tree tree;
    
    for (auto& node : nodeinfo){
        tree.push(node[1]);

    }
    
    tree.preorder(tree.root);
    tree.postorder(tree.root);
    
    answer.push_back(_preorder);
    answer.push_back(_postorder);
    

    
    
    return answer;
}