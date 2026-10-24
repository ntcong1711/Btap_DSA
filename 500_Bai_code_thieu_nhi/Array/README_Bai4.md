# Bài toán: Find largest sub-array formed by consecutive integers

## 1. Mô tả giải thuật chi tiết

Chương trình trong file `Bai4.c` sử dụng phương pháp duyệt vét cạn kết hợp với kỹ thuật “xóa phần tử trùng lặp” trong mảng để thu được một mảng mới còn lại sau khi loại bỏ các phần tử bị lặp lại. Đây là cách tiếp cận đơn giản nhưng hiệu quả với các bài toán nhỏ và dữ liệu vừa phải.

* **Hàm `find_largest_subarray(int num[], int n)`**:
  * Khởi tạo biến `new_size = n` để theo dõi số lượng phần tử hiện tại của mảng sau mỗi lần xóa.
  * Duyệt qua từng phần tử `i` của mảng bằng vòng lặp ngoài:

    * Với mỗi `i`, xét các vị trí `j` đứng sau `i` bằng vòng lặp trong.
    * Nếu `num[i] == num[j]`, nghĩa là phần tử ở vị trí `j` trùng với phần tử ở vị trí `i`, thì chương trình sẽ thực hiện việc xóa phần tử `num[j]` khỏi mảng.

  * Quá trình xóa phần tử được thực hiện bằng cách:

    * Dịch chuyển các phần tử phía sau `j` lên một vị trí về trái bằng vòng lặp:
      `num[k] = num[k + 1];`
    * Giảm `new_size` đi 1 vì mảng đã bớt đi một phần tử.
    * Giảm `j` đi 1 để tiếp tục xét lại các phần tử mới được dịch chuyển vào vị trí `j`.

  * Sau khi không còn phần tử nào trùng lặp với các phần tử đã xét, chương trình sẽ in ra mảng kết quả theo dạng:
    `The largest subarray:{a,b,c,...}`

* **Hàm `main()`**:
  * Khai báo mảng `nums` cố định trong chương trình.
  * Tính số lượng phần tử `n` bằng cách: `sizeof(nums) / sizeof(nums[0])`.
  * Gọi hàm `find_largest_subarray(nums, n)` để xử lý và in ra kết quả.

### Cách hoạt động của thuật toán
Thuật toán này hoạt động theo nguyên tắc “xóa các phần tử trùng lặp” trong mảng. Với mỗi phần tử ở vị trí `i`, chương trình tìm kiếm các phần tử đứng sau nó có cùng giá trị. Nếu tìm thấy, nó sẽ xóa phần tử đó và dịch chuyền các phần tử phía sau lên để đảm bảo mảng vẫn liên tục.

Ví dụ:

- Mảng ban đầu: `{2, 0, 2, 1, 4, 3, 1, 0}`
- Tại `i = 0`, phần tử `2` gặp lại ở `j = 2` nên xóa phần tử đó.
- Sau khi dịch chuyển, mảng trở thành `{2, 0, 1, 4, 3, 1, 0}`.
- Tiếp tục xét các phần tử còn lại, nếu có trùng lặp thì xóa tiếp.
- Kết quả cuối cùng được in ra dưới dạng mảng còn lại sau khi loại bỏ các phần tử trùng lặp.

Độ phức tạp của thuật toán
- Thời gian: O(n³) trong trường hợp xấu nhất, vì mỗi lần xóa phần tử phải dịch chuyển các phần tử phía sau, và quá trình này xảy ra nhiều lần trong các vòng lặp lồng nhau.
- Bổ nhớ: O(1) vì không cần mảng phụ để lưu kết quả trung gian.

## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Mảng có nhiều phần tử trùng lặp
* **Đầu vào (Input):**
  * Mảng `nums`: `2, 0, 2, 1, 4, 3, 1, 0`

* **Đầu ra (Output):**
  ```text
  The largest subarray:{2,0,1,4,3,1}
  ```

  Giải thích: Trong mảng ban đầu, các phần tử `2` và `0` xuất hiện lại ở vị trí khác, nên chương trình sẽ xóa các phần tử trùng lặp và in ra mảng còn lại sau khi đã loại bỏ.

### Test Case 2: Mảng không có phần tử nào trùng lặp
* **Đầu vào (Input):**
  * Mảng `nums`: `1, 2, 3, 4, 5`

* **Đầu ra (Output):**
  ```text
  The largest subarray:{1,2,3,4,5}
  ```

  Giải thích: Không có cặp phần tử nào giống nhau, nên mảng sau khi xử lý giữ nguyên trạng thái ban đầu.



































































































































