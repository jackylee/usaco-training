#!/usr/bin/env python
import string
import os
import sys

def gen_code(prob, temp, dict):
    handle = open(prob + ".cpp", "w")
    print >>handle, "/*"
    for k, v in dict.iteritems():
        print >>handle, "%s: %s" % (k, v)
    print >>handle, "PROB:%s" % prob
    print >>handle, "*/"
    code = open(temp, "r")
    orig=""
    for line in code:
        orig = orig + line
    print >>handle, orig % (prob, prob)
    code.close()
    handle.close()

def load_dict(name):
    handle = open(name, "r")
    dict = {}
    for line in handle:
        if len(line[:-1]) == 0:
            continue
        fields = line[:-1].split(":")
        dict[fields[0]] = fields[1]
    handle.close()
    return dict

def gen_make(prob):
    handle = open("usaco_make", "r");
    make=""
    for line in handle:
        make = make + line
    handle.close()
    handle = open("Makefile", "w")
    print >>handle, make % (prob, prob, prob, prob, prob)
    handle.close()

def usage(argv):
    print "%s: problem[problem]" % argv[0]

if len(sys.argv) == 1:
    usage(sys.argv)
    sys.exit(0)
dict = load_dict("usaco.dict")
for prob in sys.argv[1:]:
	gen_code(prob, "usaco.temp", dict)
	gen_make(prob)
	os.system("vim %s.cpp" % prob)
