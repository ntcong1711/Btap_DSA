# Bài Tập: Tháp Hà Nội

## 1. Yêu Cầu Bài Toán

Chương trình giải bài toán Tháp Hà Nội classic bằng ngôn ngữ C. 
Mục tiêu: Di chuyển toàn bộ n đĩa từ cọc nguồn A sang cọc đích C thông qua cọc trung gian B sao cho:
1. Mỗi lần chỉ di chuyển đúng 1 đĩa.
2. Không được đặt đĩa lớn hơn lên trên đĩa nhỏ hơn tại bất kỳ thời điểm nào.
3. Sử dụng cọc B làm cọc hỗ trợ trung gian trong quá trình chuyển.


## 2. Diễn Giải Giải Thuật (Đệ Quy)

Để chuyển n đĩa từ cọc A sang cọc C (dùng B làm trung gian):
1. Trường hợp cơ sở (Base Case):
   - Khi n = 1: Di chuyển trực tiếp đĩa 1 từ cọc nguồn A sang cọc đích C.
2. Bước đệ quy (Recursive Step):
   - Bước 1: Gọi đệ quy chuyển n - 1 đĩa trên cùng từ cọc A sang cọc B (sử dụng cọc C làm trung gian).
   - Bước 2: In thông báo di chuyển đĩa thứ n từ cọc A sang cọc C.
   - Bước 3: Gọi đệ quy chuyển n - 1 đĩa từ cọc B sang cọc C (sử dụng cọc A làm trung gian).

## 3. Test Cases 

## Test Case 1: n = 1 đĩa
Input:
Nhap so luong dia: 1
Output:
Chuyen dia 1 tu A sang C 

## Test Case 2: n = 2 đĩa
Input:
Nhap so luong dia: 2
Output:
Chuyen dia 1 tu A sang B 
Chuyen dia 2 tu A sang C 
Chuyen dia 1 tu B sang C 

## Test Case 3: n = 3 đĩa
Input:
Nhap so luong dia: 3
Output:
Chuyen dia 1 tu A sang C\n
Chuyen dia 2 tu A sang B 
Chuyen dia 1 tu C sang B 
Chuyen dia 3 tu A sang C 
Chuyen dia 1 tu B sang A 
Chuyen dia 2 tu B sang C 
Chuyen dia 1 tu A sang C 
