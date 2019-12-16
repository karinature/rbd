#!/usr/bin/env python3
from random import *
from auxClasses import *
dim = 3  # #dimansions
size = 100
file = "/home/rbd/PycharmProjects/dan/points"


def rand(bottom_lim=0, range_lim=10, round_lim=2):
    return round(range_lim * random() + bottom_lim, round_lim)


def generate_points(n=size, d=dim):
    points = [tuple(rand() for i in range(d)) for i in range(n)]
    points.sort()
    return points


def create_points_file(points):
    with open(file, 'w') as f:
        # f.write('%d\n' % len(points)  # for c++ compatibility
        for point in points:
            f.write(f' '.join(map(str, point)))
            f.write('\n')


def get_points_from_file():
    with open(file) as f:
        # n = f.readline()  # for c++ compatibility
        points = [tuple(map(float, i.split(' '))) for i in f]
    return points


def get_points(n=size, d=dim):
    create_points_file(generate_points(n, d))
    return get_points_from_file()


def gen_encrypted_points_from_file():
    with open(file) as f:
        points = [Point(*map(Binary, map(float, i.split(' ')))) for i in f]  # todo encapsulate in Binary
        print(points)
    return points


# def gen_encrypted_points():


if __name__ == '__main__':
    # create_points_file()
    # generate_points()
    # print('get_points')
    # print(get_points())
    print('gen_encrypted_points_from_file')
    print(gen_encrypted_points_from_file())
