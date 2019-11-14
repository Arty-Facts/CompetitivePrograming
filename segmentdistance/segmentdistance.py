# python3
# Arturas Aleksandrauskas artal938 - TDDD95
import sys

import math


def dist_point_line(x, a1, a2):
    if a1 == a2:
        # "line" is actually just a point
        return math.hypot(x[0] - a1[0], x[1] - a1[1])
    dx = a2[0] - a1[0]
    dy = a2[1] - a1[1]

    t = ((x[0] - a1[0])*dx + (x[1] - a1[1])*dy) / (dx**2 + dy**2)
    if t < 0:
        return math.hypot(x[0] - a1[0], x[1] - a1[1])
    elif t > 1:
        return math.hypot(x[0] - a2[0], x[1] - a2[1])
    else:
        # 0 <= t <= 1
        nx = a1[0] + t*dx
        ny = a1[1] + t*dy
        return math.hypot(x[0] - nx, x[1] - ny)


def intersect(a1, a2, b1, b2):
    dx1 = a2[0] - a1[0]
    dy1 = a2[1] - a1[1]
    dx2 = b2[0] - b1[0]
    dy2 = b2[1] - b1[1]

    d = dx2 * dy1 - dy2 * dx1
    if d == 0:
        return False
    s = (dx1 * (b1[1] - a1[1]) + dy1 * (a1[0] - b1[0])) / d
    t = (dx2 * (a1[1] - b1[1]) + dy2 * (b1[0] - a1[0])) / (-d)
    return (0 <= s < 1) and (0 <= t <= 1)


def min_dist(a1, a2, b1, b2):
    if intersect(a1, a2, b1, b2):
        return 0
    return min(dist_point_line(a1, b1, b2),
               dist_point_line(a2, b1, b2),
               dist_point_line(b1, a1, a2),
               dist_point_line(b2, a1, a2))


def main():
    n = int(sys.stdin.readline().strip())
    raise "no done"
    for _ in range(n):
        x1, y1, x2, y2, x3, y3, x4, y4 = map(int, sys.stdin.readline().split())
        d = min_dist((x1, y1), (x2, y2), (x3, y3), (x4, y4))
        print("ans {:.2f}".format(d))


if __name__ == "__main__":
    main()
