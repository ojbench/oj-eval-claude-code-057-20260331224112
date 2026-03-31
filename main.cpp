#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Student {
    string id;        // 学号
    string name;      // 姓名
    int score;        // 成绩
    int order;        // 添加顺序，用于成绩相同时按添加顺序排序
};

class StudentManager {
private:
    vector<Student> students;      // 存储学生信息（按添加顺序）
    map<string, int> idIndex;      // 学号到students数组索引的映射
    map<string, int> nameIndex;    // 姓名到students数组索引的映射
    int orderCounter;              // 记录添加顺序

public:
    StudentManager() : orderCounter(0) {}

    // 1-添加学生信息
    void addStudent(const string& id, const string& name, int score) {
        // 检查学号是否已存在
        if (idIndex.find(id) != idIndex.end()) {
            cout << "FAILED" << endl;
            return;
        }

        Student student;
        student.id = id;
        student.name = name;
        student.score = score;
        student.order = orderCounter++;

        students.push_back(student);
        int index = students.size() - 1;
        idIndex[id] = index;
        nameIndex[name] = index;

        cout << "SUCCESS" << endl;
    }

    // 2-显示全部学生信息
    void displayAll() {
        for (const auto& student : students) {
            cout << student.id << " " << student.name << " " << student.score << endl;
        }
    }

    // 3-按学号查询学生信息
    void queryById(const string& id) {
        int index = idIndex[id];
        const Student& student = students[index];
        cout << student.id << " " << student.name << " " << student.score << endl;
    }

    // 4-按姓名查询学生信息
    void queryByName(const string& name) {
        int index = nameIndex[name];
        const Student& student = students[index];
        cout << student.id << " " << student.name << " " << student.score << endl;
    }

    // 5-按学号升序排序
    void sortById() {
        vector<Student> sorted = students;
        sort(sorted.begin(), sorted.end(), [](const Student& a, const Student& b) {
            return a.id < b.id;
        });

        for (const auto& student : sorted) {
            cout << student.id << " " << student.name << " " << student.score << endl;
        }
    }

    // 6-按成绩降序排序（成绩相同时按添加顺序）
    void sortByScore() {
        vector<Student> sorted = students;
        sort(sorted.begin(), sorted.end(), [](const Student& a, const Student& b) {
            if (a.score != b.score) {
                return a.score > b.score;  // 成绩降序
            }
            return a.order < b.order;  // 成绩相同时按添加顺序
        });

        for (const auto& student : sorted) {
            cout << student.id << " " << student.name << " " << student.score << endl;
        }
    }
};

int main() {
    StudentManager manager;
    int command;

    while (cin >> command) {
        if (command == 1) {
            // 添加学生信息
            string id, name;
            int score;
            cin >> id >> name >> score;
            manager.addStudent(id, name, score);
        } else if (command == 2) {
            // 显示全部学生信息
            manager.displayAll();
        } else if (command == 3) {
            // 按学号查询
            string id;
            cin >> id;
            manager.queryById(id);
        } else if (command == 4) {
            // 按姓名查询
            string name;
            cin >> name;
            manager.queryByName(name);
        } else if (command == 5) {
            // 按学号升序排序
            manager.sortById();
        } else if (command == 6) {
            // 按成绩降序排序
            manager.sortByScore();
        } else if (command == 7) {
            // 退出
            cout << "END" << endl;
            break;
        }
    }

    return 0;
}
