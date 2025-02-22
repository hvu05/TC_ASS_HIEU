#include "main.h"
#include "TASK1.cpp"
#include "TASK2.cpp"
#include "TASK3.cpp"
#include "TASK4.cpp"
#include "TASK5.cpp"

inline static const string green = "\033[32m";
inline static const string red = "\033[31m";
inline static const string cyan = "\033[36m";
inline static const string reset = "\033[0m"; // To reset to default color

// const int MAX_LINES = 5;
// const int MAX_LINE_LENGTH = 100;

// Task 1

bool compareFiles(const string p1, const string p2)
{
    ifstream f1(p1);
    ifstream f2(p2);
    // cout << p1 << endl << p2;
    if (!f1 || !f2)
    {
        cout << "Không thể mở file" << endl;
        return false;
    }
    // string t;
    // getline(f1, t);
    // cout << "t = " << t << endl;

    // getline(f2, t);
    // cout << "t = " << t << endl;

    string line1, line2;
    int lineNum = 1;
    while (getline(f1, line1) && getline(f2, line2))
    {
        // Xóa khoảng trắng cuối dòng để tránh lỗi không cần thiết
        line1.erase(line1.find_last_not_of(" \t\r\n") + 1);
        line2.erase(line2.find_last_not_of(" \t\r\n") + 1);
        // cout << line1 << " ---- " << line2;
        if (line1 != line2)
        {
            cout << "Khác nhau tại dòng " << lineNum << ":\n";
            cout << "File 1: " << line1 << "\n";
            cout << "File 2: " << line2 << "\n";
            f1.close();
            f2.close();
            return false;
        }
        lineNum++;
    }

    if (getline(f1, line1) || getline(f2, line2))
    {
        cout << "Một file có thêm dòng mà file kia không có." << endl;
        f1.close();
        f2.close();
        return false;
    }
    f1.close();
    f2.close();
    return true;
}

void xuatfile1(int LF1[], int LF2[])
{
    string count = "";
    for (int i = 1; i <= 1000; ++i)
    {
        string lf1;
        string lf2;
        ifstream file("task1/input/file_" + to_string(i) + ".txt");
        if (!file)
            cout << "File not found";
        else
        {
            getline(file, lf1);
            getline(file, lf2);

            stringstream ss1(lf1);
            int indexLF1 = 0;
            while (ss1 >> LF1[indexLF1++])
            {
                if (indexLF1 >= 17)
                    break;
            }

            stringstream ss2(lf2);
            int indexLF2 = 0;
            while (ss2 >> LF2[indexLF2++])
            {
                if (indexLF2 >= 17)
                    break;
            }
            // 2 mảng này đã có các phần tử, giờ gọi hàm và test
        }
        int out = gatherForces(LF1, LF2);
        string temp = to_string(out);
        // cout << "at = " << temp << endl;
        ofstream outFile("task1/output/output_" + to_string(i) + ".txt");
        outFile << temp;
        outFile.close();

        string file1 = "task1/output/output_" + to_string(i) + ".txt";
        string file2 = "task1/expect/expect_" + to_string(i) + ".txt";
        if (compareFiles(file1, file2) == true)
        {
            cout << green << "Test case " << i << " passed." << reset << endl;
        }
        else
        {
            cout << red << "Test case " << i << " failed." << reset << endl;
            count += " " + to_string(i) + " ";
        }
    }
    cout << "Failed test " << count;
}

void xuatfile2()
{
    string count = "";
    for (int i = 1; i <= 1000; ++i)
    {
        string lf1;
        ifstream file("task2/input/test_" + to_string(i) + ".txt");
        if (!file)
            cout << "File not found";
        else
        {
            getline(file, lf1);
        }
        string temp = determineRightTarget(lf1);

        // cout << "at = " << temp << endl;
        ofstream outFile("task2/output/output_" + to_string(i) + ".txt");
        outFile << temp;
        outFile.close();

        string file1 = "task2/output/output_" + to_string(i) + ".txt";
        string file2 = "task2/expect/expect_" + to_string(i) + ".txt";
        if (compareFiles(file1, file2) == true)
        {
            cout << green << "Test case " << i << " passed." << reset << endl;
        }
        else
        {
            cout << red << "Test case " << i << " failed." << reset << endl;
            count += " " + to_string(i) + " ";
        }
    }

    for (int i = 1001; i <= 1006; ++i)
    {
        string lf1;
        string s2, s3;
        ifstream file("task2/input/test_" + to_string(i) + ".txt");
        if (!file)
            cout << "File not found";
        else
        {
            getline(file, lf1);
            getline(file, s2);
            getline(file, s3);
        }
        string temp = decodeTarget(lf1, stoi(s2), stoi(s3));

        // cout << "at = " << temp << endl;
        ofstream outFile("task2/output/output_" + to_string(i) + ".txt");
        outFile << temp;
        outFile.close();

        string file1 = "task2/output/output_" + to_string(i) + ".txt";
        string file2 = "task2/expect/expect_" + to_string(i) + ".txt";
        if (compareFiles(file1, file2) == true)
        {
            cout << green << "Test case " << i << " passed." << reset << endl;
        }
        else
        {
            cout << red << "Test case " << i << " failed." << reset << endl;
            count += " " + to_string(i) + " ";
        }
    }

    cout << "Failed test " << count;
}

void xuatfile3()
{
    string count = "";
    int LF1, LF2, EXP1, EXP2, T1, T2, E;
    for (int i = 1; i <= 1000; ++i)
    {
        ifstream file("task3/input/test_" + to_string(i) + ".txt");
        if (!file)
            cout << "File not found";
        else
        {
            string line;
            // int LF1, LF2, EXP1, EXP2, T1, T2, E;

            // Đọc dòng 1 (LF1, LF2)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> LF1 >> LF2;
            }
            else
            {
                cerr << "Lỗi đọc LF1, LF2!" << endl;
                return;
            }

            // Đọc dòng 2 (EXP1, EXP2)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> EXP1 >> EXP2;
            }
            else
            {
                cerr << "Lỗi đọc EXP1, EXP2!" << endl;
                return;
            }

            // Đọc dòng 3 (T1, T2)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> T1 >> T2;
            }
            else
            {
                cerr << "Lỗi đọc T1, T2!" << endl;
                return;
            }

            // Đọc dòng 4 (E)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> E;
            }
            else
            {
                cerr << "Lỗi đọc E!" << endl;
                return;
            }
        }
        // cout << T1 << " " << T2 << endl;
        manageLogistics(LF1, LF2, EXP1, EXP2, T1, T2, E);
        // cout << "at = " << temp << endl;
        ofstream outFile("task3/output/output_" + to_string(i) + ".txt");
        outFile << T1 << " " << T2;
        outFile.close();

        string file1 = "task3/output/output_" + to_string(i) + ".txt";
        string file2 = "task3/expect/expect_" + to_string(i) + ".txt";
        if (compareFiles(file1, file2) == true)
        {
            cout << green << "Test case " << i << " passed." << reset << endl;
        }
        else
        {
            cout << red << "Test case " << i << " failed." << reset << endl;
            count += " " + to_string(i) + " ";
        }
    }
    cout << "Failed test " << count;
}


void xuatfile4()
{
    string count = "";
    int LF1, LF2, EXP1, EXP2, T1, T2, battle[10][10];
    for (int i = 1; i <= 1000; ++i)
    {
        ifstream file("task4/input/test_" + to_string(i) + ".txt");
        if (!file)
            cout << "File not found";
        else
        {
            string line;
            // int LF1, LF2, EXP1, EXP2, T1, T2, E;

            // Đọc dòng 1 (LF1, LF2)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> LF1 >> LF2;
            }
            else
            {
                cerr << "Lỗi đọc LF1, LF2!" << endl;
                return;
            }

            // Đọc dòng 2 (EXP1, EXP2)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> EXP1 >> EXP2;
            }
            else
            {
                cerr << "Lỗi đọc EXP1, EXP2!" << endl;
                return;
            }

            // Đọc dòng 3 (T1, T2)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> T1 >> T2;
            }
            else
            {
                cerr << "Lỗi đọc T1, T2!" << endl;
                return;
            }

            for (int i = 0; i < 10; ++i) {
                getline(file, line);  // Đọc từng dòng
                stringstream ss(line);
                for (int j = 0; j < 10; ++j) {
                    ss >> battle[i][j];  // Lưu vào mảng battle
                }
            }
        }
        // cout << T1 << " " << T2 << endl;
        int num = planAttack(LF1, LF2, EXP1, EXP2, T1, T2, battle);
        // cout << "at = " << temp << endl;
        ofstream outFile("task4/output/output_" + to_string(i) + ".txt");
        outFile << num;
        outFile.close();

        string file1 = "task4/output/output_" + to_string(i) + ".txt";
        string file2 = "task4/expect/expect_" + to_string(i) + ".txt";
        if (compareFiles(file1, file2) == true)
        {
            cout << green << "Test case " << i << " passed." << reset << endl;
        }
        else
        {
            cout << red << "Test case " << i << " failed." << reset << endl;
            count += " " + to_string(i) + " ";
        }
    }
    cout << "Failed test " << count;
}

void xuatfile5()
{
    string count = "";
    int ball, battle[5][5];
    for (int i = 1; i <= 1000; ++i)
    {
        ifstream file("task5/input/test_" + to_string(i) + ".txt");
        if (!file)
            cout << "File not found";
        else
        {
            string line;
            // int LF1, LF2, EXP1, EXP2, T1, T2, E;

            // Đọc dòng 1 (LF1, LF2)
            if (getline(file, line))
            {
                stringstream ss(line);
                ss >> ball;
            }
            else
            {
                cerr << "Lỗi đọc LF1, LF2!" << endl;
                return;
            }

            for (int i = 0; i < 5; ++i) {
                getline(file, line);  // Đọc từng dòng
                stringstream ss(line);
                for (int j = 0; j < 5; ++j) {
                    ss >> battle[i][j];  // Lưu vào mảng battle
                }
            }
        }
        int num = resupply(ball, battle);
        // cout << "at = " << temp << endl;
        ofstream outFile("task5/output/output_" + to_string(i) + ".txt");
        outFile << num;
        outFile.close();

        string file1 = "task5/output/output_" + to_string(i) + ".txt";
        string file2 = "task5/expect/expect_" + to_string(i) + ".txt";
        if (compareFiles(file1, file2) == true)
        {
            cout << green << "Test case " << i << " passed." << reset << endl;
        }
        else
        {
            cout << red << "Test case " << i << " failed." << reset << endl;
            count += " " + to_string(i) + " ";
        }
    }
    cout << "Failed test " << count;
}

int main()
{
    int LF1[17];
    int LF2[17];
    xuatfile1(LF1, LF2);
    // xuatfile2();
    // xuatfile3();
    // xuatfile4();
    // xuatfile5();
}
// build: g++ -o main after.cpp
// run: ./main