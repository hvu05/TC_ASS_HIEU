import os
import random

def generate_numbers():
    """Tạo một mảng 17 số nguyên < 0 hoặc > 1000"""
    return [random.randint(-1000, -1) if random.random() < 0.5 else random.randint(1001, 2000) for _ in range(17)]

def create_files(directory="output", num_files=1000):
    """Tạo 1000 file .txt chứa 2 dòng mảng số nguyên"""
    if not os.path.exists(directory):
        os.makedirs(directory)
    
    for i in range(1, num_files + 1):
        file_path = os.path.join(directory, f"file_{i}.txt")
        with open(file_path, "w") as f:
            f.write(" ".join(map(str, generate_numbers())) + "\n")
            f.write(" ".join(map(str, generate_numbers())) + "\n")
    
    print(f"Đã tạo {num_files} file trong thư mục '{directory}'")

# Gọi hàm tạo file
create_files("SinhTestCase/task1/input")
