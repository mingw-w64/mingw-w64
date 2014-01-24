#!/usr/bin/python

import os
from glob import glob
from collections import defaultdict


#
# gcov *.c is buggy, so getting a nice coverage report for .h files
# requires more steps:
#
#  (1) for file in *.c; do gcov -l $file; done
#
#  (2) generate a cumulative coverage for each .h file
#
# Tested with gcc/gcov 4.4.3.
#

NOCOV_EXPECTED = ['constants.c', 'bench.c']


def update_count(line, results):
    first, rest = line.split(':', 1)
    first = first.lstrip()
    try:
        results['count'] += int(first)
    except ValueError:
        results[first] += 1
    return first, rest


d = defaultdict(list)
for filename in glob("*##*.h.gcov"):
    k = filename.split('##')[1]
    d[k].append(filename)

for outfile, lst in d.items():
    files = [open(x) for x in lst]
    out = open(outfile, "w")
    for line in files[0]:
        results = {'-': 0, '#####': 0, 'count': 0}
        first, rest = update_count(line, results)
        for f in files[1:]:
            fst, rst = update_count(f.readline(), results)
            if rst != rest and not 'gcda' in rest and not 'gcno' in rest \
               and not ':Runs:' in rest and not ':Programs:' in rest:
                print(line.rstrip(), rst.rstrip(), rest.rstrip())
        if results['count'] > 0:
            first = results['count']
        elif results['#####'] > 0:
            first = '#####'
        else:
            first = '-'
        first = format(str(first), ">10.10")
        out.write(':'.join((first, rest)))
    out.close()
    for f in files:
        f.close()


def update_total(line, results):
    first, rest = line.split(':', 1)
    first = first.lstrip()
    try:
        int(first)
        results['count'] += 1
    except ValueError:
        if 'GCOV_NOT_REACHED' in rest:
            results['not_reached'] += 1
        elif 'GCOV_UNLIKELY' in rest:
            results['unlikely'] += 1
        else:
            #if '####' in first:
            #    print(first, rest)
            results[first] += 1
    return first, rest

print("\n%19s%19s%19s%19s\n" %
      ("file name:", "lines:", "not executed:", "unaccounted for:"))

for filename in glob("*.h.gcov"):
    if '##' in filename: continue
    with open(filename) as f:
        results = {'-': 0, '#####': 0, 'not_reached': 0, 'unlikely': 0,
                   'count': 0}
        for line in f:
            update_total(line, results)
    print("%19s%19d%19d%19d" % (filename.split('.gcov')[0], results['count'],
                                results['not_reached']+results['unlikely']+
                                results['#####'], results['#####']))

print("")

for filename in glob("*.c.gcov"):
    if '##' in filename: continue
    with open(filename) as f:
        results = {'-': 0, '#####': 0, 'not_reached': 0, 'unlikely': 0, 'count': 0}
        for line in f:
            update_total(line, results)
    print("%19s%19d%19d%19d" % (filename.split('.gcov')[0], results['count'],
                                results['not_reached']+results['unlikely']+
                                results['#####'], results['#####']))

print("\n\n%19s\n" % "no coverage:")

for filename in glob("*.h"):
    s = filename + '.gcov'
    if not os.path.isfile(s):
        with open(filename) as f:
            for line in f:
                if 'static inline' in line:
                    print("%19s" % filename)
                    break

for filename in glob("*.c"):
    s = filename + '.gcov'
    if not os.path.isfile(s) and not filename in NOCOV_EXPECTED:
        print("%19s" % filename)

print("")
