# ShiftSort
ShiftSort is quicker than MergeSort
Shift Sort is a merging algorithm like Merge Sort, but is more selective on what it merges. Merge Sort splits its array in half continuously until reaching its base case of 2 elements, swaps if needed, and then merges as it returns. Shift Sort uses a derivative array to split in half continuously until reaching a base case of 2 or 3 elements, uses the results to determine what parts of the array to merge, and then merges as it returns.
Shift Sort time and space complexities:

| Complexity |   BigO   |
| ---------- | -------- |
| Best       | O(n)     |
| Average    | O(nlogn) |
| Worst      | O(nlogn) |
| Space      | n        |

With best-case complexity, Shift Sort’s O(n) beats Merge Sort’s O(nlogn). Shift Sort’s average-case complexity is the same as Merge Sort’s, but in real world testing, Shift Sort out performs Merge Sort. For space, at worst, Shift Sort will initialize a second and third list of about n/2, putting the total at n.
