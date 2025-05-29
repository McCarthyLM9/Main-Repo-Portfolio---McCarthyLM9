"""Doubly Linked List Implementation with Insertion, Deletion, and Display."""


class Node:
    """A node in a doubly linked list."""

    def __init__(self, val):
        """Initialize node with data and pointers."""
        self.data = val
        self.next = None
        self.prev = None


class LinkedList:
    """Doubly linked list with head and tail pointers."""

    def __init__(self):
        """Initialize an empty linked list."""
        self.head = None
        self.tail = None

    def insert_at_head(self, val):
        """Insert a node at the head of the list."""
        new_node = Node(val)
        if not self.head:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def insert_at_tail(self, val):
        """Insert a node at the tail of the list."""
        new_node = Node(val)
        if not self.tail:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

    def is_empty(self):
        """Return True if the list is empty."""
        return self.head is None

    def get_head(self):
        """Return the head node of the list."""
        return self.head

    def print_list(self):
        """Print the elements of the list from head to tail."""
        if self.is_empty():
            print("empty")
            return
        curr = self.head
        while curr:
            print(curr.data, end=' ')
            curr = curr.next
        print()

    def remove_value(self, val, remove_all=False):
        """Remove the first or all nodes with the given value."""
        if not self.head:
            return False

        removed = False
        curr = self.head
        while curr:
            if curr.data == val:
                removed = True
                next_node = curr.next
                if curr == self.head:
                    self.head = curr.next
                    if self.head:
                        self.head.prev = None
                    else:
                        self.tail = None
                elif curr == self.tail:
                    self.tail = curr.prev
                    if self.tail:
                        self.tail.next = None
                    else:
                        self.head = None
                else:
                    curr.prev.next = curr.next
                    curr.next.prev = curr.prev
                del curr
                if not remove_all:
                    return True
                curr = next_node
            else:
                curr = curr.next
        return removed


def get_int_input(prompt):
    """Safely get an integer input from the user."""
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter an integer.")


def main():
    """Main function to interact with the linked list."""
    l1 = LinkedList()
    num_nodes = get_int_input("Enter the number of nodes for the list: ")

    for i in range(num_nodes):
        while True:
            direction = input(
                f"Insert node {i + 1} at head or tail? (head/tail): "
            ).strip().lower()
            if direction in {"head", "tail"}:
                node_val = get_int_input(f"Enter value of node {i + 1}: ")
                if direction == "head":
                    l1.insert_at_head(node_val)
                else:
                    l1.insert_at_tail(node_val)
                break
            else:
                print("Invalid direction. Please enter 'head' or 'tail'.")

    print("Linked list contents:", end=' ')
    l1.print_list()

    while not l1.is_empty():
        rem = input("Do you want to remove a value? (y/n): ").strip().lower()
        if rem == "y":
            rem_val = get_int_input("Enter the value to remove: ")
            while True:
                mode = input(
                    "Remove first or all occurrences? (f/a): "
                ).strip().lower()
                if mode in {"f", "a"}:
                    remove_all = mode == "a"
                    break
                else:
                    print("Invalid choice. Enter 'f' or 'a'.")
            removed = l1.remove_value(rem_val, remove_all)
            if not removed:
                print("Value not found in the list.")
        else:
            break
        print("Updated list:", end=' ')
        l1.print_list()

    print("Thank you for using the doubly linked list program!")


if __name__ == "__main__":
    main()
