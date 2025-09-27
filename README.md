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
5. C++ (mã hoá + giải mã

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/aa61c8bd-c32f-4460-91ba-c90d78b38ac7" />


 - html+css+javascript
   
   <img width="1724" height="823" alt="image" src="https://github.com/user-attachments/assets/ed49ac0f-0ba8-4876-bf69-214da102312a" />

  <img width="1474" height="722" alt="image" src="https://github.com/user-attachments/assets/b17a86d1-ecab-474f-9f09-48ca590efe3b" />

  <img width="1619" height="851" alt="image" src="https://github.com/user-attachments/assets/7226c7c7-015f-4ec4-8850-778eafcf6111" />
   
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

<img width="1918" height="1078" alt="image" src="https://github.com/user-attachments/assets/f20ded93-03ab-442d-b32e-4657844b5237" />

- html+css+javascript
  
<img width="1829" height="956" alt="image" src="https://github.com/user-attachments/assets/8d54d67b-ad2d-4ae9-9ae3-47ccab293a5b" />

<img width="1355" height="719" alt="image" src="https://github.com/user-attachments/assets/5ae67d7f-9d8c-46b0-93d2-fab3ee32ef8c" />

<img width="1494" height="769" alt="image" src="https://github.com/user-attachments/assets/4d50fb1e-e431-4a61-a76b-642be232d73c" />



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

<img width="1903" height="1073" alt="image" src="https://github.com/user-attachments/assets/3dd38ba0-a41d-4be5-be84-b946ae48ce5e" />

- html+css+javascript
  
  <img width="1772" height="884" alt="image" src="https://github.com/user-attachments/assets/d8f14861-907f-49d6-b145-fc500c9e0ce1" />

  <img width="1407" height="705" alt="image" src="https://github.com/user-attachments/assets/a474320e-c4d0-4863-bd52-611d50c02290" />
  
  <img width="1347" height="670" alt="image" src="https://github.com/user-attachments/assets/84103629-5167-4678-a521-73f6e245c837" />

---

## 4. Mã Vigenere (Vigenere Cipher)

* Nguyên lý: Dùng một từ khóa lặp lại để dịch chuyển từng chữ cái của bản rõ.
1. Tên gọi:
* Mã Vigenere (Vigenere Cipher)
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

  <img width="1915" height="1071" alt="image" src="https://github.com/user-attachments/assets/f270d2b5-dcdb-4fc1-abde-999c7723e01d" />

  - html+css+javascript

  <img width="1662" height="825" alt="image" src="https://github.com/user-attachments/assets/8ba8e1e1-0727-46ad-9d87-114026ce7cb6" />
  

  <img width="606" height="362" alt="image" src="https://github.com/user-attachments/assets/feb69f6c-90eb-4a1e-a694-148fa1205a28" />
  

   <img width="821" height="454" alt="image" src="https://github.com/user-attachments/assets/86fd7c28-1f1f-4371-87ac-12606b473ce6" />

  
---
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

  <img width="1914" height="1079" alt="image" src="https://github.com/user-attachments/assets/998e1b2a-2e5c-4f6a-8c05-bd0a2773c080" />

  - html+css+javascript

  <img width="1616" height="897" alt="image" src="https://github.com/user-attachments/assets/c36a643d-fc47-4e39-b660-8bfc49435ff0" />

  <img width="599" height="336" alt="image" src="https://github.com/user-attachments/assets/df2d8527-b41a-446e-a325-3ff9389b60fb" />

  <img width="543" height="430" alt="image" src="https://github.com/user-attachments/assets/699c3caf-db9b-4ed3-bc10-60be43663524" />



  
---
