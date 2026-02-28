

---

# 📦 Array-Based Queue in C++

## 📖 Overview

This project contains a generic queue implementation built using a custom dynamic array (`clsDynamicArray<T>`).

The queue follows the **FIFO (First In, First Out)** principle and provides safe operations with proper exception handling.

This implementation is part of my Data Structures practice in C++.

---

## 🚀 Features

* Template-based (supports any data type)
* Array-backed implementation
* Exception handling for empty queue access
* Clean and minimal queue interface

---

## 🛠️ Supported Operations

| Method         | Description                          |
| -------------- | ------------------------------------ |
| `push(T item)` | Insert item at the back of the queue |
| `pop()`        | Remove the front item                |
| `front()`      | Get the front item                   |
| `back()`       | Get the last item                    |
| `Size()`       | Return number of elements            |
| `IsEmpty()`    | Check if queue is empty              |
| `Clear()`      | Remove all elements                  |

---

## ⚠️ Error Handling

The following operations throw `std::out_of_range` if the queue is empty:

* `pop()`
* `front()`
* `back()`

---

## 🧠 Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| `push()`  | O(1)       |
| `pop()`   | O(n)*      |
| `front()` | O(1)       |
| `back()`  | O(1)       |

* `pop()` is O(n) because removing the first element shifts remaining elements in the dynamic array.

---

## 🏗️ Structure

This queue is built on top of a custom dynamic array class:

```
clsMyQueueArr<T>
    └── clsDynamicArray<T>
```

---

## 🎯 Learning Goal

This project was built to:

* Practice template programming
* Understand queue abstraction
* Learn how array-backed queues work internally
* Improve exception-safe design

---
