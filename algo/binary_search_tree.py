# -*- encoding: utf-8 -*-
'''
@create_time: 2020/07/01 10:10:13
@author: lichunyu
'''


class BinarySearchTree(object):

    def __init__(self, tree=[]):
        self.tree = tree

    @property
    def length(self):
        return len(self.tree)

    def build_binary_tree(self, lst):
        for i in lst:
            self.insert(i)

    def have_left_subtree(self, x):
        if 2*x+1 < self.length and self.tree[2*x+1] is not None:
            return True
        else:
            return False

    def have_right_subtree(self, x):
        if 2*x+2 < self.length and self.tree[2*x+2] is not None:
            return True
        else:
            return False

    def maximum(self, x=0, index=False):
        if self.have_right_subtree(x):
            return self.maximum(2*x+2, index=index)
        else:
            if index is True:
                return x, self.tree[x]
            return self.tree[x]

    def minimum(self, x=0, index=False):
        if self.have_left_subtree(x):
            return self.minimum(2*x+1, index=index)
        else:
            if index is True:
                return x, self.tree[x]
            return self.tree[x]

    def inorder_tree_walk(self, x=0):
        if x < self.length and self.tree[x] is not None:
            self.inorder_tree_walk(2*x+1)
            print(self.tree[x])
            self.inorder_tree_walk(2*x+2)

    def insert(self, v, x=0):
        if x < self.length and self.tree[x] is not None:
            if v < self.tree[x]:
                self.insert(v, 2*x+1)
            elif v >= self.tree[x]:
                self.insert(v, 2*x+2)
        elif x < self.length and self.tree[x] is None:
            self.tree[x] = v
        elif x >= self.length:
            space = x - self.length
            self.tree += space*[None] + [v]
        else:
            raise Exception('insert error')

    def tansplant(self, x1, x2):
        """x1 to x2"""
        subtree = self.get_subtree(x1)
        index_subtree_x2 = self._get_index_subtree(x2)
        for i in index_subtree_x2:
            self.tree[i] = None
        for n, i in enumerate(subtree):
            self.tree[index_subtree_x2[n]] = i
        self.pruning()

    def pruning(self):
        length = self.length
        index_last = 0
        for n in range(length-1, -1, -1):
            if self.tree[n] is not None:
                index_last = n
                break
        self.tree = self.tree[:index_last+1]

    def get_subtree(self, x):
        index_subtree = self._get_index_subtree(x)
        subtree = []
        for i in index_subtree:
            subtree.append(self.tree[i])
        return subtree

    def _get_index_subtree(self, x):
        index_subtree = [x]
        for i in index_subtree:
            if 2*i+1 < self.length:
                index_subtree.append(2*i+1)
            else:
                break
            if 2*i+2 < self.length:
                index_subtree.append(2*i+2)
            else:
                break
        return index_subtree

    def delete(self, x):
        if not self.have_left_subtree(x) and not self.have_right_subtree(x):
            self.tree[x] = None
        elif self.have_left_subtree(x) and not self.have_right_subtree(x):
            self.tansplant(2*x+1, x)
        elif self.have_right_subtree(x) and not self.have_left_subtree(x):
            self.tansplant(2*x+2, x)
        elif self.have_left_subtree(x) and self.have_right_subtree(x):
            if not self.have_left_subtree(2*x+2):
                self.tree[x] = self.tree[2*x+2]
                self.tansplant(2*(2*x+2)+2, 2*x+2)
            else:
                x_min, v_min = self.minimum(x=2*x+2, index=True)
                if self.have_right_subtree(x_min):
                    self.tansplant(2*x_min+2, x_min)
                    self.tree[x] = v_min
                else:
                    self.tree[x_min] = None
                    self.tree[x] = v_min
                    self.pruning()


if __name__ == '__main__':
    # tree = [6, 5, 7, 2, 6, None, 8, 1, 3]
    tree = [15, 6, 18, 3, 7, 17, 20, 2, 4, None, 13, None, None, None, None, None, None, None, None, None, None, 9]
    # tree = [6, 5, 7, 2, 5, None, 8]
    bt = BinarySearchTree(tree)
    # import random
    # lst = list(range(20))
    # random.shuffle(lst)
    # bt.build_binary_tree(lst)
    bt.delete(0)
    bt.inorder_tree_walk()
