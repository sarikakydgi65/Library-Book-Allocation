# 📚 Library Book Allocation System

A C program that manages book allocation and waiting queue for a library using circular queue data structure.

---

## ✨ Features

### 📖 Book Management
- Pre-loaded books: DSA (2 copies), OS (1 copy), DBMS (1 copy)
- Display available books with copy counts
- Request books if copies are available
- Return books and automatically allocate to waiting students

### ⏳ Waiting Queue System
- Circular queue implementation (max 5 students)
- FIFO (First In First Out) allocation
- Automatic allocation when books are returned
- Display waiting queue status

### 🔄 Book Allocation Process
1. Student requests a book
2. If copy available → Allocated immediately
3. If no copies available → Added to waiting queue
4. When book returned → Allocated to first waiting student

---

## 🚀 How to Run

### Prerequisites
- C compiler (GCC, MinGW, or any C compiler)

### Using Command Line (Linux/Mac)
```bash
gcc library_management.c -o library_management
./library_management
```

### Using Command Line (Windows)
```bash
gcc library_management.c -o library_management.exe
library_management.exe
```

### Using VS Code
1. Install **C/C++ Extension Pack**
2. Open the `.c` file
3. Click **Run** button or press `F5`
4. Select **C++ (GCC/LLDB)**

---

## 📖 How to Use

1. **Display Books** — View all books and available copies
2. **Request Book**
   - Enter student name
   - Enter book name (DSA, OS, or DBMS)
   - Gets book if available or joins waiting queue
3. **Return Book**
   - Enter book name to return
   - Book is allocated to next waiting student automatically
4. **Display Queue** — View all pending requests
5. **Exit** — Close the program

---

## 💻 Code Structure

```
Library Book Allocation System
├── Structures
│   ├── struct Book (name, copies)
│   └── struct Request (studentName, bookName)
├── Circular Queue Functions
│   ├── isEmpty()   - Check if queue is empty
│   ├── isFull()    - Check if queue is full
│   └── enqueue()   - Add request to queue
├── Book Management Functions
│   ├── displayBooks()  - Show available books
│   ├── findBook()      - Search for book by name
│   ├── requestBook()   - Handle book requests
│   └── returnBook()    - Process returns & auto-allocate
└── displayQueue()      - Show waiting list
```

---

## 🎮 Demo Example

**Scenario 1: Book Available**
```
Student: Raj
Book: DSA
Output: "Book 'DSA' allocated to Raj"
```

**Scenario 2: No Copies Available**
```
Student: Priya
Book: OS (0 copies left)
Output: "Book not available. Added to waiting queue"
```

**Scenario 3: Auto-allocation on Return**
```
Student returns OS → Automatically allocated to Priya from queue
Output: "Book allocated to waiting user Priya"
```

---

## 📊 Queue Visualization

```
Circular Queue (MAX = 5):
[Student1: DSA] → [Student2: OS] → [Student3: DBMS] → [Empty] → [Empty]
```

---

## 🛠️ Technologies Used

| Technology            | Usage                        |
|-----------------------|------------------------------|
| C Programming Language | Core logic                  |
| Circular Queue        | Waiting list data structure  |
| string.h              | String operations            |
| stdio.h               | Standard I/O                 |

---

## ⚙️ System Requirements

- **OS:** Windows, Linux, macOS
- **Compiler:** Any C compiler (GCC 4.0+)
- **Memory:** Minimum 64MB RAM

---

## 🔮 Future Enhancements

- [ ] Add new books dynamically
- [ ] Student login system
- [ ] Due date and fine system
- [ ] Save/Load data from file
- [ ] Graphical User Interface
- [ ] Multiple book requests per student
- [ ] Priority queue for special students

---

## 📋 Sample Input/Output

```
===== LIBRARY BOOK ALLOCATION SYSTEM =====
1. Display Available Books
2. Request Book
3. Return Book
4. Display Waiting Queue
5. Exit
Enter your choice: 1

--- Available Books in Library ---
1. DSA  - 2 copies
2. OS   - 1 copies
3. DBMS - 1 copies
```

---

## 📄 License

Educational purpose project. Free to modify and distribute.

---

## 👨‍💻 Author

**Shreegowri-CM**
