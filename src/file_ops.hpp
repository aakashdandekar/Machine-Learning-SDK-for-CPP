#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

#include "datatypes.hpp"

DataType parseValue(const string& token) {
    if (token.empty()) return token;

    try {
        size_t pos;
        int i = stoi(token, &pos);
        if (pos == token.size()) return i;
    } catch (...) {}

    try {
        size_t pos;
        long l = stol(token, &pos);
        if (pos == token.size()) return l;
    } catch (...) {}

    try {
        size_t pos;
        double d = stod(token, &pos);
        if (pos == token.size()) return d;
    } catch (...) {}

    return token;
}

vector<string> splitLine(const string& line, char delim = ',') {
    vector<string> fields;
    string field;
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (inQuotes) {
            if (c == '"') {
                if (i + 1 < line.size() && line[i + 1] == '"') {
                    field += '"';
                    ++i;
                } else {
                    inQuotes = false;
                }
            } else {
                field += c;
            }
        } else {
            if (c == '"') {
                inQuotes = true;
            } else if (c == delim) {
                fields.push_back(field);
                field.clear();
            } else {
                field += c;
            }
        }
    }
    fields.push_back(field);
    return fields;
}

vector<vector<DataType>> readCsv(const string& filepath, bool hasHeader = false, char delim = ',') {
    ifstream file(filepath);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: " + filepath);
    }

    vector<vector<DataType>> data;
    string line;
    bool firstLine = true;

    while (getline(file, line)) {
        if (line.empty()) continue;
        if (firstLine && hasHeader) {
            firstLine = false;
            continue;
        }
        firstLine = false;

        vector<string> tokens = splitLine(line, delim);
        vector<DataType> row;
        row.reserve(tokens.size());
        for (auto& tok : tokens) {
            row.push_back(parseValue(tok));
        }
        data.push_back(move(row));
    }

    return data;
}

class File {
    private:
        vector<vector<DataType>> dataset;

    public:
        File(string filepath) {
            this->dataset = readCsv(filepath, true);
        }

        vector<vector<DataType>> getData() {
            return this->dataset;
        }
};