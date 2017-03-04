#pragma once
#include "../utils.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(const vector<int> &arr, const int &root) {
    if (root >= arr.size()) return nullptr;
    TreeNode *node = new TreeNode(arr[root]);
    node->left = createTree(arr, (root << 1) + 1);
    node->right = createTree(arr, (root << 1) + 2);
    return node;
}

void middleOrderRecursive(const TreeNode* root) {
    if (root == nullptr) return;
    middleOrderRecursive(root->left);
    cout << root->val << " ";
    middleOrderRecursive(root->right);
}

void middleOrderNonRecursive(const TreeNode* root) {
    stack<const TreeNode*> st;
    set<const TreeNode*> visit;
    st.push(root);
    visit.insert(root);
    while (!st.empty()) {
        while (st.top()->left != nullptr && visit.find(st.top()->left) == visit.end()) {
            st.push(st.top()->left);
            visit.insert(st.top());
        }
        if (st.top()->left == nullptr || visit.find(st.top()->left) != visit.end()) {
            cout << st.top()->val << " ";
        }
        const TreeNode* right = st.top()->right;
        st.pop();
        if (right != nullptr) {
            st.push(right);
            visit.insert(right);
        }
    }
}

void beforeOrderRecursive(const TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    beforeOrderRecursive(root->left);
    beforeOrderRecursive(root->right);
}

void beforeOrderNonRecursive(const TreeNode* root) {
    stack<const TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        const TreeNode* middle = st.top();
        cout << middle->val << " ";
        st.pop();
        if (middle->right != nullptr) st.push(middle->right);
        if (middle->left != nullptr) st.push(middle->left);
    }
}

void afterOrderRecursive(const TreeNode* root) {
    if (root == nullptr) return;
    afterOrderRecursive(root->left);
    afterOrderRecursive(root->right);
    cout << root->val << " ";
}

void afterOrderNonRecursive(const TreeNode* root) {
    stack<const TreeNode*> st;
    set<const TreeNode*> visit;
    st.push(root);
    visit.insert(root);
    while (!st.empty()) {
        while (st.top()->left != nullptr && visit.find(st.top()->left) == visit.end()) {
            st.push(st.top()->left);
            visit.insert(st.top());
        }
        if (st.top()->right != nullptr && visit.find(st.top()->right) == visit.end()) {
            st.push(st.top()->right);
            visit.insert(st.top());
        }
        else {
            cout << st.top()->val << " ";
            st.pop();
        }
    }
}