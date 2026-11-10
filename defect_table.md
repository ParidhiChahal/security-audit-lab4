# Security Audit Defect Table

| Defect # | Vulnerability Type | Exact Location (Function / Line) | Security Impact |
| :--- | :--- | :--- | :--- |
| **1** | Unchecked `malloc` (Null Pointer Dereference) | `allocate_buffer()` / Line 14 | Can cause segmentation faults or allow attackers to crash the application via Denial of Service (DoS). |
| **2** | Integer Overflow / Buffer Overflow | `process_size()` / Line 28 | Arithmetic overflow leads to a small buffer allocation size, resulting in a heap-based buffer overflow and potential remote code execution (RCE). |
| **3** | Use-After-Free | `free_resource()` / Line 45 | Accessing memory after it has been freed can lead to arbitrary code execution or memory corruption. |
| **4** | Double Free | `cleanup()` / Line 62 | Freeing the same pointer twice corrupts memory management metadata, leading to crashes or exploitable heap corruption. |
| **5** | Uninitialized Memory Read | `parse_data()` / Line 78 | Reading variables before assignment can leak sensitive stack data or cause undefined behavior. |
