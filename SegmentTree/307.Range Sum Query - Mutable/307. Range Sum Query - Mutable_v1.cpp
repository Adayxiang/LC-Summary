class NumArray {
private:
    struct SegmentTreeNode
    {
        int start, end, sum;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int i, int j):start(i), end(j), sum(0), left(nullptr), right(nullptr){}
    };
    
    SegmentTreeNode* buildTree(int i, int j, vector<int>& nums)
    {
        if(i > j) return nullptr;
        SegmentTreeNode *node = new SegmentTreeNode(i, j);
        if(i == j)
        {
            node->sum = nums[i];
            return node;
        }
        
        int mid = i + (j - i) / 2;
        node->left = buildTree(i, mid, nums);
        node->right = buildTree(mid + 1, j, nums);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
    
    void updateTree(int i, int val, SegmentTreeNode *node)
    {
        if(!node) return;
        if(node->start == i && node->end == i)
        {
            node->sum = val;
            return;
        }
        int mid = (node->start + node->end) / 2;
        if(mid >= i) updateTree(i, val, node->left);
        else updateTree(i, val, node->right);
        node->sum = 0;
        if(node->left) node->sum += node->left->sum;
        if(node->right) node->sum += node->right->sum;
        return;
    }
    
    int sumTree(int i, int j, SegmentTreeNode *node)
    {
        if(!node || node->start > j || node->end < i) return 0;
        if(node->start == i && node->end == j) return node->sum;
        int mid = (node->start + node->end) / 2;
        if(i > mid) return sumTree(i, j, node->right);
        if(j <= mid) return sumTree(i, j, node->left);
        return sumTree(i, mid, node->left) + sumTree(mid + 1, j, node->right);
    }
    
    SegmentTreeNode *root;
public:
    NumArray(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        root = buildTree(i, j, nums);
    }
    
    void update(int i, int val) {
        updateTree(i, val, root);
    }
    
    int sumRange(int i, int j) {
        return sumTree(i, j, root);
    }
};