"""Linked list implementation for managing books in a collection."""


class Node:
    """Node class for linked list,
       containing a book and a reference to the next node.
    """
    def __init__(self, book):
        """Initialize a Node instance with a book and
           set the next node to None.
        """
        self.data = book
        self.next = None


class LinkedList:
    """Linked list class to manage a collection of books."""
    def __init__(self):
        """Initialize an empty linked list."""
        self.head = None

    def insert_in_order(self, book):
        """Insert a book into the linked list in
           alphabetical order by title.
        """
        new_node = Node(book)
        if not self.head or book.get_author() < self.head.data.get_author():
            new_node.next = self.head
            self.head = new_node
            return
        curr = self.head
        while curr.next and curr.next.data.get_author() < book.get_author():
            curr = curr.next
        new_node.next = curr.next
        curr.next = new_node

    def print_list(self):
        """Print the books in the linked list."""
        curr = self.head
        while curr:
            curr.data.print_book()
            curr = curr.next
