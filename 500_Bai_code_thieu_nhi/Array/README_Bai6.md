# Bài toán: Tìm mảng con lớn nhất có số lượng số 0 và số 1 bằng nhau (Find the largest subarray having an equal number of 0’s and 1’s)

## 1. Mô tả giải thuật chi tiết

Bài toán yêu cầu tìm mảng con liên tiếp có số lượng phần tử bằng 0 và bằng 1 bằng nhau, đồng thời chọn mảng con có chiều dài lớn nhất. Nếu có nhiều mảng con cùng có độ dài lớn nhất, chương trình sẽ in ra tất cả các mảng con đó.

### Ý tưởng của thuật toán

Thuật toán sử dụng phương pháp duyệt vét cạn (Brute Force) để xét tất cả các đoạn con liên tiếp trong mảng.

- Với mỗi vị trí bắt đầu `i`, ta xét các đoạn con bắt đầu từ `i`.
- Với mỗi vị trí kết thúc `j`, ta đếm số lượng số `0` và số `1` trong đoạn từ `i` đến `j`.
- Khi số lượng số `0` bằng số lượng số `1`, ta xác định đây là một mảng con hợp lệ.
- Trong số các mảng con hợp lệ, ta so sánh độ dài của chúng để tìm ra đoạn dài nhất.
- Nếu có nhiều đoạn có cùng độ dài lớn nhất, chương trình lưu và in tất cả chúng.

### Hàm `find_largest_subarray(int nums[], int n)`

* Khởi tạo:
  * `max_length = 0`: lưu chiều dài lớn nhất tìm được.
  * `A[n]` và `B[n]`: lưu vị trí bắt đầu và vị trí kết thúc của các mảng con có độ dài lớn nhất.
  * `t = 0`: biến đếm số lượng mảng con có cùng độ dài lớn nhất.

* Duyệt vòng lặp ngoài (`i` từ `0` đến `n - 1`):
  * `count_0 = 0` và `count_1 = 0`: đếm số lượng số 0 và số 1 trong đoạn hiện tại.

* Duyệt vòng lặp trong (`j` từ `i` đến `n - 1`):
  * Nếu `nums[j] == 0`, tăng `count_0`.
  * Nếu `nums[j] == 1`, tăng `count_1`.
  * Khi `count_0 == count_1`, nghĩa là đoạn từ `i` đến `j` có số lượng số 0 và số 1 bằng nhau.

* Xử lý độ dài:
  * `current_length = j - i + 1`.
  * Nếu `current_length == max_length`, nghĩa là tìm được thêm một mảng con khác có cùng độ dài lớn nhất, ta lưu vị trí bắt đầu và kết thúc vào `A` và `B`.
  * Nếu `current_length > max_length`, cập nhật `max_length` và lưu vị trí mới.

* Sau khi duyệt xong:
  * Nếu `max_length == 0`, in ra: `No such subarray exists.`
  * Ngược lại, in ra tất cả các mảng con dài nhất đó theo định dạng:
    `Largest subarray is { ... } và { ... } having length X`

### Hàm `main()`

* Khai báo mảng `nums` cố định.
* Tính số phần tử `n` bằng `sizeof(nums) / sizeof(nums[0])`.
* Gọi hàm `find_largest_subarray(nums, n)` để tìm và in kết quả.

### Cách hoạt động của thuật toán

Thuật toán xét tất cả các đoạn con liên tiếp có thể có trong mảng:

- Với `i = 0`, xét tất cả các đoạn bắt đầu từ vị trí đầu tiên.
- Với `i = 1`, xét tất cả các đoạn bắt đầu từ vị trí thứ hai.
- ...
- Với `i = n - 1`, xét các đoạn chỉ chứa một phần tử.

Với mỗi đoạn, chương trình đếm số lượng số 0 và số 1, nếu hai lượng này bằng nhau thì đoạn đó hợp lệ. Sau đó, chương trình so sánh độ dài của đoạn hợp lệ với `max_length` để tìm ra đoạn dài nhất.

### Độ phức tạp của thuật toán

- Thời gian: O(n²) vì xét tất cả các đoạn con liên tiếp.
- Bổ nhớ: O(n) vì cần lưu vị trí bắt đầu và kết thúc của các mảng con dài nhất trong các mảng `A` và `B`.

## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Có nhiều mảng con dài nhất cùng có số lượng số 0 và số 1 bằng nhau

* Đầu vào (Input):
  * Mảng `nums`: `0, 0, 1, 0, 1, 0, 0`

* Đầu ra (Output):
  ```text
  Largest subarray is {0, 1, 0, 1} và {1, 0, 1, 0} having length 4
  ```

  Giải thích:
  * Mảng con `{0, 1, 0, 1}` có 2 số 0 và 2 số 1.
  * Mảng con `{1, 0, 1, 0}` cũng có 2 số 0 và 2 số 1.
  * Độ dài của cả hai mảng con đều là 4, là lớn nhất có thể có trong mảng này.

### Test Case 2: Có một mảng con dài nhất duy nhất

* Đầu vào (Input):
  * Mảng `nums`: `1, 0, 1, 0`

* Đầu ra (Output):
  ```text
  Largest subarray is {1, 0, 1, 0} having length 4
  ```

  Giải thích:
  * Đoạn con toàn bộ mảng `{1, 0, 1, 0}` có số lượng số 0 và số 1 bằng nhau (2 và 2).
  * Đây là mảng con dài nhất có thể có.

### Test Case 3: Không có mảng con nào thỏa mãn điều kiện

* Đầu vào (Input):
  * Mảng `nums`: `1, 1, 1, 1`

* Đầu ra (Output):
  ```text
  No such subarray exists.
  ```

  Giải thích:
  * Mảng này chỉ chứa số 1, không có số 0 nào, nên không thể tìm được đoạn con có số lượng số 0 bằng số lượng số 1.

### Test Case 4: Có mảng con dài nhất với nhiều giá trị bằng nhau

* Đầu vào (Input):
  * Mảng `nums`: `0, 1, 1, 0, 0, 1`

* Đầu ra (Output):
  ```text
  Largest subarray is {0, 1, 1, 0} having length 4
  ```

  Giải thích:
  * Mảng con `{0, 1, 1, 0}` có 2 số 0 và 2 số 1.
  * Đây là đoạn dài nhất thỏa mãn điều kiện trong mảng.

---

Bài toán này giúp rèn luyện tư duy về việc duyệt tất cả các đoạn con liên tiếp và theo dõi số lượng phần tử trong từng đoạn để tìm ra mảng con có tính chất đặc biệt.
