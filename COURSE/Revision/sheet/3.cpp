#include <iostream>
#include <cstring>
using namespace std;

struct Address
{
    int house_num;
    char *city;
    char *street;
    char *state;
    int pincode;
};

struct Student
{
    char *name;
    char *father_name;
    int enrollment;
    char *specialisation;
    char *minors[10];
    char *majors[10];
    int gate_score;
    char *status_category;
    char *bhawan;         
    int room_num;         
    char *blood_group;
    Address home_address;

    Student() : name(nullptr), father_name(nullptr), enrollment(0), specialisation(nullptr),
                gate_score(0), status_category(nullptr), bhawan(nullptr), room_num(0), blood_group(nullptr)
    {
        for (int i = 0; i < 10; i++)
        {
            minors[i] = nullptr;
            majors[i] = nullptr;
        }
    }

    Student(char *name,
            char *father_name,
            int enrollment,
            char *specialisation,
            char *minors[10],
            char *majors[10],
            int gate_score,
            char *status_category,
            char *bhawan,
            int room_num,
            int house_num,
            char *city,
            char *street,
            char *state,
            int pincode,
            char *blood_group)
    {
        this->name = name;
        this->father_name = father_name;
        this->enrollment = enrollment;
        this->specialisation = specialisation;
        for (int i = 0; i < 10; i++)
        {
            this->minors[i] = minors[i];
            this->majors[i] = majors[i];
        }
        this->gate_score = gate_score;
        this->status_category = status_category;
        this->bhawan = bhawan;
        this->room_num = room_num;
        this->home_address.house_num = house_num;
        this->home_address.city = city;
        this->home_address.street = street;
        this->home_address.state = state;
        this->home_address.pincode = pincode;
        this->blood_group = blood_group;
    }
};

char *input_line()
{
    char temp[100];
    cin.getline(temp, 100);
    char *return_string = new char[strlen(temp) + 1];
    strcpy(return_string, temp);
    return return_string;
}

Student *create_student()
{
    cout << "Input the following form fields...\n";
    cout << "Name: ";
    char *name = input_line();
    cout << "Father's name: ";
    char *fathers_name = input_line();
    cout << "Enrollment: ";
    int enrollment;
    cin >> enrollment;
    cin.ignore();

    cout << "Specialisation: ";
    char *specialisation = input_line();

    char *minors[10] = {nullptr};
    char *majors[10] = {nullptr};
    int num_minors, num_majors;

    cout << "Number of Minors (max 10): ";
    cin >> num_minors;
    cin.ignore();
    for (int i = 0; i < num_minors && i < 10; i++)
    {
        cout << "  Minor " << (i + 1) << ": ";
        minors[i] = input_line();
    }

    cout << "Number of Majors (max 10): ";
    cin >> num_majors;
    cin.ignore();
    for (int i = 0; i < num_majors && i < 10; i++)
    {
        cout << "  Major " << (i + 1) << ": ";
        majors[i] = input_line();
    }

    cout << "Gate Score: ";
    int gate_score;
    cin >> gate_score;
    cin.ignore();

    cout << "Status Category (GEN/OBC/SC/ST): ";
    char *status_category = input_line();

    cout << "Bhawan Allocated: ";
    char *bhawan = input_line();

    cout << "Room Number: ";
    int room_num;
    cin >> room_num;

    cout << "House number: ";
    int house_num;
    cin >> house_num;
    cin.ignore();

    cout << "City: ";
    char *city = input_line();
    cout << "Street: ";
    char *street = input_line();
    cout << "State: ";
    char *state = input_line();
    cout << "Pincode: ";
    int pincode;
    cin >> pincode;
    cin.ignore();

    cout << "Blood group: ";
    char *blood_group = input_line();

    return new Student(name, fathers_name, enrollment, specialisation,
                       minors, majors, gate_score, status_category,
                       bhawan, room_num, house_num, city, street, state,
                       pincode, blood_group);
}

void print_student(const Student &student)
{
    cout << "\n========================================" << endl;
    cout << "Name: " << student.name << endl;
    cout << "Father's Name: " << student.father_name << endl;
    cout << "Enrollment No.: " << student.enrollment << endl;
    cout << "Specialisation: " << student.specialisation << endl;

    cout << "Minors: ";
    bool empty_minor = true;
    for (int i = 0; i < 10 && student.minors[i] != nullptr; i++)
    {
        cout << student.minors[i] << " ";
        empty_minor = false;
    }
    if (empty_minor) cout << "None";
    cout << endl;

    cout << "Majors: ";
    bool empty_major = true;
    for (int i = 0; i < 10 && student.majors[i] != nullptr; i++)
    {
        cout << student.majors[i] << " ";
        empty_major = false;
    }
    if (empty_major) cout << "None";
    cout << endl;

    cout << "Gate Score: " << student.gate_score << endl;
    cout << "Status Category: " << student.status_category << endl;
    cout << "Hostel/Bhawan: " << student.bhawan << " (Room " << student.room_num << ")" << endl;
    cout << "Home Address: House #" << student.home_address.house_num << ", "
         << student.home_address.street << ", " << student.home_address.city << ", "
         << student.home_address.state << " - " << student.home_address.pincode << endl;
    cout << "Blood Group: " << student.blood_group << endl;
    cout << "========================================" << endl;
}

void test()
{
    int t;
    cout << "Enter number of students: ";
    cin >> t;
    cin.ignore();

    Student **students = new Student*[t];

    for (int i = 0; i < t; i++)
    {
        students[i] = create_student();
    }

    for (int i = 0; i < t; i++)
    {
        print_student(*students[i]);
    }

    for (int i = 0; i < t; i++)
    {
        delete students[i];
    }
    delete[] students;
}

int main()
{
    test();
    return 0;
}