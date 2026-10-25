# Bài toán: Tìm tích lớn nhất của 2 số trong mảng (Find maximum product of two integers in an array)

## 1. Mô tả giải thuật chi tiết

Chương trình sử dụng phương pháp duyệt vét cạn (Brute Force) để xét tất cả các cặp số có thể tạo thành trong mảng và tính tích của từng cặp. Sau đó, chương trình so sánh các tích đó với nhau để tìm ra tích lớn nhất.

* **Hàm `find_maximum_product(int num[], int n)`**:
  * Kiểm tra điều kiện đầu vào: nếu mảng có ít hơn 2 phần tử thì in ra thông báo: `The array must have at least 2 elements.` và kết thúc hàm.
  * Khởi tạo biến `maxProd = INT_MIN` để lưu giá trị tích lớn nhất tìm được. Giá trị này bắt đầu bằng số nhỏ nhất có thể của kiểu `int` để đảm bảo có thể so sánh với mọi tích.
  * Khởi tạo hai mảng `A[]` và `B[]` để lưu các cặp số có tích lớn nhất. Vì một số trường hợp có thể có nhiều cặp cho cùng một tích lớn nhất, nên chương trình lưu toàn bộ các cặp đó.
  * Duyệt qua tất cả các cặp `(i, j)` với `i < j`:

    * Vòng lặp ngoài `i` chạy từ `0` đến `n - 1`.
    * Vòng lặp trong `j` chạy từ `i + 1` đến `n - 1`.
    * Tính `prod = num[i] * num[j]`.

  * So sánh tích vừa tính với `maxProd`:

    * Nếu `prod == maxProd`: nghĩa là cặp đang xét có tích bằng với tích lớn nhất hiện tại, chương trình lưu thêm cặp này vào tập hợp kết quả.
    * Nếu `prod > maxProd`: nghĩa là tìm thấy một tích mới lớn hơn tích lớn nhất trước đó, chương trình cập nhật `maxProd` và reset lưu trữ để chỉ giữ các cặp có tích mới lớn nhất.

  * Sau khi duyệt tất cả các cặp, hàm in ra các cặp số có tích lớn nhất theo định dạng:
    ```text
    Pais have maximum product: (a, b) and (c, d)
    ```

* **Hàm `main()`**:
  * Khai báo mảng `nums` cố định trong chương trình.
  * Tính số lượng phần tử `n` bằng biểu thức: `sizeof(nums) / sizeof(nums[0])`.
  * Gọi hàm `find_maximum_product(nums, n)` để tìm và in ra các cặp có tích lớn nhất.

### Cách hoạt động của thuật toán

Thuật toán này xét tất cả các cặp số trong mảng, không bỏ sót trường hợp nào. Với mỗi cặp `(i, j)`, chương trình tính tích `num[i] * num[j]` và so sánh với tích lớn nhất hiện tại. Nếu tích mới lớn hơn, nó sẽ thay thế kết quả cũ; nếu bằng với tích lớn nhất hiện tại, nó sẽ được lưu thêm vào danh sách các cặp đáp án.

Độ phức tạp của thuật toán:

- Thời gian: O(n²) vì phải xét tất cả các cặp của mảng.
- Bổ nhớ: O(n²) vì chương trình lưu trữ các cặp có tích lớn nhất trong hai mảng `A[]` và `B[]`.

## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Có nhiều cặp có cùng tích lớn nhất
* **Đầu vào (Input):**
  * Mảng `nums`: `-10, -3, 5, 6, -2`
* **Đầu ra (Output):**
  ```text
  Pais have maximum product: (-10, -3) and (5, 6)
  ```

  Giải thích: Các tích của các cặp là:
  * `(-10) * (-3) = 30`
  * `5 * 6 = 30`
  * Các cặp còn lại đều nhỏ hơn `30`

  Vậy tích lớn nhất là `30`, và có 2 cặp đạt giá trị này.

### Test Case 2: Có một cặp duy nhất cho tích lớn nhất
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, 3, 4, 5`
* **Đầu ra (Output):**
  ```text
  Pais have maximum product: (4, 5)
  ```

  Giải thích: Tích lớn nhất có thể tạo ra là `4 * 5 = 20`.

### Test Case 3: Mảng có số âm và số dương
* **Đầu vào (Input):**
  * Mảng `nums`: `-8, 2, 5, -3, 10`
* **Đầu ra (Output):**
  ```text
  Pais have maximum product: (-8, -3)
  ```

  Giải thích: Cặp `(-8, -3)` cho tích `24`, lớn hơn các tích khác như `2 * 10 = 20`, `5 * 10 = 50`, nhưng `(-8) * (-3) = 24` không phải lớn nhất. Cặp `5 * 10 = 50` là lớn hơn, nên kết quả thực tế là:
  ```text
  Pais have maximum product: (5, 10)
  ```

### Test Case 4: Mảng chỉ có 1 phần tử
* **Đầu vào (Input):**
  * Mảng `nums`: `7`
* **Đầu ra (Output):**
  ```text
  The array must have at least 2 elements.
  ```

  Giải thích: Vì bài toán yêu cầu tìm tích của 2 số trong mảng nên mảng phải có ít nhất 2 phần tử.

### Test Case 5: Có nhiều cặp cùng tích lớn nhất với số âm
* **Đầu vào (Input):**
  * Mảng `nums`: `-2, -5, 3, 4, -1`
* **Đầu ra (Output):**
  ```text
  Pais have maximum product: (-2, -5) and (3, 4)
  ```

  Giải thích:
  * `(-2) * (-5) = 10`
  * `3 * 4 = 12`
  * `(-1) * (-5) = 5`
  * `(-2) * 4 = -8`

  Trong trường hợp này, tích lớn nhất thực tế là `12` từ cặp `(3, 4)`. Nếu muốn minh họa trường hợp nhiều cặp lớn nhất, ta có thể dùng mảng khác như:
  * `nums = {-3, -2, 4, 5}`
  * tích lớn nhất là `12` từ `(-3, -4)` không có; vì vậy không phù hợp.

  Do đó, với dữ liệu trên, đáp án đúng là:
  ```text
  Pais have maximum product: (3, 4)
  ```

### Test Case 6: Mảng có số 0
* **Đầu vào (Input):**
  * Mảng `nums`: `0, 3, 8, -2, 5`
* **Đầu ra (Output):**
  ```text
  Pais have maximum product: (3, 8)
  ```

  Giải thích: Tích lớn nhất là `3 * 8 = 24`.

### Kết luận

Thuật toán duyệt hết tất cả các cặp là cách tiếp cận đơn giản, dễ hiểu và phù hợp với các bài tập Cơ bản về mảng, đặc biệt khi tập dữ liệu không quá lớn. Nó cho phép kiểm tra chính xác từng cặp số và tìm ra kết quả tối ưu theo yêu cầu của bài toán.
