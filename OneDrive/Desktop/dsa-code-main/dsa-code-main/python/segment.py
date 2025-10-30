class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.tree = [0] * (4 * self.n)
        self.build(nums, 0, 0, self.n - 1)

    def build(self, nums, node, l, r):
        if l == r:
            self.tree[node] = nums[l]
            return
        mid = (l + r) // 2
        self.build(nums, 2*node+1, l, mid)
        self.build(nums, 2*node+2, mid+1, r)
        self.tree[node] = self.tree[2*node+1] + self.tree[2*node+2]

    def update(self, idx, val, node=0, l=0, r=None):
        if r is None: r = self.n - 1
        if l == r:
            self.tree[node] = val
            return
        mid = (l + r) // 2
        if idx <= mid:
            self.update(idx, val, 2*node+1, l, mid)
        else:
            self.update(idx, val, 2*node+2, mid+1, r)
        self.tree[node] = self.tree[2*node+1] + self.tree[2*node+2]

    def query(self, L, R, node=0, l=0, r=None):
        if r is None: r = self.n - 1
        if R < l or L > r:  # No overlap
            return 0
        if L <= l and r <= R:  # Complete overlap
            return self.tree[node]
        mid = (l + r) // 2
        return self.query(L, R, 2*node+1, l, mid) + self.query(L, R, 2*node+2, mid+1, r)


# Example usage:
nums = [1, 3, 5, 7, 9, 11]
st = SegmentTree(nums)
print("Sum (1-3):", st.query(1, 3))
st.update(1, 10)
print("After update, Sum (1-3):", st.query(1, 3))
