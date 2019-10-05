# ShiftSort

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/9014f709b9514bdca852b9d3ccff75e2)](https://app.codacy.com/app/JamesQuintero/ShiftSort?utm_source=github.com&utm_medium=referral&utm_content=JamesQuintero/ShiftSort&utm_campaign=Badge_Grade_Dashboard)

![Preview](./ShiftSort%20vs%20MergeSort%20execution%20time%20graph.PNG)

ShiftSort is a stable, adaptive, divide-and-conquer sorting algorithm. When the list is already partily sorted, Shiftsort beats any other sorting algorithm. 

It’s similar to Merge Sort, but is more selective on what it merges. Merge Sort splits its array in half continuously until reaching its base case of 2 elements, swaps if needed, and then merges as it returns. Shift Sort uses a derivative array to split in half continuously until reaching a base case of 2 or 3 elements, uses the results to determine what parts of the array to merge, and then merges as it returns. 


**Shift Sort time and space complexities:**

| Complexity |   BigO   |
| ---------- | -------- |
| Best       | O(n)     |
| Average    | O(nlogn) |
| Worst      | O(nlogn) |
| Space      | n        |

Shift Sort has a best-case time complexity of O(n) because it uses a secondary list, and if the secondary list is empty, the array is already sorted and the algorithm stops after n iterations. 
Shift Sort’s O(n) beats Merge Sort’s O(nlogn). Shift Sort’s average-case complexity is the same as Merge Sort’s, but in real world testing, Shift Sort out performs Merge Sort. For space, at worst, Shift Sort will initialize a second and third list of about n/2, putting the total at n. 


**Main parts of Shift Sort:**
1)	Derivative List Creation
2)	Splitting of Derivative list
3)	Merging Sublists

*[See ShiftSort-Analysis.pdf for step-by-step on Shift Sort's inner workings](../master/ShiftSort-Analysis.pdf)*
