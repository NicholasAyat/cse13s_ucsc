# Homework 4: Design Document

  * author: *Nicholas Ayat* 
  * date: February 2025

## introduction

This document outlines the approach for implementing the required functions for the text editor. The goal is to work with linked lists and stacks while maintaining efficient memory management and ensuring that the undo feature functions correctly.

### **1. `ll_text *append_text(ll_text *list, char *text)`**
This function appends a new node to the end of the linked list.
- Traverse to the end of the linked list.
- Allocate memory for a new node.
- Use `strdup()` to copy the text into the new node.
- Set the `next` pointer of the last node to the new node.
- If `list` is `NULL`, return the newly created node.

### **2. `ll_text *insert_text(ll_text *list, char *text, int position)`**
This function inserts a new node at a given position.
- Traverse the list up to `position - 1`.
- Allocate memory for a new node and copy the text.
- Adjust pointers to insert the node at the specified position.
- If inserting at the head, update the list’s head pointer.

### **3. `ll_text *delete_text(ll_text *list, int position)`**
This function deletes a node at a given position.
- Traverse to the node just before the target position.
- Update the previous node’s `next` pointer to skip over the deleted node.
- Free the memory allocated for the removed node.
- If deleting the head, update the head pointer.
- Return the updated list.

### **4. `ll_text *replace_text(ll_text *list, char *text, int position)`**
This function replaces the text in a node at a specified position.
- Traverse to the required node.
- Free the existing text.
- Use `strdup()` to copy the new text into the node.
- Return the list.

### **5. `ll_text *duplicate_ll_text(ll_text *list)`**
This function creates a deep copy of the linked list.
- Allocate new nodes and copy text using `strdup()`.
- Maintain original order.
- Return the head of the new list.

### **6. `int ll_text_length(ll_text *list)`**
This function returns the length of the linked list.
- Iterate through the list and count nodes.
- Return the count.

### **7. `ll_text_stack *push_duplicate(ll_text_stack *stack)`**
This function pushes a duplicate of the current text state onto the stack.
- Allocate memory for a new stack node.
- Duplicate the current list using `duplicate_ll_text()`.
- Set the `next` pointer of the new stack node to the current stack top.
- Return the new stack top.

### **8. `ll_text_stack *push_empty(ll_text_stack *stack)`**
This function pushes an empty text state onto the stack.
- Allocate memory for a new stack node.
- Set its text pointer to `NULL`.
- Set the `next` pointer to the current stack top.
- Return the new stack top.

### **9. `ll_text_stack *pop_stack(ll_text_stack *stack)`**
This function removes the top entry from the stack.
- Store the next node.
- Free the memory of the top node and its associated text list.
- Return the new top node of the stack.

## **testing plan**
- Use `editor_lib_test.c` to verify each function.
- Start with `ll_text_length()` and `append_text()`.
- Gradually enable more tests as functions are implemented.
- Run `valgrind --leak-check=full ./editor_lib_test` to check for memory leaks.

## **potential enhancements**
- Implement search functionality.
- Improve text rendering.
- Allow longer lines.
- Add syntax highlighting.