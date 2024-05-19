//
//  main.cpp
//  code_to_refactor
//
//  Created by tkvitko on 19.05.2024.
//

#include <iostream>
#include <vector>
#include<cmath>

struct Point {
    // структура "точка" с координатами
    // может быть использована в 2d, если z=0
    int x, y, z;
};

enum class Dimension {
    // Измерение, в котором производится изменение размера
    // Либо одно из трёх, либо все три.
    x, y, z, all
};

class BasicShape {
    // фигура, имеющая только прямые стороны (линия, прямоугольник, параллелепипед)
public:
    BasicShape(std::vector<Point> points) : points_(points) {};
    virtual int getSquare();    // получение площади фигуры
    virtual int getVolume();    // получение объема фигуры
    void shift(int delta_x, int delta_y) {
        // сдвиг фигуры
        for (auto& point : points_) {
            point.x += delta_x;
            point.y += delta_y;
        }
    };
    void scale(Dimension dimention, int factor) {
        // изменение размеры фигуры в направлении(ях)
        for (auto& point : points_) {
            if (dimention == Dimension::x || dimention == Dimension::all) {
                point.x *= factor;
            } else if (dimention == Dimension::y || dimention == Dimension::all) {
                point.y *= factor;
            } else if (dimention == Dimension::z || dimention == Dimension::all) {
                point.z *= factor;
            }
        }
    }
protected:
    std::vector<Point> points_;
};

class Line : public BasicShape {
public:
    Line(std::vector<Point> points) : BasicShape(points) {}
    int getSquare() {return 0;};
    int getVolume() {return 0;};
};

class Rectangle : public BasicShape {
public:
    Rectangle(std::vector<Point> points) : BasicShape(points) {
        sideX = abs(points_.at(0).x - points_.at(1).x);
        sideY = abs(points_.at(0).y - points_.at(1).y);
    }
    int getSquare() {
        return sideX * sideY;
    };
    int getVolume() {return 0;};
private:
    int sideX, sideY;
};

class Parallelepiped : public BasicShape {
public:
    Parallelepiped(std::vector<Point> points) : BasicShape(points) {
        sideX = abs(points_.at(0).x - points_.at(1).x);
        sideY = abs(points_.at(0).y - points_.at(1).y);
        sideZ = abs(points_.at(0).z - points_.at(1).z);
    }
    int getSquare() {
        return 2 * sideX * sideY + 2 * sideX * sideZ + 2 * sideY * sideZ;
    };
    int getVolume() {
        return sideX * sideY * sideZ;
    };
    void shift(int delta_x, int delta_y, int delta_z) {
        for (auto& point : points_) {
            point.x += delta_x;
            point.y += delta_y;
            point.z += delta_z;
        }
    };
private:
    int sideX, sideY, sideZ;
};

class RoundShape {
    // фигура с не только прямыми сторонами (круг, цилиндр)
public:
    RoundShape(Point point, int radius) : center_(point), radius_(radius) {};
    RoundShape(Point point, int radius, int height) : center_(point), radius_(radius), height_(height) {};
    virtual int getSquare();    // получение площади фигуры
    virtual int getVolume();    // получение объема фигуры
    void shift(int delta_x, int delta_y) {
        // сдвиг фигуры
        center_.x += delta_x;
        center_.y += delta_y;
    };
protected:
    Point center_;
    int radius_;
    int height_;
};

class Circle : public RoundShape {
public:
    Circle(Point point, int radius) : RoundShape(point, radius) {};
    int getSquare() {
        return radius_ * radius_ * M_PI;
    }
    int getVolume() {return 0;};
};

class Cylinder : public RoundShape {
public:
    Cylinder(Point point, int radius, int height) : RoundShape(point, radius, height) {};
    int getSquare() {
        return M_PI * radius_ * radius_ + 2 * radius_ * height_;
    }
    int getVolume() {
        return radius_ * radius_ * M_PI * height_;
    };
};


int main(int argc, const char * argv[]) {
    return 0;
}
