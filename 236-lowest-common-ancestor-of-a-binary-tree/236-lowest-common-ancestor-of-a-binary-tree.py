class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
        Idea: 1) Find the path from root to that p or q and record the path
              2) Find the last same element in the two path list
        """
        result = []
        
        """Helper dfs function"""
        def dfs(node,path, target):
            if not node:
                return
            path.append(node.val)
            if node.val == target:
                result.append(path.copy())
                return
            dfs(node.left, path, target)
            dfs(node.right, path, target)
            
            path.pop(-1) # Add this to DFS to find the path
        
        dfs(root, [], p.val)
        dfs(root, [], q.val)
        
        q_path, p_path = result[0], result[1]
        q_ptr, p_ptr = 0, 0
        print(q_path, p_path)
        while q_ptr < len(q_path) and p_ptr < len(p_path):
            if q_path[q_ptr] != p_path[p_ptr]:
                return TreeNode(q_path[q_ptr -1])
            q_ptr += 1
            p_ptr += 1
        if len(q_path) > len(p_path):
            return TreeNode(p_path[p_ptr - 1])
        else:
            return TreeNode(q_path[q_ptr - 1])