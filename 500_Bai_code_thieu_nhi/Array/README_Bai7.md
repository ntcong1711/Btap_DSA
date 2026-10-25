# Bài toán: Sắp xếp mảng chứa các số 0, 1, 2 (Dutch National Flag Problem)

## 1. Mô tả giải thuật chi tiết

Chương trình sử dụng phương pháp chia ba vùng (Dutch National Flag) để sắp xếp mảng sao cho tất cả các phần tử `0` đứng ở đầu mảng, các phần tử `1` ở giữa, và các phần tử `2` ở cuối mảng.

### Ý tưởng của thuật toán

Thuật toán này hoạt động theo kiểu 3 con trỏ:

- `a`: vị trí bắt đầu của vùng `0`
- `b`: vị trí đang xét hiện tại (`mid`)
- `c`: vị trí cuối của vùng `2`

Trong quá trình duyệt, ta xét phần tử `A[b]`:

- Nếu `A[b] == 0`: đổi chỗ `A[a]` và `A[b]`, sau đó tăng `a` và `b`.
- Nếu `A[b] == 1`: phần tử này đã ở đúng vị trí, chỉ cần tăng `b`.
- Nếu `A[b] == 2`: đổi chỗ `A[b]` và `A[c]`, sau đó giảm `c`.

Quá trình lặp kết thúc khi `b > c`, nghĩa là toàn bộ mảng đã được sắp xếp đúng thứ tự.

### Các hàm trong chương trình

* **Hàm `swap(int *a, int *b)`**:
  * Đổi chỗ hai phần tử được truyền theo con trỏ.

* **Hàm `sort(int A[], int n)`**:
  * Khởi tạo ba biến `a = 0`, `b = 0`, `c = n - 1`.
  * Duyệt mảng trong khi `b <= c`:
    * Nếu `A[b] == 0`: hoán vị `A[a]` và `A[b]`, sau đó tăng `a` và `b`.
    * Nếu `A[b] == 1`: tăng `b`.
    * Nếu `A[b] == 2`: hoán vị `A[b]` và `A[c]`, sau đó giảm `c`.
  * Sau khi xong, in mảng đã được sắp xếp ra màn hình.

* **Hàm `main()`**:
  * Khai báo mảng `A` với các giá trị `0`, `1`, `2`.
  * Tính số lượng phần tử `n` bằng `sizeof(A) / sizeof(A[0])`.
  * Gọi hàm `sort(A, n)` để sắp xếp.

### Cách hoạt động của thuật toán

Thuật toán chia mảng thành 3 phần:

- Phần đầu: toàn bộ là `0`
- Phần giữa: toàn bộ là `1`
- Phần cuối: toàn bộ là `2`

Mỗi lần xét một phần tử, thuật toán sẽ đưa nó về đúng vùng tương ứng mà không làm mất dữ liệu đã sắp xếp.

Độ phức tạp của thuật toán này là:

- Thời gian: O(n) vì mỗi phần tử chỉ được xét tối đa một lần.
- Bổ nhớ: O(1) vì chỉ sử dụng một số biến phụ nhỏ và không cần mảng phụ.

## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Mảng hỗn hợp nhiều giá trị 0, 1, 2
* **Đầu vào (Input):**
  * Mảng `A`: `0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0`
* **Đầu ra (Output):**
  ```text
  { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2 }
  ```

  Giải thích: Mảng sau khi sắp xếp xếp các phần tử `0` lên đầu, các phần tử `1` ở giữa và các phần tử `2` ở cuối.

### Test Case 2: Mảng đã được sắp xếp đúng thứ tự
* **Đầu vào (Input):**
  * Mảng `A`: `0, 0, 1, 1, 2, 2, 2`
* **Đầu ra (Output):**
  ```text
  { 0, 0, 1, 1, 2, 2, 2 }
  ```

  Giải thích: Mảng đã ở trạng thái đúng nên thuật toán không cần thay đổi nhiều, chỉ duyệt qua và giữ nguyên.

### Test Case 3: Mảng chỉ chứa số 0 hoặc 1 hoặc 2
* **Đầu vào (Input):**
  * Mảng `A`: `0, 0, 0, 0, 0`
* **Đầu ra (Output):**
  ```text
  { 0, 0, 0, 0, 0 }
  ```

  Giải thích: Tất cả các phần tử đều là `0`, nên sau khi sắp xếp, mảng vẫn giữ nguyên.





