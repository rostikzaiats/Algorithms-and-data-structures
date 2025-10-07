
#include <iostream>


using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            ++length;
        }
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = s[i];
        }
    }

    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = s.str[i];
        }
    }

    ~String() {
        delete[] str;
    }

    int getLength() const {
        return length;
    }

    char& operator[](int index) {
        return str[index];
    }

    String operator+(const String& s) const {
        String result;
        result.length = length + s.length;
        delete[] result.str;
        result.str = new char[result.length + 1];
        for (int i = 0; i < length; ++i) {
            result.str[i] = str[i];
        }
        for (int i = 0; i <= s.length; ++i) {
            result.str[length + i] = s.str[i];
        }
        return result;
    }

    String& operator=(const String& s) {
        if (this == &s)
            return *this;

        delete[] str;
        length = s.length;
        str = new char[length + 1];
        for (int i = 0; i <= length; ++i) {
            str[i] = s.str[i];
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const String& s) {
        out << s.str;
        return out;
    }

    String substr(int start, int count) const {
        if (start < 0 || start >= length || count <= 0) {
            return String();
        }
        int len = std::min(count, length - start);
        char* substr = new char[len + 1];
        for (int i = 0; i < len; ++i) {
            substr[i] = str[start + i];
        }
        substr[len] = '\0';
        return String(substr);
    }

    void replace(int start, int count, const String& replacement) {
        if (start < 0 || start >= length || count < 0) {
            return;
        }
        int new_length = length - count + replacement.length;
        char* new_str = new char[new_length + 1];
        for (int i = 0; i < start; ++i) {
            new_str[i] = str[i];
        }
        for (int i = 0; i < replacement.length; ++i) {
            new_str[start + i] = replacement.str[i];
        }
        for (int i = start + count; i < length; ++i) {
            new_str[i + replacement.length - count] = str[i];
        }
        new_str[new_length] = '\0';
        delete[] str;
        str = new_str;
        length = new_length;
    }

    bool operator==(const String& other) const {
        if (length != other.length)
            return false;
        for (int i = 0; i < length; ++i) {
            if (str[i] != other.str[i])
                return false;
        }
        return true;
    }
};
class MarkovChange {
private:
    String part_to_be_changed;
    String part_to_change;

public:
    MarkovChange(String ptbc = "", String ptc = "") : part_to_be_changed(ptbc), part_to_change(ptc) {}

    String GetDeletePart() {
        return part_to_be_changed;
    }

    String GetChangingPart() {
        return part_to_change;
    }
};

bool MarkovStep(String& main_str, MarkovChange str) {
    bool result = false;
    String deleted_str = str.GetDeletePart();
    int length = deleted_str.getLength();
    int main_length = main_str.getLength();
    for (int i = 0; i <= main_length - length; ++i) {
        if (main_str.substr(i, length) == deleted_str) {
            main_str.replace(i, length, str.GetChangingPart());
            result = true;
            break;
        }
    }
    return result;
}

void MarcovAlgorithm(String& main_str, const MarkovChange production[], int production_size) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < production_size; ++i) {
            if (MarkovStep(main_str, production[i])) {
                changed = true;
                break;
            }
        }
    }
}
//
//int main(int argc, char** argv) {
//
//    String main_str("hello world 000 aabbavbba");
//
//
//    MarkovChange production[] = {
//        {"hello", "hi", },
//        {"world", "universe"},
//        {"000","00567" },
//        { "bb", "hh" }
//    };
//    int production_size = sizeof(production) / sizeof(production[0]);
//
//
//    MarcovAlgorithm(main_str, production, production_size);
//
//
//    cout << "Modified string: " << main_str << endl;
//}
