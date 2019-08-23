#!/usr/bin/python
from __future__ import print_function
import json

groups = {}

with open('Function-Index.html', 'r') as f:
    for line in f.readlines():
        line = line.strip()

        if line.startswith('<tr><td></td><td valign="top"><a href='):

            func_name = line.split('<code>')[1].split('</code>')[0]
            desc = line.split('</a></td></tr>')[0].split('>')[-1]

            #print(func_name, desc)

            if desc not in groups:
                groups[desc] = []
                print(desc)

            if func_name not in groups[desc]:
                groups[desc].append(func_name)

r = json.dumps(groups, indent=4)

with open('libcall.groups', 'w') as f:
    f.write(r)
