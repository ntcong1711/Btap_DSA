# Bài toán: Tìm tất cả các mảng con có tổng bằng 0 (Find all subarrays with zero sum)

## 1. Mô tả giải thuật chi tiết
Chương trình sử dụng phương pháp duyệt vét cạn (Brute Force) để xét tất cả các mảng con liên tiếp của mảng ban đầu và kiểm tra tổng của từng mảng con đó.

* **Hàm `find_Print_Subarray(int nums[], int n)`**:
  * Khởi tạo biến `found = 0` để kiểm tra xem có tồn tại mảng con nào có tổng bằng 0 hay không.
  * Duyệt qua tất cả các vị trí bắt đầu `i` của mảng con:

    * Vòng lặp ngoài (`i` chạy từ `0` đến `n - 1`) chọn điểm bắt đầu của mảng con.
    * Khởi tạo biến `sum = 0` để tính tổng của các phần tử từ `i` đến `j`.
    * Vòng lặp trong (`j` chạy từ `i` đến `n - 1`) cộng dần các phần tử `nums[j]` vào `sum`.

  * Kiểm tra điều kiện tổng: Nếu `sum == 0`, nghĩa là mảng con từ `i` đến `j` có tổng bằng 0, chương trình sẽ in ra mảng con đó theo dạng: `{ nums[i], nums[i+1], ..., nums[j] }`.
  * Mỗi khi tìm thấy một mảng con có tổng bằng 0, chương trình cập nhật `found = 1`.
  * Sau khi kết thúc tất cả các vòng lặp, nếu `found` vẫn bằng `0`, chương trình sẽ in ra: `Subarray with zero-sum does not exist`.

* **Hàm `main()`**:
  * Khai báo mảng `nums` cố định trong chương trình.
  * Tính số lượng phần tử `n` của mảng bằng: `sizeof(nums) / sizeof(nums[0])`.
  * Gọi hàm `find_Print_Subarray(nums, n)` để tìm và in ra tất cả các mảng con có tổng bằng 0.

### Cách hoạt động của thuật toán
Thuật toán này xét tất cả các khoảng liên tiếp có thể có trong mảng:

- Với `i = 0`, xét các khoảng bắt đầu từ vị trí đầu tiên.
- Với `i = 1`, xét các khoảng bắt đầu từ vị trí thứ hai.
- ...
- Với `i = n - 1`, xét các khoảng chỉ có một phần tử.

Với mỗi khoảng bắt đầu `i`, chương trình sẽ tính tổng theo từng vị trí kết thúc `j`, rồi kiểm tra xem tổng ấy có bằng 0 hay không.

Độ phức tạp của thuật toán này là:

- Thời gian: O(n²) vì xét tất cả các mảng con liên tiếp.
- Bổ nhớ: O(1) vì không cần mảng phụ để lưu kết quả.


## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Có nhiều mảng con có tổng bằng 0
* **Đầu vào (Input):**
  * Mảng `nums`: `3, 4, -7, 3, 1, 3, 1, -4, -2, -2`
* **Đầu ra (Output):**
  ```text
  The subarrays with a sum of 0 are:
  { 3, 4, -7 }
  { 4, -7, 3 }
  { -7, 3, 1 }
  { 3, 1, 3 }
  { 1, 3, 1 }
  { 3, 1, -4 }
  { 1, -4, -2 }
  { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
  ```

  Giải thích: Trong mảng trên có nhiều khoảng con liên tiếp có tổng bằng 0, ví dụ:
  * `3 + 4 + (-7) = 0`
  * `4 + (-7) + 3 = 0`
  * `(-7) + 3 + 1 = 0`
  * `3 + 4 + (-7) + 3 + 1 + 3 + 1 + (-4) + (-2) + (-2) = 0`

### Test Case 2: Có một mảng con duy nhất có tổng bằng 0
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, -3, 4, 5`
* **Đầu ra (Output):**
  ```text
  The subarrays with a sum of 0 are:
  { 1, 2, -3 }
  ```

  Giải thích: Mảng con `1, 2, -3` có tổng là `0`.

### Test Case 3: Không có mảng con nào có tổng bằng 0
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, 3, 4`
* **Đầu ra (Output):**
  ```text
  The subarrays with a sum of 0 are:
  Subarray with zero-sum does not exist
  ```

  Giải thích: Không có khoảng con nào trong mảng này có tổng bằng 0.




