#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cctype>
using namespace std;
bool adminLogin();
bool isValidName(const char*);
void inputData(int*, char[][30], float*, float*, float*, float*, int);
void calculateSalary(float*, float*, float*, float*, float*, int);
void displayTable(int*, char[][30], float*, float*, float*, float*, float*, int);
void saveToFile(int*, char[][30], float*, float*, float*, float*, float*, int);
void readFromFile();
bool adminLogin() {
 string username, password;
 cout << "================ ADMIN LOGIN ================\n";
 cout << "Username: ";
 cin >> username;
 cout << "Password: ";
 cin >> password;
 if ((username == "Sumiyyah" || username == "Neham") && password == "1234") {
 cout << "\nLogin Successful! Welcome " << username << "\n\n";
 return true;
 } else {
 cout << "\nInvalid Login! Access Denied\n";
 return false;
 }
}
bool isValidName(const char* name) {
 for (int i = 0; name[i] != '\0'; i++) {
 if (!isalpha(name[i]) && name[i] != ' ')
 return false;
 }
 return true;
}
int main() {
 if (!adminLogin())
 return 0;
 int n;
 cout << "Enter number of employees: ";
 cin >> n;
 int empID[n];
 char name[n][30];
 float basic[n], hra[n], da[n], tax[n], total[n];
 int choice;
 bool dataEntered = false;
 do {
 cout << "\n=========== ADMIN DASHBOARD ===========\n";
 cout << "1. Enter Employee Data\n";
 cout << "2. Display Salary Table\n";
 cout << "3. Save Data to File\n";
 cout << "4. Read Data From File\n";
 cout << "5. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 inputData(empID, name, basic, hra, da, tax, n);
 calculateSalary(basic, hra, da, tax, total, n);
 dataEntered = true;
 break;
 case 2:
 if (dataEntered)
 displayTable(empID, name, basic, hra, da, tax, total, n);
 else
 cout << " Please enter data first!\n";
 break;
 case 3:
 if (dataEntered)
 saveToFile(empID, name, basic, hra, da, tax, total, n);
 else
 cout << " No data to save!\n";
 break;
 case 4:
 readFromFile();
 break;
 case 5:
 cout << "Exiting Admin Dashboard...\n";
 break;
 default:
 cout << "Invalid choice! Try again.\n";
 }
 } while (choice != 5);
 return 0;
}
void inputData(int* id, char name[][30], float* basic, float* hra,
 float* da, float* tax, int n) {
 for (int i = 0; i < n; i++) {
 cout << "\n--- Employee " << i + 1 << " ---\n";
 while (true) {
 cout << "Employee ID: ";
 cin >> id[i];
 if (cin.fail() || id[i] <= 0) {
 cout << "Invalid input! Enter a positive integer for ID.\n";
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 } else break;
 }
 cin.ignore();
 while (true) {
 cout << "Employee Name: ";
 cin.getline(name[i], 30);
 if (isValidName(name[i])) break;
 else cout << "Only alphabets & spaces allowed!\n";
 }
 while (true) {
 cout << "Basic Salary: ";
 cin >> basic[i];
 if (cin.fail() || basic[i] < 0) {
 cout << "Invalid input! Enter a non-negative number.\n";
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 } else break;
 }
 while (true) {
 cout << "HRA: ";
 cin >> hra[i];
 if (cin.fail() || hra[i] < 0) {
 cout << "Invalid input! Enter a non-negative number.\n";
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 } else break;
 }
 while (true) {
 cout << "DA: ";
 cin >> da[i];
 if (cin.fail() || da[i] < 0) {
 cout << "Invalid input! Enter a non-negative number.\n";
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 } else break;
 }
 while (true) {
 cout << "Tax: ";
 cin >> tax[i];
 if (cin.fail() || tax[i] < 0) {
 cout << "Invalid input! Enter a non-negative number.\n";
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 } else break;
 }
 }
}
void calculateSalary(float* basic, float* hra, float* da,
 float* tax, float* total, int n) {
 for (int i = 0; i < n; i++)
 total[i] = basic[i] + hra[i] + da[i] - tax[i];
}
void displayTable(int* id, char name[][30], float* basic, float* hra,
 float* da, float* tax, float* total, int n) {
 cout << fixed << setprecision(2);
 cout << "\nID Name Basic HRA DA Tax Total\n";
 cout << "------------------------------------------------------------\n";
 for (int i = 0; i < n; i++) {
 cout << left << setw(6) << id[i]
 << setw(20) << name[i]
 << setw(10) << basic[i]
 << setw(10) << hra[i]
 << setw(10) << da[i]
 << setw(10) << tax[i]
 << setw(10) << total[i] << endl;
 }
}
void saveToFile(int* id, char name[][30], float* basic, float* hra,
 float* da, float* tax, float* total, int n) {
 ofstream file("salary.txt");
 file << fixed << setprecision(2);
 file << "ID Name Basic HRA DA Tax Total\n";
 file << "------------------------------------------------------------\n";
 for (int i = 0; i < n; i++) {
 file << left << setw(6) << id[i]
 << setw(20) << name[i]
 << setw(10) << basic[i]
 << setw(10) << hra[i]
 << setw(10) << da[i]
 << setw(10) << tax[i]
 << setw(10) << total[i] << endl;
 }
 file.close();
 cout << "Data saved successfully!\n";
}
void readFromFile() {
 ifstream file("salary.txt");
 string line;
 cout << "\n========= DATA FROM FILE =========\n";
 while (getline(file, line)) {
 cout << line << endl;
 }
 file.close();
}
