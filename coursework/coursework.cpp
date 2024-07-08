#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <io.h>
#include <fcntl.h>

using namespace std;

void cleaningArr(vector<vector <int>>& m_) {
    auto begin = m_.cbegin();
    auto end = m_.cend();
    m_.erase(begin, end);
}

void fillEmptyArr(vector<vector <int>>& m) {
    m.push_back(vector <int>(1));
    m[0][0] = 0;
}

void checkingEmptiness(vector<vector <int>>& a_, vector<vector <int>>& b_, vector<vector <int>>& c_) {
    if (a_.empty()) {
        fillEmptyArr(a_);
    }
    if (b_.empty()) {
        fillEmptyArr(b_);
    }
    if (c_.empty()) {
        fillEmptyArr(c_);
    }
}

void fileInput(vector<vector <int>>& a, vector<vector <int>>& b, vector<vector <int>>& c) {
    int size_a, size_b, size_c;
    wstring filePath;
    char s;
    wcout << "Specify absolute path of file:" << endl;
    wcin >> filePath;
    ifstream fIn(filePath);
    while (true) {
        if (fIn.is_open()) {
            break;
        }
        else wcout << "File cannot be opened using this path." << endl;
        wcout << "Specify new absolute path of file:" << endl;
        wcin >> filePath;
        ifstream fIn(filePath);
    }
    wcout << "Start reading." << endl;
    while (true) {
        fIn >> s;
        if (s == 'A') {
            cleaningArr(a);
            fIn >> size_a;
            for (int i = 0; i < size_a; i++) {
                a.push_back(vector <int>(size_a));
                for (int l = 0; l < size_a; l++) fIn >> a[i][l];
            }
        }
        else if (s == 'B') {
            cleaningArr(b);
            fIn >> size_b;
            for (int i = 0; i < size_b; i++) {
                b.push_back(vector <int>(size_b));
                for (int l = 0; l < size_b; l++) fIn >> b[i][l];
            }
        }
        else if (s == 'C') {
            cleaningArr(c);
            fIn >> size_c;
            for (int i = 0; i < size_c; i++) {
                c.push_back(vector <int>(size_c));
                for (int l = 0; l < size_c; l++) fIn >> c[i][l];
            }
        }
        else if (s == '0') {
            wcout << "Reading is over." << endl;
            break;
        }
    }
    fIn.close();
    checkingEmptiness(a, b, c);
}

void fileOutput(vector<vector <int>>& a, vector<vector <int>>& b, vector<vector <int>>& c) {
    checkingEmptiness(a, b, c);
    wstring filePath;
    wcout << "Specify absolute path of file:" << endl;
    wcin >> filePath;
    ofstream fOut(filePath);
    while (true) {
        if (fOut.is_open()) {
            break;
        }
        else wcout << "File cannot be opened using this path." << endl;
        wcout << "Specify new absolute path of file:" << endl;
        wcin >> filePath;
        ofstream fOut(filePath);
    }
    wcout << "Start writing." << endl;
    fOut << "A" << endl;
    fOut << a.size() << endl;
    for (int i = 0; i < a.size(); i++) {
        for (int l = 0; l < a[i].size(); l++) fOut << a[i][l] << " ";
        fOut << endl;
    }
    fOut << "B" << endl;
    fOut << b.size() << endl;
    for (int i = 0; i < b.size(); i++) {
        for (int l = 0; l < b[i].size(); l++) fOut << b[i][l] << " ";
        fOut << endl;
    }
    fOut << "C" << endl;
    fOut << c.size() << endl;
    for (int i = 0; i < c.size(); i++) {
        for (int l = 0; l < c[i].size(); l++) fOut << c[i][l] << " ";
        fOut << endl;
    }
    fOut << 0 << endl;
    fOut.close();
    wcout << "Writing is over." << endl;
}

void fillMatrix(vector<vector <int>>& m_) {
    int size_m;
    cleaningArr(m_);
    wcout << "\nSpecify size of matrix: ";
    wcin >> size_m;
    wcout << "\nSpecify nums of matrix: ";
    for (int i = 0; i < size_m; i++) {
        m_.push_back(vector <int>(size_m));
        for (int l = 0; l < size_m; l++) wcin >> m_[i][l];
    }
}

void consoleInput(vector<vector <int>>& a, vector<vector <int>>& b, vector<vector <int>>& c) {
    int choice_;
    while (true) {
        system("cls");
        wcout <<
            "Choose action:\n"
            "0. Finish filling\n"
            "1. Fill matrix A\n"
            "2. Fill matrix B\n"
            "3. Fill matrix C\n";
        wcout << "\nType a number to continue: ";
        wcin >> choice_;
        if (choice_ == 0) {
            break;
        }
        if (choice_ == 1) {
            fillMatrix(a);
        }
        else if (choice_ == 2) {
            fillMatrix(b);
        }
        else if (choice_ == 3) {
            fillMatrix(c);
        }
        else wcout << "Action with number " << choice_ << " does not exist.\n" << endl;
        system("pause");
    }
    checkingEmptiness(a, b, c);
}

void consoleOutput(vector<vector <int>>& a, vector<vector <int>>& b, vector<vector <int>>& c) {
    checkingEmptiness(a, b, c);
    wcout << "Matrix A:" << endl;
    for (int i = 0; i < a.size(); i++) {
        for (int l = 0; l < a[i].size(); l++) wcout << setw(5) << a[i][l] << " ";
        wcout << "\n";
    }
    wcout << "\nMatrix B:" << endl;
    for (int i = 0; i < b.size(); i++) {
        for (int l = 0; l < b[i].size(); l++) wcout << setw(5) << b[i][l] << " ";
        wcout << "\n";
    }
    wcout << "\nMatrix C:" << endl;
    for (int i = 0; i < c.size(); i++) {
        for (int l = 0; l < c[i].size(); l++) wcout << setw(5) << c[i][l] << " ";
        wcout << "\n";
    }
}

void addColumnAndRow(vector<vector <int>>& m_) {
    wcout << "Matrix:" << endl;
    for (int i = 0; i < m_.size(); i++) {
        for (int l = 0; l < m_[i].size(); l++) wcout << setw(5) << m_[i][l] << " ";
        wcout << "\n";
    }
    wcout << "Starting adding." << endl;
    int num_;
    vector <int> matrix;
    for (int l = 0; l < m_.size() + 1; l++) {
        wcout << "element [" << m_.size() + 1 << "][" << l + 1 << "]: ";
        wcin >> num_;
        matrix.push_back(num_);
    }
    m_.push_back(matrix);
    matrix.clear();
    for (int l = 0; l < m_.size() - 1; l++) {
        wcout << "element [" << l + 1 << "][" << m_[l].size() + 1 << "]: ";
        wcin >> num_;
        m_[l].push_back(num_);
    }
    wcout << "Adding is over." << endl;
    wcout << endl << "Matrix:" << endl;
    for (int i = 0; i < m_.size(); i++) {
        for (int l = 0; l < m_[i].size(); l++) wcout << setw(5) << m_[i][l] << " ";
        wcout << "\n";
    }
}

void deleteColumnAndRow(vector<vector <int>>& m_) {
    wcout << "Matrix:" << endl;
    for (int i = 0; i < m_.size(); i++) {
        for (int l = 0; l < m_[i].size(); l++) wcout << setw(5) << m_[i][l] << " ";
        wcout << endl;
    }
    wcout << "Starting deleting." << endl;
    auto iter = m_.cbegin();
    m_.erase(iter + m_.size() - 1);
    for (int l = 0; l < m_.size(); l++) {
        auto iter = m_[l].cbegin();
        m_[l].erase(iter + m_.size());
    }
    wcout << "Deleting is over." << endl;
    wcout << endl << "Matrix:" << endl;
    for (int i = 0; i < m_.size(); i++) {
        for (int l = 0; l < m_[i].size(); l++) wcout << setw(5) << m_[i][l] << " ";
        wcout << endl;
    }
}

void editingMatrix(vector<vector <int>>& m) {
    int i, j, num;
    bool flag = true;
    int choice;
    while (true) {
        system("cls");
        wcout << "Matrix:" << endl;
        for (int i = 0; i < m.size(); i++) {
            for (int l = 0; l < m[i].size(); l++) wcout << setw(5) << m[i][l] << " ";
            wcout << endl;
        }
        wcout <<
            "Choose action:\n"
            "0. Exit\n"
            "1. Editing element (under the number i,j)\n"
            "2. Editing row (under the number i)\n"
            "3. Editing column (under the number j)\n"
            "4. Add column and row to the end\n"
            "5. Delete column and row in the end\n";
        wcout << "\nType a number to continue: ";
        wcin >> choice;
        system("cls");
        switch (choice) {
        case 0:
            flag = false;
            break;
        case 1:
            wcout <<
                "Starting editing.\n"
                "Enter indexes i(row) j(column): ";
            while (true) {
                wcin >> i >> j;
                i--;
                j--;
                if (0 <= i < m.size() && 0 <= j < m[0].size()) break;
                wcout <<
                    "Indexes incorrect.\n"
                    "Enter new indexes i(row) j(column): ";
            }
            wcout << "Enter num you want to replace: ";
            wcin >> num;
            m[i][j] = num;
            wcout << "Editing is over." << endl;
            break;
        case 2:
            wcout <<
                "Starting editing.\n"
                "Enter index i(row): ";
            while (true) {
                wcin >> i;
                i--;
                if (0 <= i < m.size()) break;
                wcout <<
                    "Index incorrect.\n"
                    "Enter new index i(row): ";
            }
            wcout << "Enter nums:" << endl;
            for (int l = 0; l < m.size(); l++) {
                wcout << "element [" << i + 1 << "][" << l + 1 << "]: ";
                wcin >> m[i][l];
            }
            wcout << "Editing is over." << endl;
            break;
        case 3:
            wcout <<
                "Starting editing.\n"
                "Enter index j(column): ";
            while (true) {
                wcin >> j;
                j--;
                if (0 <= j < m[0].size()) break;
                wcout <<
                    "Index incorrect.\n"
                    "Enter new index j(column): ";
            }
            wcout << "Enter nums:" << endl;
            for (int l = 0; l < m.size(); l++) {
                wcout << "element [" << l + 1 << "][" << j + 1 << "]: ";
                wcin >> m[l][j];
            }
            wcout << "Editing is over." << endl;
            break;
        case 4:
            addColumnAndRow(m);
            break;
        case 5:
            deleteColumnAndRow(m);
            break;
        default:
            wcout << "\nAction with number " << choice << " does not exist." << endl;
        }
        if (!flag) break;
        system("pause");
    }
}

int editing(vector<vector <int>>& a, vector<vector <int>>& b, vector<vector <int>>& c) {
    int choice;
    checkingEmptiness(a, b, c);
    while (true) {
        system("cls");
        wcout <<
            "Choose action:\n"
            "0. Exit\n"
            "1. Editing matrix A\n"
            "2. Editing matrix B\n"
            "3. Editing matrix C\n";
        wcout << "\nType a number to continue: ";
        wcin >> choice;
        system("cls");
        switch (choice) {
        case 0:
            return 0;
        case 1:
            editingMatrix(a);
            break;
        case 2:
            editingMatrix(b);
            break;
        case 3:
            editingMatrix(c);
            break;
        default:
            wcout << "\nAction with number " << choice << " does not exist." << endl;
        }
        system("pause");
    }
}

void task15(vector<vector <int>>& a, vector<vector <int>>& b, vector<vector <int>>& c) {
    checkingEmptiness(a, b, c);
    wcout << "Start task 15 execution." << endl;
    vector <int> max_nums(a.size() + b.size());
    int max_num;
    for (int i = 0; i < a.size(); i++) {
        max_num = INT_MIN;
        for (int l = 0; l < a[i].size(); l++)
            if (a[l][i] > max_num) max_num = a[l][i];
        max_nums[i] = max_num;
    }
    for (int i = 0; i < b.size(); i++) {
        max_num = INT_MIN;
        for (int l = 0; l < b[i].size(); l++)
            if (b[i][l] > max_num) max_num = b[i][l];
        max_nums[i + a.size()] = max_num;
    }
    for (int i = 0; i < c.size(); i++)
        for (int j = 0; j < c[i].size(); j++)
            for (int l = 0; l < max_nums.size(); l++)
                if (c[i][j] == max_nums[l]) c[i][j] = 0;
    wcout << "Task 15 is over." << endl;
}

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    vector <vector <int>> A, B, C;
    while (true) {
        system("cls");
        wcout <<
            "Choose action:\n"
            "0. Exit\n"
            "1. Input from file\n"
            "2. Output in file\n"
            "3. Input from console\n"
            "4. Output in console\n"
            "5. Editing element in matrix\n"
            "6. Performe task 15\n";
        wcout << "\nType a number to continue: ";
        int choice;
        wcin >> choice;
        system("cls");
        switch (choice) {
        case 0:
            return 0;
        case 1:
            wcout <<
                "File filling format:\n"
                "1. The name of the matrix;\n"
                "2. matrix size;\n"
                "3. the matrix;\n"
                "4. etc..\n"
                "If you want to interrupt the filling process in the file, write zero.\n"
                "If any other character is encountered, the reading process will be interrupted.\n";
            fileInput(A, B, C);
            break;
        case 2:
            fileOutput(A, B, C);
            break;
        case 3:
            consoleInput(A, B, C);
            break;
        case 4:
            consoleOutput(A, B, C);
            break;
        case 5:
            editing(A, B, C);
            break;
        case 6:
            task15(A, B, C);
            break;
        default:
            wcout << "\nAction with number " << choice << " does not exist." << endl;
        }
        system("pause");
    }
}
