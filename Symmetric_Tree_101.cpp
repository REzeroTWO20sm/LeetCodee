#include <vector>
#include <iostream>

// g++ Symmetric_Tree_101.cpp -o Symmetric_Tree_101 --std=c++14 -I/usr/local/include

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

void TreeUnique_left(TreeNode* root, std::vector<int>& vect) {
    if (root == nullptr) {
        vect.push_back(0);
        return;
    }
    
    TreeUnique_left(root->left, vect);
    vect.push_back(root->val);
    TreeUnique_left(root->right, vect);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    std::vector<int> p_vec; TreeUnique_left(p,p_vec);
    std::vector<int> q_vec; TreeUnique_left(q,q_vec);
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

bool isSymmetric(TreeNode* root) {
    int head = root->val;
    std::vector<int> vec; TreeUnique_left(root,vec);
    if(vec.size()%2==0 && vec.size()!=1 && vec.size()!=0){
        return false;
    }
    int back_i = vec.size()-1;
    for(int i=0;i<vec.size();i++){
        if(vec[i]==vec[back_i]){
            std::cout << "["<<vec[i] << ","<<vec[back_i]<<"]";
            back_i-=1;
            continue;
        }
        else if(vec[i]!=vec[back_i]){
            std::cout << "["<<vec[i] << ","<<vec[back_i]<<"]";
            return false;
        }
    }
    return true;
}

bool isSymmetric_best(TreeNode* root_1, TreeNode* root_2) {
    if (root_1 == nullptr && root_2 == nullptr) {
        return true;
    }
    if (root_1 == nullptr || root_2 == nullptr) {
        return false;
    }
    if (root_1->val != root_2->val) {
        return false;
    }
    return isSymmetric_best(root_1->left, root_2->right) && isSymmetric_best(root_1->right, root_2->left);
}

int main(){

    // // Создание узлов 1
    // TreeNode* root_1 = new TreeNode(1);
    // TreeNode* leftChild_1 = new TreeNode(2);
    // TreeNode* rightChild_1 = new TreeNode(2);

    // // Построение дерева
    // root_1->left = leftChild_1;
    // root_1->right = rightChild_1;

    // // Добавление дополнительных узлов
    // leftChild_1->left = new TreeNode(3);
    // leftChild_1->right = new TreeNode(4);

    // rightChild_1->left = new TreeNode(4);
    // rightChild_1->right = new TreeNode(3);

    //============================================

    // Создание узлов 1
    TreeNode* root_1 = new TreeNode(1);
    TreeNode* leftChild_1 = new TreeNode(2);
    TreeNode* rightChild_1 = new TreeNode(2);

    // Построение дерева
    root_1->left = leftChild_1;
    root_1->right = rightChild_1;

    // Добавление дополнительных узлов
    leftChild_1->left = new TreeNode(2);
    //leftChild_1->right = new TreeNode(4);

    rightChild_1->left = new TreeNode(2);
    //rightChild_1->right = new TreeNode(3);
    
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
    TreeUnique_left(root_1,vec_1);

    std::vector<int> vec_2{};
    TreeUnique_left(root_2,vec_2);

    for(auto it : vec_1){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    for(auto it : vec_2){
        std::cout << it << " ";
    }
    std::cout << std::endl;

    std::cout << "{ "<<isSameTree(root_1,root_2)<<" } "<<std::endl;
    std::cout << isSymmetric(root_1)<<" "<<isSymmetric(root_2);

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout<< isSymmetric_best(root_1,root_1);
}