# Bài toán: Tìm cặp số trong mảng có tổng cho trước (Find Pair with Given Sum)

## 1. Mô tả giải thuật chi tiết
Chương trình sử dụng phương pháp vét cạn (Brute Force) để duyệt qua tất cả các khả năng kết hợp của các phần tử trong mảng:

* **Hàm `findPair(int nums[], int target, int n)`**:
  * Khởi tạo biến `found = 0` nhằm kiểm tra xem có tìm thấy ít nhất một cặp số thỏa mãn yêu cầu hay không.
  * Sử dụng hai vòng lặp lồng nhau:

    * Vòng lặp ngoài (`i` chạy từ `0` đến `n - 1`) chọn phần tử thứ nhất của cặp.
    * Vòng lặp trong (`j` chạy từ `i + 1` đến `n - 1`) chọn phần tử đứng sau phần tử thứ nhất để tạo thành một cặp, tránh lặp lại hoặc tự cộng với chính nó.

  * Kiểm tra điều kiện tổng: Nếu `nums[i] + nums[j] == target`, chương trình sẽ in ra: `Pair found (nums[i], nums[j])` và cập nhật `found = 1`.
  * Sau khi kết thúc vòng lặp, nếu biến `found` vẫn bằng `0`, chương trình sẽ in ra: `Pair not found.`.

* **Hàm `main()`**:
  * Nhận dữ liệu mảng số nguyên `nums` từ người dùng.
  * Nhận giá trị tổng cần tìm `target`.
  * Gọi hàm `findPair` để thực thi thuật toán và trả về kết quả.


## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Có cặp số thỏa mãn tổng cho trước
* **Đầu vào (Input):**
  * Mảng `nums`: `2, 4, 3, 5, 7, 8`
  * `target`: `9`
* **Đầu ra (Output):**
  Pair found (2, 7)
  Pair found (4, 5)

### Test Case 2: Có một cặp số duy nhất thỏa mãn
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, 3, 9`
  * `target`: 8
* **Đầu ra (Output):**
Pair found (3, 5)  

### Test Case 3: Không có cặp số nào thỏa mãn
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, 3, 4`
  * `target`: 10
* **Đầu ra (Output):**
Pair not found.





