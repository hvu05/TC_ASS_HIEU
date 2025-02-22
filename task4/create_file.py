import os
import random

def generate_files(num_files=1000, output_folder="task_input"):
    os.makedirs(output_folder, exist_ok=True)  # Tạo thư mục nếu chưa có
    
    for i in range(1, num_files + 1):
        file_path = os.path.join(output_folder, f"test_{i}.txt")
        with open(file_path, "w") as f:
            # Dòng 1: Hai số nguyên từ -10 đến 1100
            f.write(f"{random.randint(-10, 1100)} {random.randint(-10, 1100)}\n")
            
            # Dòng 2: Hai số nguyên từ -10 đến 700
            f.write(f"{random.randint(-10, 700)} {random.randint(-10, 700)}\n")
            
            # Dòng 3: Hai số nguyên từ -20 đến 3100
            f.write(f"{random.randint(-20, 3100)} {random.randint(-20, 3100)}\n")
            
            # Dòng 4-13: Ma trận 10x10 với số nguyên từ -10 đến 210
            for _ in range(10):
                row = " ".join(str(random.randint(-10, 210)) for _ in range(10))
                f.write(row + "\n")
    
    print(f"Đã tạo {num_files} file trong thư mục '{output_folder}'")

# Gọi hàm để tạo file
test_folder = "SinhTestCase/task4/input"
generate_files(1000, test_folder)
