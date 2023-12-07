#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void write_all_lines(string input, string output) {
    ifstream fin(input);
    if (fin.is_open()) {
        ofstream fout(output);
        if (fout.is_open()) {
            int a, b, c;
            while (fin >> a >> b >> c) {
                ifstream fin2(input);
                int a2, b2, c2;
                while (fin2 >> a2 >> b2 >> c2) {
                    if (a == a2 && b == b2 && c == c2) {
                        continue; // Пропускаємо порівняння лінії з собою
                    }

                    if (a *b == b2 * a2) {
                        fout << a << " " << b << " " << c << " " << a2 << " " << b2 << " " << c2 << " parallel" << endl;
                    }
                    else if (a * a2 + b* b2 == 0) {
                        fout << a << " " << b << " " << c << " " << a2 << " " << b2 << " " << c2 << " perpend" << endl;
                    }
                    else {
                        fout << a << " " << b << " " << c << " " << a2 << " " << b2 << " " << c2 << " intersect" << endl;
                    }
                }
                fin2.close();
            }
            fout.close();
        }
        else {
            cout << "Error during opening output file" << endl;
        }
        fin.close();
    }
    else {
        cout << "Error during opening input file" << endl;
    }
}

int main() {
    string input;
    string output;
    cout << "Enter input filename: ";
    cin >> input;
    cout << "Enter output filename: ";
    cin >> output;

    write_all_lines(input, output);

    return 0;
}
//1 1 1
//2 2 2
//- 1 1 0
