# Bài toán: Tìm mảng con có tổng cho trước và có độ dài lớn nhất (Find maximum length sub-array having given sum)

## 1. Mô tả giải thuật chi tiết

Chương trình sử dụng phương pháp duyệt vét cạn (Brute Force) để xét tất cả các mảng con liên tiếp trong mảng ban đầu và kiểm tra nếu tổng của chúng bằng giá trị `target` đã cho. Khi tìm thấy các mảng con thỏa mãn, chương trình sẽ lưu lại mảng con có độ dài lớn nhất để in ra sau cùng.

* **Hàm `find_Print_Subarray(int nums[], int n, int target)`**:
  * Khởi tạo biến `found = 0` để kiểm tra xem có tồn tại mảng con nào có tổng bằng `target` hay không.
  * Khởi tạo `length_max = 0` để lưu độ dài lớn nhất tìm được.
  * Khởi tạo `a` và `b` để lưu vị trí bắt đầu và kết thúc của mảng con có độ dài lớn nhất.
  * Duyệt qua tất cả vị trí bắt đầu `i` của mảng con:
    * `i` chạy từ `0` đến `n - 1`.
    * Khởi tạo `sum = 0` để tính tổng các phần tử từ `i` đến `j`.
    * Duyệt tiếp qua các vị trí kết thúc `j` từ `i` đến `n - 1`.
    * Cộng dần `nums[j]` vào `sum`.
  * Nếu `sum == target`, nghĩa là mảng con từ `i` đến `j` có tổng bằng giá trị cần tìm, chương trình sẽ:
    * Đặt `found = 1`.
    * Tính độ dài `j - i + 1`.
    * Nếu độ dài này lớn hơn hoặc bằng `length_max`, cập nhật `length_max`, `a`, `b`.
    * In ra mảng con theo định dạng: `{ nums[i], nums[i+1], ..., nums[j] }`.
  * Sau khi kết thúc tất cả các vòng lặp, nếu `found` vẫn bằng `0`, chương trình sẽ in ra: `Subarray with s sum of target does not exist`.
  * Cuối cùng, chương trình in ra mảng con dài nhất tìm được theo định dạng: `The longest subarray is { ... } having length X`.

* **Hàm `main()`**:
  * Khai báo mảng `nums` cố định.
  * Tính số phần tử `n` của mảng bằng `sizeof(nums) / sizeof(nums[0])`.
  * Khai báo biến `target` là giá trị cần tìm.
  * Gọi hàm `find_Print_Subarray(nums, n, target)` để thực hiện tìm kiếm và in kết quả.

### Cách hoạt động của thuật toán
Thuật toán này xét tất cả các khoảng liên tiếp có thể có trong mảng:

- Với `i = 0`, xét các khoảng bắt đầu từ vị trí đầu tiên.
- Với `i = 1`, xét các khoảng bắt đầu từ vị trí thứ hai.
- ...
- Với `i = n - 1`, xét các khoảng chỉ có một phần tử.

Với mỗi khoảng bắt đầu `i`, chương trình kiểm tra mọi khoảng kết thúc `j` để tính tổng. Nếu tổng bằng `target`, chương trình lưu lại và in ra mảng con đó. Đồng thời, nếu mảng con mới có độ dài lớn hơn hoặc bằng độ dài lớn nhất cũ, chương trình cập nhật lại mảng con dài nhất.

Độ phức tạp của thuật toán này là:

- Thời gian: O(n²) vì xét tất cả các mảng con liên tiếp.
- Bổ nhớ: O(1) vì không cần mảng phụ để lưu trữ kết quả trung gian.

## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Có nhiều mảng con có tổng bằng target và có mảng con dài nhất
* **Đầu vào (Input):**
  * Mảng `nums`: `5, 6, -5, 5, 3, 5, 3, -2, 0`
  * `target = 8`
* **Đầu ra (Output):**
  ```text
  The subarrays with a sum of 8 are:
  { -5, 5, 3, 5 }
  { 5, 3 }
  { 3, 5 }
  { 5, 3 }
  The longest subarray is {-5, 5, 3, 5 } having length 4 
  ```

  Giải thích: Trong mảng trên có nhiều mảng con liên tiếp có tổng bằng `8`, ví dụ:
  * `-5 + 5 + 3 + 5 = 8`
  * `5 + 3 = 8`
  * `3 + 5 = 8`
  * `5 + 3 = 8`

  Trong số đó, mảng con dài nhất là `{-5, 5, 3, 5}` có độ dài `4`.

### Test Case 2: Có một mảng con duy nhất có tổng bằng target
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, -3, 4, 5`
  * `target = 0`
* **Đầu ra (Output):**
  ```text
  The subarrays with a sum of 0 are:
  { 1, 2, -3 }
  The longest subarray is { 1, 2, -3 } having length 3 
  ```

  Giải thích: Chỉ có duy nhất mảng con `1, 2, -3` có tổng bằng `0` và cũng là mảng con dài nhất.

### Test Case 3: Không có mảng con nào có tổng bằng target
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, 3, 4`
  * `target = 11`
* **Đầu ra (Output):**
  ```text
  The subarrays with a sum of 11 are:
  Subarray with s sum of 11 does not exist
  The longest subarray is { } having length 0 
  ```

  Giải thích: Không có khoảng con nào trong mảng này có tổng bằng `11`, do đó chương trình sẽ báo không tìm thấy và in ra mảng con dài nhất rỗng với độ dài bằng `0`.


