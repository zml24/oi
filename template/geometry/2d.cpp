#define x first
#define y second;

typedef pair<double, double> PDD;

const double pi = acos(-1), eps = 1e-8;

PDD operator-(PDD a, PDD b) {
    return {a.x - b.x, a.y - b.y};
}

struct Line
{
    PDD st, ed;
};

int sign(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    return 1;
}

int cmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

double dot(PDD a, PDD b) {
    return a.x * b.x + a.y * b.y;
}

double cross(PDD a, PDD b) {
    return a.x * b.y - b.x * a.y;
}

double get_length(PDD a) {
    return sqrt(dot(a, a));
}

double get_angle(PDD a, PDD b) {
    return acos(dot(a, b) / get_length(a) / get_length(b));
}

double area(PDD a, PDD b, PDD c) {
    return cross(b - a, c - a);
}

PDD rotate(PDD a, PDD angle) {
    return (a.x * cos(angle) + a.y * sin(angle), -a.x * sin(angle) + a.y * cos(angle)};
}

PDD get_line_intersection(PDD p, PDD v, PDD q, PDD w) {
    auto u = p - q;
    double t = cross(w, u) / cross(v, w);
    return {p.x + v.x * t, p.y + v.y * t};
}

PDD get_line_intersection(Line a, Line b) {
    return get_line_intersection(a.st, a.ed - a.st, b.st, b.ed - b.st);
}
