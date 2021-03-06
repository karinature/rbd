#!/usr/bin/env python3

import random


def quickselect(items, item_index, coor=1):
    def select(lst, l, r, index, coor=1):
        # base case
        if r == l:
            return lst[l]
        pivot_index = random.randint(l, r)  # choose random pivot
        lst[l], lst[pivot_index] = lst[pivot_index], lst[l]  # move pivot to beginning of list
        # partition
        i = l
        for j in range(l + 1, r + 1):
            if lst[j][coor] < lst[l][coor]:  # compare by the 2nd [y] coordinate
                i += 1
                lst[i], lst[j] = lst[j], lst[i]
        lst[i], lst[l] = lst[l], lst[i]  # move pivot to correct location
        # recursively partition one side only
        if index == i:
            return lst[i]
        elif index < i:
            return select(lst, l, i - 1, index)
        else:
            return select(lst, i + 1, r, index)

    if items is None or len(items) < 1:
        return None
    if item_index < 0 or item_index > len(items) - 1:
        raise IndexError()
    return select(items, 0, len(items) - 1, item_index)


def median(items):
    return [quickselect(items, ((len(items)) // 2), 1)]


if __name__ == "__main__":
    print('Quick Select (main)')
    a = [random.randint(0, 25) for i in range(10)]
    # for i in range(0, len(a)):
    print(a)  # , i)
    for i in range(0, len(a)):
        print(i, ": ", quickselect(a, i))



# def func():
#     if something:
#         # do something
#         if another_thing:
#             # do
#         else:
#             # do else
#     else:
#         # do else