import os
import random

def generate_test_files(num_files=1000, output_dir="test_cases"):
    os.makedirs(output_dir, exist_ok=True)
    
    for i in range(1, num_files + 1):
        file_path = os.path.join(output_dir, f"test_{i}.txt")
        
        with open(file_path, "w") as f:
            # Hàng 1: Hai số nguyên từ -20 đến 1059
            f.write(f"{random.randint(-20, 1059)} {random.randint(-20, 1059)}\n")
            
            # Hàng 2: Hai số nguyên từ -30 đến 700
            f.write(f"{random.randint(-30, 700)} {random.randint(-30, 700)}\n")
            
            # Hàng 3: Hai số nguyên từ -50 đến 3500
            f.write(f"{random.randint(-50, 3500)} {random.randint(-50, 3500)}\n")
            
            # Hàng 4: Một số nguyên từ 0 đến 99
            f.write(f"{random.randint(0, 99)}\n")
    
    print(f"{num_files} test files have been generated in '{output_dir}'")

# Gọi hàm để tạo file
test_folder = "SinhTestCase/task3/input"
generate_test_files(1000, test_folder)
