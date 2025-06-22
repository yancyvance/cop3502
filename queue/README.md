# Queue

This queue implementation has two backend implementations. One is using a Singly Linked List while the other is a Variable-Length Array. The Singly Linked List can easily be swapped to use either the version that only keeps track of the `head` only or both the `head` and `tail`.

Refer to the documentation for the list of [operations](https://docs.google.com/document/d/e/2PACX-1vRYRk3yFp3sDWOZuxTBIEF2kIx-sOvx5vBtff2o7MS7GLH8A-F3XFgbi6z1t6bDKyjUm7xm-Ay_WTNM/pub "operations") supported.

## Dependencies
The following header files are required in addition to the queue header files. Download the appropriate files from the provided links:
- [Singly Linked List](https://github.com/yancyvance/cop3502/tree/main/linkedlist "Singly Linked List") -  **`sll.h`** (`head` only) or **`sll2.h`** (both `head` and `tail`)
- [Variable-Length Array](https://github.com/yancyvance/cop3502/tree/main/array "Variable-Length Array") - **`vla.h`**


## Usage
- **`queue_sll.h`** - Queue Implementation using a Singly Linked List (both `head` and `tail`)
- **`queue_vla.h`** - Queue Implementation using a Variable-Length Array
- **`queue.c`** - Sample Tester File
