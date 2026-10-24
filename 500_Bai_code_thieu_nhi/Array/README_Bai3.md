# Bài toán: Tìm các phần tử trùng lặp trong mảng (Find duplicate elements in array)

## 1. Mô tả giải thuật chi tiết

Bài toán yêu cầu tìm và in ra các phần tử bị lặp lại trong mảng, đồng thời loại bỏ các phần tử trùng lặp đã phát hiện để tránh in lại nhiều lần. Chương trình sử dụng phương pháp duyệt vét cạn (Brute Force) để so sánh từng cặp phần tử trong mảng.

* **Hàm `find_duplicate_element(int num[], int n)`**:
  * Khởi tạo biến `new_size = n` để theo dõi kích thước hiện tại của mảng sau khi đã xóa các phần tử trùng lặp.
  * Khởi tạo mảng `result[n]` để lưu các phần tử trùng lặp đã tìm được.
  * Khởi tạo biến `a = 0` để đếm số phần tử trong mảng `result`.
  * Duyệt qua từng phần tử `i` trong mảng: `for (int i = 0; i < new_size; i++)`.
  * Với mỗi `i`, duyệt tiếp từ `j = i + 1` đến `new_size - 1` để so sánh `num[i]` với các phần tử phía sau.
  * Khi gặp `num[i] == num[j]`, chương trình hiểu rằng phần tử `num[i]` là một giá trị trùng lặp.
  * Sau đó thực hiện xóa phần tử `num[j]` khỏi mảng bằng cách dịch chuyển tất cả các phần tử phía sau `j` lên 1 vị trí:

    ```c
    for (int k = j; k < new_size - 1; k++) {
        num[k] = num[k + 1];
    }
    ```

  * Giảm `new_size--` và `j--` để tiếp tục xét các phần tử mới được dịch lên.
  * Sau khi xóa phần tử trùng lặp, chương trình kiểm tra xem giá trị `num[i]` đã xuất hiện trong `result` chưa:

    ```c
    int is_exist = 0;
    for (int n = 0; n < a; n++) {
        if (result[n] == num[i]) {
            is_exist = 1;
            break;
        }
    }
    ```

  * Nếu giá trị chưa tồn tại trong `result`, chương trình lưu nó vào `result[a]` và tăng `a` lên 1.
  * Khi kết thúc vòng lặp, chương trình in ra danh sách các phần tử trùng lặp theo dạng:

    ```c
    printf("These duplicate element in the array:");
    printf("{");
    for (int i = 0; i < a; i++) {
        printf("%d", result[i]);
        if (i < a - 1) {
            printf(",");
        }
    }
    printf("}");
    ```

* **Hàm `main()`**:
  * Khai báo mảng `nums` cố định trong chương trình.
  * Tính số lượng phần tử `n` của mảng bằng `sizeof(nums) / sizeof(nums[0])`.
  * Gọi hàm `find_duplicate_element(nums, n)` để tìm các phần tử trùng lặp.

### Cách hoạt động của thuật toán

Thuật toán này sẽ xét tất cả các cặp phần tử có thể có trong mảng để tìm các giá trị trùng lặp:

- Với `i = 0`, chương trình so sánh phần tử đầu tiên với tất cả các phần tử còn lại.
- Nếu phần tử ở vị trí `j` trùng với `num[i]`, chương trình sẽ xóa `num[j]` khỏi mảng.
- Sau đó, tiến hành kiểm tra lại để tránh in trùng một giá trị nhiều lần.
- Quá trình này lặp lại đến khi tất cả các cặp phần tử đã được xét.

Độ phức tạp của thuật toán này là:

- Thời gian: O(n³) trong trường hợp xấu nhất, vì việc duyệt cặp phần tử lồng nhau kết hợp với việc dịch chuyển các phần tử trong mảng khi phát hiện trùng lặp.
- Bổ nhớ: O(n) do phải lưu các phần tử trùng lặp vào mảng `result`.

## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Có nhiều phần tử bị trùng lặp
* **Đầu vào (Input):**
  * Mảng `nums`: `3, 4, -7, 3, 1, 3, 1, -4, -2, -2`
* **Đầu ra (Output):**
  ```text
  These duplicate element in the array:{3,1,-2}
  ```

  Giải thích: Trong mảng trên, các giá trị xuất hiện nhiều hơn 1 lần là:
  * `3` xuất hiện 3 lần
  * `1` xuất hiện 2 lần
  * `-2` xuất hiện 2 lần

  Vì vậy, chương trình sẽ in ra các giá trị trùng lặp theo thứ tự tìm thấy: `{3,1,-2}`.

### Test Case 2: Chỉ có một giá trị duy nhất bị lặp lại
* **Đầu vào (Input):**
  * Mảng `nums`: `5, 8, 2, 5, 9, 1`
* **Đầu ra (Output):**
  ```text
  These duplicate element in the array:{5}
  ```

  Giải thích: Giá trị `5` xuất hiện 2 lần, nên chương trình chỉ in ra `5` một lần trong danh sách trùng lặp.

### Test Case 3: Mảng không có phần tử nào trùng lặp
* **Đầu vào (Input):**
  * Mảng `nums`: `2, 7, 4, 9, 6`
* **Đầu ra (Output):**
  ```text
  These duplicate element in the array:{}
  ```

  Giải thích: Không có giá trị nào xuất hiện hơn 1 lần trong mảng nên kết quả in ra là mảng rỗng `{}`.

