# Bài toán: Gộp 2 mảng đã sắp xếp (Merge Two Sorted Arrays)

## 1. Mô tả giải thuật chi tiết

Bài toán này yêu cầu hợp nhất hai mảng đã được sắp xếp theo thứ tự tăng dần thành một mảng đã sắp xếp. Trong chương trình `Bai8.c`, ta sử dụng phương pháp merge tương tự thuật toán Merge Sort.

### Ý tưởng của thuật toán

- Giả sử có hai mảng `X[]` và `Y[]` với số phần tử lần lượt là `m` và `n`.
- Ta tạo thêm một mảng phụ `Z` có kích thước `m + n` để lưu kết quả đã sắp xếp.
- Dùng ba con trỏ:
  - `i` để duyệt mảng `X`
  - `j` để duyệt mảng `Y`
  - `k` để duyệt mảng `Z`
- Mỗi bước, so sánh `X[i]` và `Y[j]`:
  - Nếu `X[i] <= Y[j]`, đưa `X[i]` vào `Z[k]` và tăng `i`, `k`.
  - Ngược lại, đưa `Y[j]` vào `Z[k]` và tăng `j`, `k`.
- Sau khi một trong hai mảng đã hết phần tử, ta copy phần còn lại của mảng kia vào `Z`.
- Cuối cùng, chương trình in ra kết quả theo hai nhóm:
  - `X[] = { ... }` là các phần tử đầu tiên của `Z` (số lượng `m` phần tử)
  - `Y[] = { ... }` là các phần tử còn lại của `Z` (từ vị trí `m` đến hết)

### Hàm `merge_sort_arrays(int X[], int Y[], int m, int n)`

Hàm này thực hiện các bước sau:

1. Tính `length = m + n`.
2. Khởi tạo mảng `Z[length]`.
3. Dùng vòng lặp `while (i < m && j < n)` để so sánh và chọn phần tử nhỏ hơn để thêm vào `Z`.
4. Dùng hai vòng lặp tiếp theo để copy phần tử còn lại của `X` hoặc `Y` vào `Z` nếu có.
5. In ra kết quả mảng `X[]` và `Y[]` sau khi đã hợp nhất.

### Cách hoạt động của thuật toán

Ví dụ với:
- `X = {1, 4, 7, 8, 10}`
- `Y = {2, 3, 9}`

Ta tiến hành so sánh từng cặp phần tử:

- `1` và `2` => chọn `1`
- `4` và `2` => chọn `2`
- `4` và `3` => chọn `3`
- `4` và `9` => chọn `4`
- `7` và `9` => chọn `7`
- `8` và `9` => chọn `8`
- `9` => chọn `9`
- `10` => chọn `10`

Mảng hợp nhất cuối cùng là:

`Z = {1, 2, 3, 4, 7, 8, 9, 10}`

Sau đó chương trình chia `Z` thành hai phần để hiển thị:

- `X[] = { 1, 2, 3, 4, 7 }`
- `Y[] = { 8, 9, 10 }`

### Độ phức tạp

- Thời gian: O(m + n)
  - Vì mỗi phần tử trong `X` và `Y` chỉ được xét tối đa một lần.
- Bổ nhớ: O(m + n)
  - Vì ta tạo thêm một mảng phụ `Z` để lưu kết quả.

## 2. Mô tả dữ liệu kiểm thử (Test Cases)

### Test Case 1: Hợp nhất hai mảng đã sắp xếp

* **Đầu vào (Input):**
  * `X[] = {1, 4, 7, 8, 10}`
  * `Y[] = {2, 3, 9}`

* **Đầu ra (Output):**
  ```text
  X[] = { 1, 2, 3, 4, 7 }
  Y[] = { 8, 9, 10 }
  ```

* **Giải thích:**
  - Hai mảng đều đã sắp xếp tăng dần.
  - Sau khi ghép và sắp xếp lại, mảng kết quả là `{1, 2, 3, 4, 7, 8, 9, 10}`.
  - Chương trình chia kết quả thành hai phần theo `m = 5` phần tử đầu và phần còn lại.

### Test Case 2: Một mảng rỗng

* **Đầu vào (Input):**
  * `X[] = {}`
  * `Y[] = {1, 2, 3}`

* **Đầu ra (Output):**
  ```text
  X[] = { 1, 2, 3 }
  Y[] = { }
  ```

* **Giải thích:**
  - Nếu `X` rỗng thì ta chỉ cần copy toàn bộ phần tử của `Y` sang `Z`.
  - Chương trình vẫn thực hiện đúng và in ra kết quả hợp nhất.

### Test Case 3: Mảng có phần tử trùng nhau

* **Đầu vào (Input):**
  * `X[] = {1, 2, 4, 7}`
  * `Y[] = {2, 3, 4, 8}`

* **Đầu ra (Output):**
  ```text
  X[] = { 1, 2, 2, 3 }
  Y[] = { 4, 4, 7, 8 }
  ```

* **Giải thích:**
  - Khi so sánh, các phần tử trùng nhau được giữ lại theo thứ tự từ `X` và `Y`.
  - Thuật toán merge vẫn hoạt động đúng với các giá trị lặp lại.
