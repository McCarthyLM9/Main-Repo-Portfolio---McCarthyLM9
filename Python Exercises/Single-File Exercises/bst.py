"""Binary Search Tree Implementation"""
from collections import deque
from pathlib import Path
from graphviz import Digraph


class Node:
    """Creates Node Object
    """
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BinarySearchTree:
    """Creates Binary Tree Object w/ Methods
    """
    def __init__(self):
        self.root = None

    # Insert
    def insert(self, val):
        """Method for inserting values into bst"""
        def insert_rec(node, val):
            if not node:
                return Node(val)
            if val < node.val:
                node.left = insert_rec(node.left, val)
            elif val > node.val:
                node.right = insert_rec(node.right, val)
            return node
        self.root = insert_rec(self.root, val)

    # Search
    def search(self, val):
        """Method for searching for value in bst"""
        def search_rec(node, val):
            if not node:
                return False
            if node.val == val:
                return True
            elif val < node.val:
                return search_rec(node.left, val)
            else:
                return search_rec(node.right, val)
        return search_rec(self.root, val)

    # Delete
    def delete(self, val):
        """Method for deletion from bst"""
        def delete_rec(node, val):
            if not node:
                return None
            if val < node.val:
                node.left = delete_rec(node.left, val)
            elif val > node.val:
                node.right = delete_rec(node.right, val)
            else:
                # Node with only one child or no child
                if not node.left:
                    return node.right
                elif not node.right:
                    return node.left
                # Node with two children
                temp = self.get_min_node(node.right)
                node.val = temp.val
                node.right = delete_rec(node.right, temp.val)
            return node
        self.root = delete_rec(self.root, val)

    # Get min node (helper for deletion)
    def get_min_node(self, node):
        """Method for minimum value gathering from bst"""
        while node and node.left:
            node = node.left
        return node

    # Find Min
    def find_min(self):
        """Method for min val finding"""
        if not self.root:
            return None
        return self.get_min_node(self.root).val

    # Find Max
    def find_max(self):
        """Method for max val finding"""
        curr = self.root
        if not curr:
            return None
        while curr.right:
            curr = curr.right
        return curr.val

    # Get Height
    def get_height(self):
        """Method to get bst height"""
        def height(node):
            if not node:
                return -1
            return 1 + max(height(node.left), height(node.right))
        return height(self.root)

    # Count all nodes
    def count_nodes(self):
        """Method to count nodes in bst"""
        def count(node):
            if not node:
                return 0
            return 1 + count(node.left) + count(node.right)
        return count(self.root)

    # Count leaf nodes
    def count_leaves(self):
        """Method to count leaves in bst"""
        def count(node):
            if not node:
                return 0
            if not node.left and not node.right:
                return 1
            return count(node.left) + count(node.right)
        return count(self.root)

    # Check if tree is balanced
    def is_balanced(self):
        """Method to check if bst is balanced"""
        def check(node):
            if not node:
                return 0, True
            lh, lb = check(node.left)
            rh, rb = check(node.right)
            return 1 + max(lh, rh), lb and rb and abs(lh - rh) <= 1
        _, balanced = check(self.root)
        return balanced

    # Inorder Traversal
    def inorder_traversal(self):
        """Inorder Traversal Method"""
        def inorder(node):
            if not node:
                return []
            return inorder(node.left) + [node.val] + inorder(node.right)
        return inorder(self.root)

    # Preorder Traversal
    def preorder_traversal(self):
        """Preorder Traversal Method"""
        def preorder(node):
            if not node:
                return []
            return [node.val] + preorder(node.left) + preorder(node.right)
        return preorder(self.root)

    # Postorder Traversal
    def postorder_traversal(self):
        """Postorder Traversal Method"""
        def postorder(node):
            if not node:
                return []
            return postorder(node.left) + postorder(node.right) + [node.val]
        return postorder(self.root)

    # Level-order (Breadth-First)
    def level_order_traversal(self):
        """Level Order Traversal Method"""
        if not self.root:
            return []
        result = []
        queue = deque([self.root])
        while queue:
            queue_len = len(queue)
            level = []
            for _ in range(queue_len):
                node = queue.popleft()
                if node:
                    level.append(node.val)
                    queue.append(node.left)
                    queue.append(node.right)
            if level:
                result.append(level)
        return result

    # Balanced Insert Order
    def balanced_insert_order(self, sorted_values):
        """Insert values in a auto-balanced manner"""
        if not sorted_values:
            return []
        mid = len(sorted_values) // 2
        return (
            [sorted_values[mid]]
            + self.balanced_insert_order(sorted_values[:mid])
            + self.balanced_insert_order(sorted_values[mid + 1:])
        )

    # Render Graphviz
    def render_graphviz(self, filename="bst_graphviz", view=False):
        """Render the BST using Graphviz"""
        if not self.root:
            print("[Empty Tree]")
            return

        def add_edges(dot, node):
            if node.left:
                dot.node(str(node.left.val))
                dot.edge(str(node.val), str(node.left.val))
                add_edges(dot, node.left)
            if node.right:
                dot.node(str(node.right.val))
                dot.edge(str(node.val), str(node.right.val))
                add_edges(dot, node.right)

        dot = Digraph(comment="Binary Search Tree", format="png")
        dot.attr(dpi="500")
        dot.node(str(self.root.val))
        add_edges(dot, self.root)
        dot.render(filename, view=view)  # Saves and optionally opens image
        print(f"Graph rendered to {filename}.png")


# Main functionality for user interaction and bst implementation
# Utilizes Graphviz visualization before/after operations
def main():
    """Interactive main program for user-driven BST operations"""
    while True:
        try:
            user_dir = input(
                "Enter output directory for Graphviz images "
                "(leave blank for current directory): "
            ).strip()
            output_dir = (
                Path(user_dir).expanduser().resolve()
                if user_dir else Path.cwd()
            )
            output_dir.mkdir(parents=True, exist_ok=True)
            break
        except (OSError, ValueError) as e:
            print(f"Error creating directory: {e}. Please try again.")

    bst = BinarySearchTree()
    print("== Binary Search Tree Program ==")

    # Insert values
    while True:
        user_input = input(
            "Enter integers to insert (comma-separated) or 'done' to finish: "
        ).strip()
        if user_input.lower() == 'done':
            break
        if not user_input:
            print("Input cannot be empty. Please enter integers or 'done'.")
            continue
        try:
            values = [int(val.strip()) for val in user_input.split(',')]
            if not values:
                print("No valid integers found. Try again.")
                continue
            values.sort()
            balanced_values = bst.balanced_insert_order(values)
            for val in balanced_values:
                bst.insert(val)
        except ValueError:
            print("Invalid input. Please enter integers only.")

    print("\nTree structure after insertion:")
    bst.render_graphviz(
        filename=output_dir / "bst_graphviz_before"
    )

    print("\nTraversals:")
    print("Inorder:", bst.inorder_traversal())
    print("Preorder:", bst.preorder_traversal())
    print("Postorder:", bst.postorder_traversal())
    print("Level-order:", bst.level_order_traversal())
    print("Minimum:", bst.find_min())
    print("Maximum:", bst.find_max())
    print("Height:", bst.get_height())
    print("Total nodes:", bst.count_nodes())
    print("Leaf nodes:", bst.count_leaves())
    print("Balanced:", bst.is_balanced())

    # Delete values
    while True:
        del_input = input(
            "\nEnter a value to delete or type 'done' to finish: "
        ).strip()
        if del_input.lower() == 'done':
            break
        if not del_input:
            print("Input cannot be empty. Please enter a value or 'done'.")
            continue
        try:
            val = int(del_input)
        except ValueError:
            print("Invalid input. Please enter an integer.")
            continue
        while True:
            mode = input(
                "Delete (f)irst occurrence or (a)ll? [f/a]: "
            ).strip().lower()
            if mode in ('f', 'a'):
                break
            else:
                print("Invalid option. Please enter 'f' or 'a'.")
        if mode == 'f':
            if bst.search(val):
                bst.delete(val)
                print(f"Deleted first occurrence of {val}.")
            else:
                print(f"{val} not found in the tree.")
        else:
            count = 0
            while bst.search(val):
                bst.delete(val)
                count += 1
            if count:
                print(f"Deleted all {count} occurrence(s) of {val}.")
            else:
                print(f"{val} not found in the tree.")

    print("\nTree structure after deletion:")
    bst.render_graphviz(
        filename=output_dir / "bst_graphviz_after"
    )

    # Final state
    print("\nFinal Inorder:", bst.inorder_traversal())
    print("Balanced:", bst.is_balanced())

    if bst.count_nodes() == 0:
        print("The tree is now empty.")
    print("Thank you for using the BST program!")


if __name__ == "__main__":
    main()
