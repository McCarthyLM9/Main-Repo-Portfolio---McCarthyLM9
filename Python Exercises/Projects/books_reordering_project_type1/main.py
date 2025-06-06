"""Main module for the Books Reordering Project.
   This module reads a file containing book information, creates a linked list
   of books, and prints them in order by author.
"""
from pathlib import Path
from linked_list import LinkedList
from book import Book


def main():
    """Main function to read a file containing book information,
       create a linked list of books, and print them in order by author.
    """

    project_path = Path(__file__).parent.resolve()

    file_name = input(
        "Enter the file name (relative path within project directory): "
    ).strip()

    file_path = project_path / file_name

    try:
        with file_path.open('r', encoding='utf-8') as input_file:
            book_list = LinkedList()

            for line in input_file:
                parts = line.strip().split(',')
                if len(parts) < 3:
                    continue
                title, author, year = [part.strip() for part in parts]
                book = Book(title, author, year)
                book_list.insert_in_order(book)

            book_list.print_list()

    except FileNotFoundError:
        print(f"Error opening input file: {file_name}")


if __name__ == "__main__":
    main()
