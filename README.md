# CPlusPlusPad
CPlusPlusPad is a fully functional notepad application built in C++. It allows users to create, save, delete, and edit text files with ease, providing all the essential features of a standard notepad.


## Features

- **Create** new text files
- **Save** text files
- **Open** existing text files
- **Delete** text within files
- **Navigate** through text using arrow keys

## How to Use

### Compilation

To compile the CppNotePro application, you need a C++ compiler installed on your system.


### Controls

- **Type text**: Just start typing to insert characters.
- **Enter key**: Create a new line.
- **Backspace key**: Delete the character before the cursor.
- **Arrow keys**: Move the cursor up, down, left, or right.
- **Esc key**: Save the file and exit the application.

## Code Overview

### Class `node`

A class representing a node in a doubly linked list, containing a character and pointers to the next, previous, up, and down nodes.

### Class `TwoDDLLADT`

A class representing a two-dimensional doubly linked list abstract data type (ADT). It manages the text and cursor operations, including insertion, deletion, navigation, and file handling.

#### Key Methods

- `Insert(char c)`: Inserts a character at the current cursor position.
- `Delete()`: Deletes the character at the current cursor position.
- `Save()`: Saves the current text to a file.
- `Load()`: Loads text from a file.
- `Up()`, `Down()`, `Left()`, `Right()`: Navigates the cursor.
- `PrintAll()`: Prints the entire text.
- `PrintCursor()`: Prints the text with the cursor position.

### Main Function

The main function initializes the notepad, loads any existing text from a file, and enters an input loop to handle user commands.

## Dependencies

- **conio.h**: For handling keyboard inputs.
- **windows.h**: For cursor manipulation and clearing the screen.

## Contributing

Contributions are welcome! Please fork the repository and submit pull requests for any improvements or bug fixes.
