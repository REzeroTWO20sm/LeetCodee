#include <vector>
#include <iostream>

// g++ Same_Tree_100.cpp -o Same_Tree_100 --std=c++14 -I/usr/local/include

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(TreeNode* root){
    if (root == nullptr) {
        return;
    }
    std::cout << root->val ;
    printTree(root->left);
    printTree(root->right);
}

void TreeUnique(TreeNode* root, std::vector<int>& vect) {
    if (root == nullptr) {
        vect.push_back(-1);
        return;
    }
    vect.push_back(root->val);
    TreeUnique(root->left, vect);
    TreeUnique(root->right, vect);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    std::vector<int> p_vec; TreeUnique(p,p_vec);
    std::vector<int> q_vec; TreeUnique(q,q_vec);
    if(p_vec.size() != p_vec.size()){
        return false;
    }
    else if(p_vec.size()==0){
        return false;
    }
    else if(q_vec.size()==0){
        return false;
    }
    else{
        for(int i=0;i<p_vec.size();i++){
            if(p_vec[i]!=q_vec[i]){
                return false;
            }
        }
        return true;
    }
}

int main(){
    // Создание узлов 1
    TreeNode* root_1 = new TreeNode(1);
    TreeNode* leftChild_1 = new TreeNode(2);
    //TreeNode* rightChild_1 = new TreeNode(3);

    // Построение дерева
    root_1->left = leftChild_1;
    //root_1->right = rightChild_1;

    // Добавление дополнительных узлов
    //leftChild_1->left = new TreeNode(4);
    //leftChild_1->right = new TreeNode(5);

    //rightChild_1->left = new TreeNode(6);
    //rightChild_1->right = new TreeNode(7);
    
    //=============================================

    // Создание узлов 2
    TreeNode* root_2 = new TreeNode(1);
    TreeNode* leftChild_2 = new TreeNode(2);
    TreeNode* rightChild_2 = new TreeNode(3);

    // Построение дерева
    root_2->left = leftChild_2;
    root_2->right = rightChild_2;

    // Добавление дополнительных узлов
    leftChild_2->left = new TreeNode(4);
    leftChild_2->right = new TreeNode(5);

    rightChild_2->left = new TreeNode(6);
    rightChild_2->right = new TreeNode(7);

    printTree(root_1);
    std::cout<<std::endl;

    printTree(root_2);
    std::cout<<std::endl;

    std::vector<int> vec_1{};
    TreeUnique(root_1,vec_1);

    std::vector<int> vec_2{};
    TreeUnique(root_2,vec_2);

    for(auto it : vec_1){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    for(auto it : vec_2){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << "{ "<<isSameTree(root_1,root_2)<<" } ";
}