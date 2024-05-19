#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <windows.h>

struct Vec3 {
    float x, y, z;
};

Vec3 minus(const Vec3& a, const Vec3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 crossProd(const Vec3& a, const Vec3& b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

Vec3 norm(const Vec3& v) {
    float len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return {v.x / len, v.y / len, v.z / len};
}

Vec3 rotateY(Vec3 pt, float ang) {
    float s = sin(ang);
    float c = cos(ang);
    return {pt.x * c - pt.z * s, pt.y, pt.x * s + pt.z * c};
}

Vec3 project(Vec3 pt) {
    return {pt.x, pt.y, 0};
}

struct Face {
    std::vector<int> vertIdx;
};

std::vector<Vec3> verts;
std::vector<Face> faces;

void loadObj(const std::string& fileNm) {
    std::ifstream file(fileNm);
    if (!file) {
        std::cerr << "Error opening file: " << fileNm << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        iss >> type;
        if (type == 'v') {
            Vec3 vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            verts.push_back(vertex);
        } else if (type == 'f') {
            Face face;
            int index;
            while (iss >> index) {
                face.vertIdx.push_back(index - 1);
            }
            faces.push_back(face);
        }
    }
}

int main() {
    loadObj("yourModel.obj");
    const int width = 80, height = 30;
    float angle = 0.0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD charsWritten;
    COORD coordScreen = { 0, 0 };
    DWORD conSize = width * height;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, & csbi);
    conSize = csbi.dwSize.X * csbi.dwSize.Y;

    while (true) {
        if (GetKeyState(VK_LEFT) & 0x8000) angle -= 0.05;
        if (GetKeyState(VK_RIGHT) & 0x8000) angle += 0.05;

        FillConsoleOutputCharacter(hConsole, ' ', conSize, coordScreen, &charsWritten);
        SetConsoleCursorPosition(hConsole, coordScreen);

        for (const auto& face : faces) {
            for (int i = 0; i < face.vertIdx.size(); ++i) {
                Vec3 v1 = verts[face.vertIdx[i]];
                Vec3 v2 = verts[face.vertIdx[(i + 1) % face.vertIdx.size()]];

                Vec3 rotatedV1 = rotateY(v1, angle);
                Vec3 rotatedV2 = rotateY(v2, angle);
                Vec3 projectedV1 = project(rotatedV1);
                Vec3 projectedV2 = project(rotatedV2);
                Vec3 consoleV1 = {(projectedV1.x + 1) * width / 2, (1 - projectedV1.y) * height / 2, projectedV1.z};
                Vec3 consoleV2 = {(projectedV2.x + 1) * width / 2, (1 - projectedV2.y) * height / 2, projectedV2.z};

                COORD start = {(SHORT)consoleV1.x, (SHORT)consoleV1.y};
                COORD end = {(SHORT)consoleV2.x, (SHORT)consoleV2.y};

                SetConsoleCursorPosition(hConsole, start);
                std::cout << '*';
                SetConsoleCursorPosition(hConsole, end);
                std::cout << '*';
            }
        }
        std::cout << std::flush;
        Sleep(50);
    }
    return 0;
}