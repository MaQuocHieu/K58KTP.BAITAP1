# Ma Quốc Hiếu - K225480106089
# BÀI TẬP MÔN: An toàn và bảo mật thông tin
# BÀI TẬP 1:
## TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN Caesar
1. Caesar
2. Affine
3. Hoán vị
4. Vigenere
5. Playfair
## Với mỗi phương pháp, hãy tìm hiểu:
1. Tên gọi
2. Thuật toán mã hoá, thuật toán giải mã
3. Không gian khóa
4. Cách phá mã (mà không cần khoá)
5. Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript

# Bài làm

## 1. Mã Caesar (Caesar Cipher)
1. Tên gọi: Caesar Cipher
* Nguyên lý: Dịch chuyển các chữ cái trong bảng chữ cái đi một số vị trí nhất định.
2. Công thức: Thuật toán
  * Mã hóa: C = (P + k) mod 26
  * Giải mã: P = (C - k) mod 26
3. Không gian khóa: 26 khả năng (k = 0..25). (k = 0 cho bản rõ)
4. Cách phá mã (không cần khóa)
- Brute force thử 26 khả năng.
- Phân tích tần suất chữ cái (văn bản dài -> dịch sao cho chữ phổ biến nhất khớp 'E').
5. C++ (mã hoá + giải mã)
---

## 2. Mã Affine (Affine Cipher)
1. Tên gọi: Affine Cipher
* Nguyên lý: Kết hợp nhân và cộng trên số thứ tự của chữ cái.
2. Công thức: Thuật toán
  * Mã hóa: C = (aP + b) mod 26
  * Giải mã: P = a^-1 (C - b) mod 26
    (a phải nguyên tố cùng 26 để có nghịch đảo).
3. Không gian khóa:
    - a có 12 giá trị khả dụng (các số coprime với 26): {1,3,5,7,9,11,15,17,19,21,23,25}.
    - b có 26 giá trị (0..25).
=> tổng 12 * 26 = 312 khóa.
4. Cách phá mã (không cần khóa)
- Brute force thử 312 cặp (a,b).
- Phân tích tần suất chữ cái.
5. C++ (mã hoá + giải mã).

---

## 3. Mã Hoán Vị (Transposition Cipher)
1. Tên gọi: Columnar Transposition Cipher (Mã hoán vị theo cột)
2. Thuật toán
* Nguyên lý: Không thay đổi ký tự, chỉ đổi vị trí các ký tự theo một quy tắc.
*  Mã hóa:
 - Chuẩn hóa plaintext → in hoa, bỏ ký tự không phải A–Z (tùy implementation).
 - Ghi tuần tự theo hàng vào ma trận có cols = len(key). Nếu thiếu ô thì điền ký tự padding (ví dụ 'X').
 - Sắp xếp thứ tự cột theo thứ tự chữ cái của key (nếu trùng chữ thì theo vị trí xuất hiện). Đọc các cột theo thứ tự đó, nối thành ciphertext.
* Giải mã:
 - Biết cols = len(key), rows = ceil(len(cipher)/cols).
 - Biết thứ tự cột, chia ciphertext cho từng cột theo thứ tự sắp xếp, điền cột vào ma trận rồi đọc theo hàng để thu plaintext (loại bỏ padding nếu cần).
3. Không gian khóa:
* Nếu key là hoán vị độ dài n thì có n! khả năng. Nếu dùng từ có lặp ký tự, số khả năng giảm.
4. Cách phá mã (không cần khóa):
* Thử tất cả hoán vị cột (brute force) nếu n nhỏ.
* Dùng đánh giá "tiếng Anh" (n-gram score) để chọn kết quả hợp lý.
* Nếu biết độ dài cột hoặc có manh mối (ví dụ từ thường gặp), giảm không gian tìm kiếm.
5. Code C++ (encrypt/decrypt, chuẩn hóa chữ hoa A–Z, padding 'X'):

---

## 4. Mã Vigenere (Vigenere Cipher)

* Nguyên lý: Dùng một từ khóa lặp lại để dịch chuyển từng chữ cái của bản rõ.
1. Tên gọi:
* Mã Vigenère (Vigenere Cipher)
2. Thuật toán:
* Mã hóa: lặp lại khóa K, với mỗi vị trí i: C_i = (P_i + K_i) mod 26 (ký tự được số hóa A=0..Z=25).
* Giải mã: P_i = (C_i - K_i + 26) mod 26.
3. Không gian khóa:
* Nếu khóa có độ dài m thì không gian = 26^m. Thực tế khóa thường ngắn (từ, cụm từ).
4. Cách phá mã (không cần khóa):
* Kasiski examination: tìm khoảng cách giữa các đoạn lặp → ước lượng độ dài khóa.
* Friedman test (Index of Coincidence) để ước lượng độ dài khóa.
* Khi biết độ dài m, tách ciphertext thành m chuỗi (mỗi chuỗi là Caesar) → giải từng chuỗi bằng phân tích tần suất.
5. Code C++ (đơn giản, chuẩn hóa A–Z):

## 5. Mã Playfair (Playfair Cipher)

* Nguyên lý: Mã hóa theo cặp chữ cái (digraphs) bằng bảng 5x5 chứa khóa.
1. Tên gọi:
* Mã Playfair (Playfair Cipher)
2. Thuật toán:
* Tạo bảng 5×5 từ khóa: viết khóa (bỏ chữ trùng), thay J → I (quy ước), sau đó điền phần còn lại của bảng.
* Chuẩn hóa plaintext: in hoa, J → I, loại bỏ ký tự không phải chữ, tách thành cặp (digraph); nếu hai chữ trong cặp giống nhau chèn 'X' giữa; nếu thiếu chữ cuối cùng thêm 'X'.
* Mã hóa mỗi cặp (A,B):
* Nếu cùng hàng → thay mỗi chữ bằng chữ bên phải (vòng).
* Nếu cùng cột → thay bằng chữ bên dưới (vòng).
* Nếu tạo thành hình chữ nhật → thay bằng chữ cùng hàng với A ở cột B và cùng hàng với B ở cột A.
* Giải mã: thao tác ngược (trái / trên / rectangle ngược).
3. Không gian khóa:
* Lý thuyết: 25! (vì bảng 25 chữ) — rất lớn. Thực tế người dùng dùng từ khóa => không gian nhỏ hơn.
4. Cách phá mã (không cần khóa):
* Phân tích tần suất digraph.
* Brute-force từ khóa nhỏ (dictionary attack).
* Thuật toán tối ưu hóa (hill-climbing / simulated annealing) trên không gian ma trận để tối đa hóa score tiếng Anh.
5. Code C++ (Playfair, J->I, padding 'X'):


