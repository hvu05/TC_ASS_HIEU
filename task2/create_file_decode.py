import random
import os
import string

targets = {
    3: "Buon Ma Thuot",
    4: "Duc Lap",
    5: "Dak Lak",
    6: "National Route 21",
    7: "National Route 14"
}

def generate_message():
    case_type = random.choice([1, 2, 3, 4])  # Chọn ngẫu nhiên 1 trong 4 trường hợp
    numbers = []
    text = ""
    
    if case_type == 1:
        num = random.randint(3, 7)
        text = f"Test{num}Message"
        numbers = [num]
    elif case_type == 2:
        num1, num2 = random.randint(0, 9), random.randint(0, 9)
        text = f"Msg{num1}Test{num2}"
        numbers = [num1, num2]
    elif case_type == 3:
        num1, num2, num3 = random.randint(0, 9), random.randint(0, 9), random.randint(0, 9)
        text = f"T{num1}e{num2}s{num3}tMessage"
        numbers = [num1, num2, num3]
    else:
        text = ''.join(random.choices(string.ascii_letters + " ", k=random.randint(5, 12)))
        numbers = []
    
    return text, numbers

def generate_exp():
    return random.randint(-1000, 4000)

def save_test_files(num_files=1000, folder="test_cases"):
    if not os.path.exists(folder):
        os.makedirs(folder)
    
    for i in range(1001, num_files + 1):
        message, numbers = generate_message()
        exp1, exp2 = generate_exp(), generate_exp()
        
        file_path = os.path.join(folder, f"test_{i}.txt")
        with open(file_path, "w") as f:
            f.write(message + "\n")
            f.write(str(exp1) + "\n")
            f.write(str(exp2) + "\n")
    
    print(f"Generated {num_files} test files in '{folder}' folder.")

# Chạy hàm tạo file
test_folder = "SinhTestCase/task2/input"
save_test_files(100, test_folder)
