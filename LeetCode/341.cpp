/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<NestedInteger>* nested_list;
    stack< vector<NestedInteger>::iterator > *s;
    vector<NestedInteger>::iterator cur, cur_in;
    NestedIterator(vector<NestedInteger> &nestedList) {
        nested_list = nestedList;
        s = new stack< vector<NestedInteger>::iterator >;
        cur = nested_list->begin();
        cur_in = NULL;
        in_list = NULL;
    }

    int next() {

    }

    bool hasNext() {

    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nest edList);
 * while (i.hasNext()) cout << i.next();
 */