
#include <iostream>
#include <string>
#include <limits>
using namespace std;

string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20];
int total = 0;

int findStudent(string rollno)
{
    for (int i = 0; i < total; i++)
    {
        if (arr2[i] == rollno)
        {
            return i;
        }
    }
    return -1;
}

void enter()
{
    int ch;

    cout << "How many students do you want to enter?" << endl;
    cin >> ch;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input!" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (ch <= 0 || ch > 20 - total)
    {
        cout << "Invalid number! Available space: " << 20 - total << endl;
        return;
    }

    for (int i = total; i < total + ch; i++)
    {
        cout << "\nEnter the Data of Student " << i + 1 << endl;

        cout << "Enter name: ";
        getline(cin, arr1[i]);

        cout << "Enter Roll no: ";
        getline(cin, arr2[i]);

        if (findStudent(arr2[i]) != -1)
        {
            cout << "Roll number already exists! Enter another roll no: ";
            getline(cin, arr2[i]);
            while (findStudent(arr2[i]) != -1)
            {
                cout << "Roll number already exists! Enter another roll no: ";
                getline(cin, arr2[i]);
            }
        }

        cout << "Enter course: ";
        getline(cin, arr3[i]);

        cout << "Enter class: ";
        getline(cin, arr4[i]);

        cout << "Enter contact: ";
        getline(cin, arr5[i]);
    }

    total += ch;
    cout << "\nStudent records added successfully!" << endl;
}

void show()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
    }
    else
    {
        for (int i = 0; i < total; i++)
        {
            cout << "\nData of Student " << i + 1 << endl;
            cout << "Name: " << arr1[i] << endl;
            cout << "Roll no: " << arr2[i] << endl;
            cout << "Course: " << arr3[i] << endl;
            cout << "Class: " << arr4[i] << endl;
            cout << "Contact: " << arr5[i] << endl;
        }
    }
}

void search()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
        return;
    }

    string rollno;

    cout << "Enter the roll no of student: ";
    getline(cin, rollno);

    int index = findStudent(rollno);

    if (index == -1)
    {
        cout << "Student not found!" << endl;
    }
    else
    {
        cout << "\nName: " << arr1[index] << endl;
        cout << "Roll no: " << arr2[index] << endl;
        cout << "Course: " << arr3[index] << endl;
        cout << "Class: " << arr4[index] << endl;
        cout << "Contact: " << arr5[index] << endl;
    }
}

void update()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
        return;
    }

    string rollno;

    cout << "Enter the roll no of student which you want to update: ";
    getline(cin, rollno);

    int index = findStudent(rollno);

    if (index == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }

    cout << "\nPrevious data" << endl;
    cout << "Name: " << arr1[index] << endl;
    cout << "Roll no: " << arr2[index] << endl;
    cout << "Course: " << arr3[index] << endl;
    cout << "Class: " << arr4[index] << endl;
    cout << "Contact: " << arr5[index] << endl;

    cout << "\nEnter new data" << endl;

    cout << "Enter name: ";
    getline(cin, arr1[index]);

    cout << "Enter Roll no: ";
    string newRoll;
    getline(cin, newRoll);

    while (findStudent(newRoll) != -1 && newRoll != rollno)
    {
        cout << "Roll number already exists! Enter another roll no: ";
        getline(cin, newRoll);
    }

    arr2[index] = newRoll;

    cout << "Enter course: ";
    getline(cin, arr3[index]);

    cout << "Enter class: ";
    getline(cin, arr4[index]);

    cout << "Enter contact: ";
    getline(cin, arr5[index]);

    cout << "Record updated successfully!" << endl;
}

void deleterecord()
{
    if (total == 0)
    {
        cout << "No data is entered" << endl;
        return;
    }

    int a;

    cout << "Press 1 to delete all records" << endl;
    cout << "Press 2 to delete specific record" << endl;
    cin >> a;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (a == 1)
    {
        total = 0;
        cout << "All records are deleted!" << endl;
    }
    else if (a == 2)
    {
        string rollno;

        cout << "Enter the roll no of student you want to delete: ";
        getline(cin, rollno);

        int index = findStudent(rollno);

        if (index == -1)
        {
            cout << "Student not found!" << endl;
            return;
        }

        for (int j = index; j < total - 1; j++)
        {
            arr1[j] = arr1[j + 1];
            arr2[j] = arr2[j + 1];
            arr3[j] = arr3[j + 1];
            arr4[j] = arr4[j + 1];
            arr5[j] = arr5[j + 1];
        }

        total--;

        cout << "Your required record is deleted!" << endl;
    }
    else
    {
        cout << "Invalid input!" << endl;
    }
}

int main()
{
    int value;

    while (true)
    {
        cout << "\nPress 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to exit" << endl;

        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!" << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (value)
        {
            case 1:
                enter();
                break;

            case 2:
                show();
                break;

            case 3:
                search();
                break;

            case 4:
                update();
                break;

            case 5:
                deleterecord();
                break;

            case 6:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}
