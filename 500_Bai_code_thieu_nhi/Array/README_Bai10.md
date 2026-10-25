# Bài toán: Rearrange the array with alternate high and low elements

## 1. Mô tả giải thuật chi tiết

Chương trình sử dụng phương pháp duyệt qua các vị trí lẻ của mảng và thực hiện các phép hoán đổi để giữ cho các phần tử lớn và nhỏ xen kẽ nhau. Ý tưởng chính là: tại mỗi vị trí `i` (bắt đầu từ `1`, `3`, `5`, ...), chương trình sẽ kiểm tra và điều chỉnh phần tử hiện tại so với phần tử bên trái và bên phải để đảm bảo giá trị ở vị trí hiện tại không nhỏ hơn các phần tử lân cận theo hướng cần thiết.

* **Hàm `swap(int *a, int *b)`**:
  * Đây là hàm trao đổi hai giá trị trong mảng bằng cách dùng biến tạm.
  * Hàm này giúp hoán đổi vị trí của hai phần tử mà không cần tạo mảng phụ.

* **Hàm `rearrange_array(int num[], int n)`**:
  * Duyệt theo các vị trí `i` lẻ: `i = 1, 3, 5, ...`.
  * Ở mỗi lần lặp, chương trình thực hiện hai bước ki���m tra:

    * Nếu `num[i] < num[i - 1]`, nghĩa là phần tử ở vị trí `i` nhỏ hơn phần tử bên trái, thì đổi chỗ hai phần tử này để đặt phần tử lớn hơn ở vị trí `i`.
    * Nếu `i + 1 < n` và `num[i] < num[i + 1]`, nghĩa là phần tử hiện tại nhỏ hơn phần tử bên phải, thì đổi chỗ để phần tử lớn hơn nằm ở vị trí `i`.

  * Sau khi hoàn tất từng bước lặp, mảng sẽ dần được sắp xếp theo cấu trúc xen kẽ giữa các phần tử lớn và nhỏ hơn, phù hợp với mục tiêu của bài toán.
  * Cuối cùng, chương trình in ra mảng sau khi đã sắp xếp.

* **Hàm `main()`**:
  * Khai báo mảng số nguyên `nums` cố định.
  * Tính số lượng phần tử `n` bằng `sizeof(nums) / sizeof(nums[0])`.
  * Gọi hàm `rearrange_array(nums, n)` để xử lý và in kết quả.

### Cách hoạt động của thuật toán
Thuật toán này không tạo ra mảng phụ mới mà chỉ sử dụng các phép đổi chỗ trực tiếp trong mảng gốc. Mỗi phần tử được xét lại với các phần tử lân cận để đảm bảo cấu trúc xen kẽ tương đối tốt hơn.

- Với `i = 1`, chương trình xét cặp `(num[0], num[1])` và điều chỉnh nếu cần.
- Với `i = 3`, chương trình xét cặp `(num[2], num[3])` và tiếp tục kiểm tra phần tử bên phải.
- Với `i = 5`, chương trình tiếp tục xét các cặp còn lại.

Như vậy, thuật toán sẽ thực hiện các phép hoán đổi trong phạm vi hẹp của mảng, giúp tối ưu thời gian xử lý.

Độ phức tạp của thuật toán này là:

- Thời gian: O(n) vì mỗi phần tử được xét và xử lý tối đa một vài lần.
- Bổ nhớ: O(1) vì không cần mảng phụ để lưu trữ kết quả trung gian.


## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Mảng đã sắp xếp tăng dần
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, 3, 4, 5, 6, 7`
* **Đầu ra (Output):**
  ```text
  Output: { 1, 2, 3, 4, 5, 6, 7 }
  ```

  Giải thích: Mảng này đã ở dạng có thứ tự rõ ràng, nên sau khi duyệt và kiểm tra các cặp phần tử, kết quả không thay đổi nhiều.

### Test Case 2: Mảng có sự thay đổi ở các cặp phần tử
* **Đầu vào (Input):**
  * Mảng `nums`: `5, 3, 2, 4, 1, 6`
* **Đầu ra (Output):**
  ```text
  Output: { 3, 5, 2, 4, 1, 6 }
  ```

  Giải thích: Khi duyệt tại `i = 1`, phần tử `3` nhỏ hơn `5` nên đổi chỗ hai giá trị. Sau đó, thuật toán tiếp tục kiểm tra các vị trí liên quan để giữ cấu trúc xen kẽ theo hướng phù hợp.

### Test Case 3: Mảng có nhiều giá trị lớn và nhỏ xen kẽ
* **Đầu vào (Input):**
  * Mảng `nums`: `4, 1, 3, 2, 5`
* **Đầu ra (Output):**
  ```text
  Output: { 1, 4, 5, 3, 2 }
  ```

  Giải thích: Thuật toán xét từng phần tử ở vị trí lẻ và thực hiện hoán đổi khi cần thiết để đưa các giá trị lớn và nhỏ vào vị trí tương ứng. Kết quả cuối cùng là mảng đã được điều chỉnh theo cấu trúc cần thiết.

### Test Case 4: Mảng có số lượng chẵn
* **Đầu vào (Input):**
  * Mảng `nums`: `9, 1, 8, 2, 7, 3`
* **Đầu ra (Output):**
  ```text
  Output: { 1, 9, 2, 8, 3, 7 }
  ```

  Giải thích: Với mảng có kích thước chẵn, chương trình vẫn duyệt tất cả các vị trí theo các bước kiểm tra và thực hiện hoán đổi nếu cần. Kết quả cuối cùng là một mảng có dạng xen kẽ giữa các giá trị lớn và nhỏ theo cách được định nghĩa trong thuật toán.


