import os
import random

def generate_test_files(num_files=1000, output_dir="task_resupply/input"):
    os.makedirs(output_dir, exist_ok=True)  # Tạo thư mục nếu chưa có

    for i in range(1, num_files + 1):
        filename = os.path.join(output_dir, f"test_{i}.txt")

        shortfall = random.randint(10, 500)  # Giá trị cần bổ sung
        matrix = [[random.randint(1, 200) for _ in range(5)] for _ in range(5)]  # Ma trận 5x5

        with open(filename, "w") as f:
            f.write(f"{shortfall}\n")  # Dòng 1: shortfall
            for row in matrix:
                f.write(" ".join(map(str, row)) + "\n")  # Dòng 2-6: Ma trận

    print(f"✅ Đã tạo {num_files} file test trong {output_dir}")

# Gọi hàm tạo file test
test_folder = "SinhTestCase/task5/input"
generate_test_files(1000, test_folder)
