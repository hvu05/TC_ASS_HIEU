import os
import random
import string
import re

def generate_random_string():
    """Tạo chuỗi chứa ký tự và số theo các trường hợp mô tả."""
    cases = [
        lambda: f"Kon{random.randint(3, 7)} Tum",  # Trường hợp 1: đúng 1 số trong [3,7]
        lambda: f"Ple{random.randint(0, 9)}i{random.randint(0, 9)}ku",  # Trường hợp 2: đúng 2 số
        lambda: f"Nat{random.randint(0, 9)}Ple{random.randint(0, 9)}Ku{random.randint(0, 9)}",  # Trường hợp 3: đúng 3 số
        lambda: ''.join(random.choices(string.ascii_letters, k=10)),  # Không có số
        lambda: 'Buon1Ma3Thuot5-8'  # Nhiều hơn 3 số
    ]
    return random.choice(cases)()

def create_test_files(folder="test_files", num_files=1000):
    """Tạo 1000 file test với 3 dòng theo yêu cầu."""
    os.makedirs(folder, exist_ok=True)
    
    for i in range(1, num_files + 1):
        filename = os.path.join(folder, f"test_{i}.txt")
        with open(filename, "w") as f:
            f.write(generate_random_string() + "\n")  # Dòng 1: message
            # f.write(str(random.randint(-1000, 4000)) + "\n")  # Dòng 2: số nguyên
            # f.write(str(random.randint(-1000, 4000)) + "\n")  # Dòng 3: số nguyên

    print(f"✅ Đã tạo {num_files} file test trong thư mục '{folder}'")
# Gọi hàm để tạo file
test_folder = "SinhTestCase/task2/input"
create_test_files(test_folder)
