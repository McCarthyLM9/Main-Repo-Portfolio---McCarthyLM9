"""Book class for managing book information and
   printing details in specific format.
"""


class Book:
    """
       A class to represent a book with title, author, and year of publication.
    """
    def __init__(self, title, author, year):
        """Initialize a Book instance.

        Args:
            title (str): book title
            author (str): author's name
            year (int): year of publication
        """
        self.title = title
        self.author = author
        self.year = year

    def get_title(self):
        """Get the title of the book.

        Returns:
            str: the title of the book
        """
        return self.title

    def get_author(self):
        """Get the author of the book.

        Returns:
            str: the author's name
        """
        return self.author

    def get_year(self):
        """Get the year of publication of the book.

        Returns:
            int: the year of publication
        """
        return self.year

    def print_book(self):
        """Print the book details in the format: "author, "title" (year)"."""
        print(f'{self.author}, "{self.title}" ({self.year})')
